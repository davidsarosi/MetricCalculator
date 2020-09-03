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
#include <boost/accumulators/statistics/weighted_variance.hpp>

std::vector<float> MetricCalculator::calculate(const std::string &input) {
    stringToCoordinates(input);
    setVectors();
    setWeight();
    setDistances();
    setDistancePerPath();
    setHistorgram();
    setAvarageDistanceFromWeight();
    setDeviationFromWeight();
    setInflectionPointCount();
    setHistoData();
    setMetrics();
    return _metrics;
}

void MetricCalculator::stringToCoordinates(const std::string &input) {

    std::vector<std::string> raw_points;
    boost::split(raw_points, input, boost::is_any_of(" "));
    raw_points.pop_back();

    std::vector<std::string> temp;
    _points.reserve(raw_points.size());
    for (auto &raw_point : raw_points) {
        boost::split(temp, raw_point, boost::is_any_of(";"));
        auto p = new Point;
        p->x = std::stod(temp[0]);
        p->y = std::stod(temp[1]);
        _points.emplace_back(*p);
    }
}

void MetricCalculator::setVectors() {
    _vectors.reserve(_points.size() - 1);
    for (int i = 0; i < _points.size() - 1; i++) {
        auto v = new Vector;
        v->start = _points[i];
        v->end = _points[i + 1];
        v->length = distance(v->start, v->end);
        v->relativePosition = v->end - v->start;
        v->angle = atan2(*v);
        _vectors.emplace_back(*v);
    }
}

void MetricCalculator::setHistorgram() {
    _histogram = std::vector<float>(360);

    std::fill(_histogram.begin(), _histogram.end(), 0.0);
    for (auto &v : _vectors) {
        int index = v.angle;
        _histogram[index] += v.length;
    }
    //normalise
    auto max = std::max_element(_histogram.begin(), _histogram.end());

    for (int i = 0; i < 360; ++i) {
        _histogram[i] /= *max;
    }
}

void MetricCalculator::setInflectionPointCount() {
    if (_vectors.size() < 2) {
        _inflcetionPointCount = 0;
        return;
    }
    auto current = _vectors[0].relativePosition;
    auto next = _vectors[1].relativePosition;
    bool currentGradient = current.x * next.y - current.y * next.x > 0;    //init current gradient
    int counter = 0;
    std::vector<double> gradientLenghts;
    gradientLenghts.reserve(_vectors.size() - 1);    //TODO maybe give it more love
    double currentGradientLenght = 0;
    double maxGradientLenght = 0;
    for (int i = 0; i < _vectors.size() - 1; i++) {
        current = _vectors[i].relativePosition;
        next = _vectors[i + 1].relativePosition;
        currentGradientLenght += _vectors[i].length;
        if (currentGradient != current.x * next.y - current.y * next.x > 0) {  //if current and last gradient differs
            counter++;                                                 // then we reached and inflection point
            currentGradient = !currentGradient;
            gradientLenghts.emplace_back(currentGradientLenght);
            maxGradientLenght = currentGradientLenght > maxGradientLenght ? currentGradientLenght : maxGradientLenght;
            currentGradientLenght = 0;
        }
    }
    gradientLenghts.shrink_to_fit();
    double sum_of_elems = 0;
    for (auto &n : gradientLenghts)
        sum_of_elems += n;
    using namespace boost::accumulators;
    accumulator_set<double, stats<tag::mean, tag::variance>> acc;


    for (auto gl:gradientLenghts) {
        acc(gl);
    }
    _maxCurvaturePerPath = maxGradientLenght / _pathLenght;
    _curvatureLenghtDeviation = std::sqrt(variance(acc))/maxGradientLenght;
    _avarageCurvatureLenght=mean(acc)/maxGradientLenght;
    _inflcetionPointCount = counter;
}


void MetricCalculator::setWeight() {
    Point weight{0, 0};
    for (auto p : _points) {
        weight = weight + p;
    }
    _center = weight / _points.size();
}

