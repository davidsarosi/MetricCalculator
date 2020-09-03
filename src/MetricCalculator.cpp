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

std::vector<float> MetricCalculator::calculate(const std::string& input) {
    stringToCoordinates(input);
    setDistances();
    setLocalVectors();
    setDistancePerPath();
    setHistorgram();
    setWeight();
    setAvarageDistanceFromWeight();
    setVarianceFromWeight();
    setInflectionPointCount();
    setHistoData();
    setMetrics();
    return _metrics;
}

void MetricCalculator::stringToCoordinates(const std::string& input) {

    std::vector<std::string> raw_points;
    boost::split(raw_points, input, boost::is_any_of(" "));
    raw_points.pop_back();

    std::vector<std::string> temp;
    _points.reserve(raw_points.size());
    for(auto & raw_point : raw_points){
        boost::split(temp, raw_point, boost::is_any_of(";"));
        auto p = new Point;
        p->x = std::stod(temp[0]);
        p->y = std::stod(temp[1]);
        _points.emplace_back(*p);
    }
}

void MetricCalculator::setLocalVectors() {
    _localVectors.reserve(_points.size() - 1);
    for (int i = 0; i < _points.size() - 1; i++) {
        auto v = new Vector;
        v->start = _points[i];
        v->end = _points[i+1];
        v->length = distance(v->start,v->end);
        v->angle = atan2(*v);
        _localVectors.emplace_back(*v);
    }
}

void MetricCalculator::setHistorgram() {
    _histogram = std::vector<float>(360);
    std::fill(_histogram.begin(),_histogram.end(),0.0);
    for(auto &v : _localVectors){
        int index = v.angle;
        _histogram[index] += v.length;
    }
    //normalise
    float max = _histogram[0];
    for(auto & i : _histogram){
        i>max? max = i : 0;
    }
    for (int i = 0; i < 360; ++i) {
        _histogram[i] /= max;
    }
}

void MetricCalculator::setInflectionPointCount() {
    if (_localVectors.size() < 2) {
        _inflcetionPointCount = 0;
        return;
    }
    auto current = _localVectors[0];
    auto next = _localVectors[1];
    bool currentStatus = current
            _localVector[0].first * _localVector[1].second - _localVector[0].second * _localVector[1].first > 0;

    int counter = 0;
    for (int i = 0; i < _localVector.size() - 1; i++) {
        if (currentStatus != _localVector[i].first * _localVector[i + 1].second -
                             _localVector[i].second * _localVector[i + 1].first > 0) {
            counter++;
            currentStatus = !currentStatus;
        }
    }
    _inflcetionPointCount = counter;
}

MetricCalculator::MetricCalculator() {

}

void MetricCalculator::setWeight() {
    double x = 0;
    double y = 0;
    for(auto p : _points){
        x+=p.x;
        y+=p.y;
    }
    _center.x = x/_points.size();
    _center.y = y/_points.size();
}

void MetricCalculator::setAvarageDistanceFromWeight() {
    double sumDistance = 0;
    for(auto d : _distancesFromWeigth){
        sumDistance += d;
    }
    _avarageDistanceFromWeight = sumDistance/_distancesFromWeigth.size();
}

void MetricCalculator::setDistances() {
    for(auto p : _points){
        _distancesFromWeigth.push_back(distance(p,_center));
    }
}
//elmozdulás/út hányados számítása
void MetricCalculator::setDistancePerPath() {
    double pathLength = 0;
    for(auto v : _localVectors){
        pathLength += v.length;
    }
    double dist = distance(_points.front(),_points.back());
    _distancePerPath = dist / pathLength;
}

void MetricCalculator::setVarianceFromWeight() {
    double sumBias = 0;
    for(auto d : _distancesFromWeigth){
        double bias = std::abs(_avarageDistanceFromWeight - d);
        sumBias += bias*bias;
    }
    _varianceFromWeight = std::sqrt(sumBias / _distancesFromWeigth.size());
}

double  MetricCalculator::distance(Point &p1, Point &p2) {
    return std::sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y)));
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

    std::cout << "mean=" << mean(acc) << ", deviation=" << std::sqrt(variance(acc)) << '\n';
    // prints "mean=3.5, deviation=2.91667"




    int count=0;
    for (auto m :_histo) {
        count+=m.second>0?1:0;
    }
    _histoCoverage=count/360.0;
}

void MetricCalculator::setMetrics() {
    _metrics.push_back(_distancePerPath);
    _metrics.push_back(_avarageDistanceFromWeight);
    _metrics.push_back(_varianceFromWeight);
    _metrics.push_back(_histoVariance);
    _metrics.push_back(_histoCoverage);
    _metrics.push_back(_inflcetionPointCount);
}

int MetricCalculator::atan2(Vector &v) {
    int x = v.end.x - v.start.x;
    int y = v.end.y - v.start.y;
    int angle = floor((std::atan2(y, x) * 180 / M_PI));
    return angle > 0 ? angle : 360 + angle;
}


