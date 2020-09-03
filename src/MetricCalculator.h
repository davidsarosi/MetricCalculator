//
// Created by sarosi on 25/08/2020.
//

#ifndef UNTITLED_HISTO_METRICCALCULATOR_H
#define UNTITLED_HISTO_METRICCALCULATOR_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#define private public

struct Point{
    double x;
    double y;
};

struct Vector{
    Point start;
    Point end;
    double length;
    int angle;
};


class MetricCalculator {

private:
    //saját
    std::vector<Point> _points;
    std::vector<Vector> _localVectors;
    std::vector<float> _histogram;
    Point _center;
    std::vector<float> _distancesFromWeigth;

//    //
//    std::map<int,float> _histo;
//    //std::vector<std::pair<double,double>> _points;
//    std::vector<std::pair<double,double>> _localVector;
//    std::vector<std::pair<double, double>>_inflectionPoints;
//    std::pair<double,double> _weight;
//    std::vector<double> _distances;
//    //std::vector<double> _distancesFromWeight;
    double _distancePerPath;
    double _varianceFromWeight;
    double _avarageDistanceFromWeight;
    int _inflcetionPointCount;
    float _histoVariance;
    float _histoCoverage;
    std::vector<float> _metrics;


    void stringToCoordinates(const std::string& input);
    void setDistancePerPath();
    void setVarianceFromWeight();
    void setLocalVectors();
    void setDistances();
    void setHistorgram();
    void setWeight();
    void setAvarageDistanceFromWeight();
    void setInflectionPointCount();
    void setHistoData();
    void setMetrics();

    //double distance(std::pair<double,double>p1, std::pair<double,double> p2);
    double distance(Point &p1, Point& p2);
    int atan2(Vector &v);
public:
    explicit MetricCalculator();
    std::vector<float>calculate(const std::string& input);
};



#endif //UNTITLED_HISTO_METRICCALCULATOR_H
