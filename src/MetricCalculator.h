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

    Point& operator -(const Point& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    Point& operator +(const Point& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    Point& operator /(const int& rhs)
    {
        x /= rhs;
        y /= rhs;
        return *this;
    }

    Point& operator *(const int& rhs)
    {
        x *= rhs;
        y *= rhs;
        return *this;
    }


    bool operator ==(const Point& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        return x==rhs.x && y==rhs.y;
    }
};



struct Vector{
    Point start;
    Point end;
    Point relativePosition;
    double length;
    int angle;
};


class MetricCalculator {

private:
    //saját
    std::vector<Point> _points;
    std::vector<Vector> _vectors;
    std::vector<float> _histogram;
    Point _center{};
    std::vector<float> _distancesFromWeigth;

//    //
//    std::map<int,float> _histo;
//    //std::vector<std::pair<double,double>> _points;
//    std::vector<std::pair<double,double>> _localVector;
//    std::vector<std::pair<double, double>>_inflectionPoints;
//    std::pair<double,double> _weight;
//    std::vector<double> _distances;
//    //std::vector<double> _distancesFromWeight;
    double _distancePerPath{};
    double _deviationFromWeight{};
    double _avarageDistanceFromWeight{};
    int _inflcetionPointCount{};
    float _histoFancyVariance{};
    float _histoCoverage{};
    double _maxDistanceFromWeight{};
    double _pathLenght{};
    double _maxCurvaturePerPath{};
    double _avarageCurvatureLenght{};
    double _curvatureLenghtDeviation{};
    std::vector<float> _metrics;


    void stringToCoordinates(const std::string& input);
    void setDistancePerPath();
    void setDeviationFromWeight();
    void setVectors();
    void setDistances();
    void setHistorgram();
    void setWeight();
    void setAvarageDistanceFromWeight();
    void setInflectionPointCount();
    void setHistoData();
    void setMetrics();

    //double distance(std::pair<double,double>p1, std::pair<double,double> p2);
    static double distance(Point &p1, Point& p2);
    double distance(Point &&p1, Point &p2);
    static int atan2(Vector &v);
public:
    explicit MetricCalculator()=default;
    std::vector<float>calculate(const std::string& input);
    friend std::ostream& operator<<(std::ostream& out, MetricCalculator& m);
};



#endif //UNTITLED_HISTO_METRICCALCULATOR_H
