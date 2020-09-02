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

class MetricCalculator {

private:
    std::map<int,float> _histo;
    std::vector<std::pair<double,double>> _points;
    std::vector<std::pair<double,double>> _localVector;
    std::vector<std::pair<double, double>>_inflectionPoints;
    std::pair<double,double> _weight;
    std::vector<double> _distances;
    std::vector<double> _distancesFromWeight;
    double _distancePerPath;
    double _varianceFromWeight;
    double _avarageDistanceFromWeight;
    int _inflcetionPointCount;
    float _histoVariance;
    float _histoCoverage;


    void stringToCoordinates(const std::string input);
    void setDistancePerPath();
    void setVarianceFromWeight();
    void setLocalVectors();
    void setDistances();
    void setHistorgram();
    void setWeight();
    void setAvarageDistanceFromWeight();
    void setInflectionPointCount();
    void setHistoData();

    double distanceBetweenPoints(std::pair<double,double>p1, std::pair<double,double> p2);
    void normalizeHisto();
public:
    explicit MetricCalculator();
    std::vector<float>calculate(const std::string input);



};



#endif //UNTITLED_HISTO_METRICCALCULATOR_H
