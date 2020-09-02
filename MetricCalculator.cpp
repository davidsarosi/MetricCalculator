//
// Created by sarosi on 25/08/2020.
//

#include "MetricCalculator.h"
#include <boost/algorithm/string.hpp>
#include <cmath>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/variance.hpp>


std::vector<float> MetricCalculator::calculate(const std::string input) {

    stringToCoordinates(input);
    setDistances();
    setLocalVectors();
    setDistancePerPath();
    setHistorgram();
    normalizeHisto();
    setWeight();
    setAvarageDistanceFromWeight();
    setVarianceFromWeight();
    setInflectionPointCount();
    setHistoData();
    std::vector<float> dummy;  //TODO értelmes return
    return dummy;
}

void MetricCalculator::stringToCoordinates(const std::string input) {
    std::vector<std::string> result;
    boost::split(result, input, boost::is_any_of(" "));
    result.pop_back();


    std::vector<std::string> temp;
    std::transform(result.begin(), result.end(), std::back_inserter(_points),
                   [&](std::string s) -> std::pair<double, double> {
                       boost::split(temp, s, boost::is_any_of(";"));
                       return std::make_pair(std::stod(temp[0]), std::stod(temp[1]));
                   });
}

void MetricCalculator::normalizeHisto() {
    auto pr = std::max_element
            (
                    _histo.begin(), _histo.end(),
                    [](auto &p1, auto &p2) {
                        return p1.second < p2.second;
                    }
            );
    double maxValue = pr->second;
    for (int i = 0; i < 360; ++i) {
        _histo[i] = (_histo[i] / maxValue);
    }
}

void MetricCalculator::setLocalVectors() {
    _localVector.reserve(_points.size() - 1);
    for (int i = 0; i < _points.size() - 1; i++) {
        _localVector.emplace_back(
                std::make_pair(_points[i + 1].first - _points[i].first, _points[i + 1].second - _points[i].second));
    }
}

void MetricCalculator::setHistorgram() {
    double angle;
    std::for_each(_localVector.begin(), _localVector.end(), [&angle, this](std::pair<double, double> point) {
        using namespace std;
        angle = floor((atan2(point.second, point.first) * 180 / M_PI));
        _histo[(angle > 0 ? angle : 360 + angle)] = _histo[(angle > 0 ? angle : 360 + angle)] +
                                                    angle * distanceBetweenPoints(std::make_pair(0, 0), point);
    });
}

void MetricCalculator::setInflectionPointCount() {

//    int iteration = 0;
//    bool isPositive = _localVector[0].first == 0 && _localVector[0].second > 0 ||
//                      _localVector[0].second / _localVector[0].first > 0;
    if (_localVector.size() < 2) {
        _inflcetionPointCount = 0;
        return;
    }

    bool currentStatus =
            _localVector[0].first * _localVector[1].second - _localVector[0].second * _localVector[1].first > 0;

    int counter = 0;
    for (int i = 0; i < _localVector.size() - 1; i++) {
        if (currentStatus != _localVector[i].first * _localVector[i + 1].second -
                             _localVector[i].second * _localVector[i + 1].first > 0) {
            counter++;
            currentStatus = !currentStatus;
        }


//        std::cout<<"first line x: "<<_localVector[i].first <<" y: "<<_localVector[i].second<<"    second line x: "<<_localVector[i+1].first<<" y: "<<_localVector[i+1].second<<std::endl;
//        std::cout<<"result z: "<<_localVector[i].first*_localVector[i+1].second-_localVector[i].second*_localVector[i+1].first<<std::endl;
//        std::cout<<std::endl;
//        std::cout<<std::endl;
//        std::cout<<std::endl;
    }


    _inflcetionPointCount = counter;
}

MetricCalculator::MetricCalculator() {

}

void MetricCalculator::setWeight() {
    std::pair<double, double> weight;
    for (auto p :_points) {
        weight.first += p.first;
        weight.second += p.second;
    }
    weight.first = weight.first / _points.size();
    weight.second = weight.second / _points.size();

    _weight = weight;

}

void MetricCalculator::setAvarageDistanceFromWeight() {
    double sumDistance = 0;
    double distance = 0;
    _distancesFromWeight.reserve(_points.size());
    for (auto p:_points) {
        _distancesFromWeight.emplace_back(distanceBetweenPoints(_weight, p));
        sumDistance += distanceBetweenPoints(_weight, p);
    }
    _avarageDistanceFromWeight =
            sumDistance / (_points.size() - 1); // n points make n-1 segments p1-p2 p2-p3 p3-p4 .....
}

void MetricCalculator::setDistances() {
    _distances.reserve(_points.size() - 1);
    for (int i = 0; i < _points.size() - 1; i++) {
        _distances.emplace_back(distanceBetweenPoints(_weight, _points[i + 1]));
    }
}


//elmozdulás/út hányados számítása
void MetricCalculator::setDistancePerPath() {

    double distance = distanceBetweenPoints(_points[0], _points[_points.size() - 1]);
    double path = 0;
    for (int i = 0; i < _points.size() - 1; i++) {
        path += distanceBetweenPoints(_points[i], _points[i + 1]);
    }
    _distancePerPath = distance / path;
}

void MetricCalculator::setVarianceFromWeight() {
    double sum = 0;
    for (auto d:_distancesFromWeight) {
        sum += (_avarageDistanceFromWeight - d) * (_avarageDistanceFromWeight - d);
    }
    _varianceFromWeight = std::sqrt(sum / _distances.size());
}

double MetricCalculator::distanceBetweenPoints(std::pair<double, double> p1, std::pair<double, double> p2) {

    return std::sqrt(
            ((p2.first - p1.first) * (p2.first - p1.first)) + ((p2.second - p1.second) * (p2.second - p1.second)));
}

void MetricCalculator::setHistoData() {


        for(int i=0; i<360; i++){
        _histo[i]=1;
    }
    using namespace boost::accumulators;
    accumulator_set<float, stats<tag::mean, tag::variance>> acc;

    for(auto m: _histo) {
        for (int i = 0; i < m.second*1000; i++)
            acc(m.first);
    }

    std::cout << "mean=" << mean(acc) << ", variance=" << std::sqrt(variance(acc)) << '\n';
    // prints "mean=3.5, variance=2.91667"




    int count=0;
    for (auto m :_histo) {
        count+=m.second>0?1:0;
    }

    _histoCoverage=count/360.0;
    std::cout <<"cov: " <<_histoCoverage << std::endl;
//    std::cout <<"var: "<< _histoVariance << std::endl;




}