void MetricCalculator::setAvarageDistanceFromWeight() {
    double sumDistance = 0;
    double max = 0;
    for (auto d : _distancesFromWeigth) {
        sumDistance += d;
        max = d > max ? d : max;
    }
    _maxDistanceFromWeight = max;
    _avarageDistanceFromWeight = sumDistance / _distancesFromWeigth.size() / max;
}

void MetricCalculator::setDistances() {
    _distancesFromWeigth.reserve(_points.size());
    for (auto p : _points) {
        _distancesFromWeigth.emplace_back(distance(p, _center));
    }
}

//elmozdulás/út hányados számítása
void MetricCalculator::setDistancePerPath() {
    double pathLength = 0;
    for (auto v : _vectors) {      //lenght of trajectory
        pathLength += v.length;
    }
    _pathLenght = pathLength;
    double dist = distance(_points.front(), _points.back());
    _distancePerPath = dist / pathLength;
}

void MetricCalculator::setDeviationFromWeight() {
    double sumBias = 0;
    double bias = 0;
    for (auto d : _distancesFromWeigth) {
        bias = std::abs(_avarageDistanceFromWeight - d);
        sumBias += bias * bias;
    }
    _deviationFromWeight = std::sqrt(sumBias / _distancesFromWeigth.size()) / _maxDistanceFromWeight;
}

double MetricCalculator::distance(Point &p1, Point &p2) {
    return std::sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y)));
}

double MetricCalculator::distance(Point &&p1, Point &p2) {
    return std::sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y)));
}

void MetricCalculator::setHistoData() {
    using namespace boost::accumulators;
    accumulator_set<float, stats<tag::weighted_variance(lazy)>, float> acc;
//    std::fill(_histogram.begin(), _histogram.end(), 0.0);


    Point fancyWeightPoint{0, 0};
    Point tempDummy{0, 0};
    double angle_in_radian;
    double x, y;
    for (int i = 0; i < _histogram.size(); i++) {
        angle_in_radian = i * M_PI / 180.0;
        tempDummy.x = std::cos(angle_in_radian);
        tempDummy.y = std::sin(angle_in_radian);

        fancyWeightPoint = fancyWeightPoint + tempDummy * _histogram[i];
    }
    fancyWeightPoint = fancyWeightPoint / 360;

    double dis = distance({0, 0}, fancyWeightPoint);
    _histoFancyVariance = dis;


    double coverage = 0;
    for (auto m :_histogram) {
        coverage += m > 0 ? 1 : 0;
    }

    _histoCoverage = static_cast<float>(coverage / 360.0);
}

void MetricCalculator::setMetrics() {
    //TODO reserve
    _metrics.push_back(_distancePerPath);
    _metrics.push_back(_avarageDistanceFromWeight);
    _metrics.push_back(_deviationFromWeight);
    _metrics.push_back(_histoFancyVariance);
    _metrics.push_back(_histoCoverage);
//    _metrics.push_back(_inflcetionPointCount);
    _metrics.push_back(_maxCurvaturePerPath);
}

int MetricCalculator::atan2(Vector &v) {
    int angle = floor((std::atan2(v.relativePosition.y, v.relativePosition.x) * 180 / M_PI));
    return angle > 0 ? angle : 360 + angle;
}

std::ostream &operator<<(std::ostream &out, MetricCalculator &m) {

    out << "Distance per path: " << m._distancePerPath << std::endl;
    out << "Avarage distance from weight: " << m._avarageDistanceFromWeight << std::endl;
    out << "Deviation from weight: " << m._deviationFromWeight << std::endl;
    out << "Histogram fancy variance: " << m._histoFancyVariance << std::endl;
    out << "Histogram coverage: " << m._histoCoverage << std::endl;
    out << "Inflection point count: " << m._inflcetionPointCount << std::endl;      //TODO not a real metric
    out << "Longest curve/full path: " << m._maxCurvaturePerPath << std::endl;
    out << "Mean curvature lenght/max curvature lenght: " << m._avarageCurvatureLenght << std::endl;
    out << "Curvature deviation/ max curvature lenght: " << m._curvatureLenghtDeviation << std::endl;

    return out;
}






