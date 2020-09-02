#include <iostream>
#include "MetricCalculator.h"
#include <iostream>
#include <fstream>

int main() {




    //MetricCalculator metricCalculator("1520;578 1520;582 1518;594 1512;610 1508;628 1498;650 1488;678 1476;702 1460;746 1444;786 1430;840 1428;848 1418;896 1406;950 1394;998 1390;1026 1380;1062 1374;1106 1370;1120 1368;1136 1366;1150 1366;1160 1366;1174");
//    MetricCalculator metricCalculator("0;0 1;1 3;2 4;0 6;1 7;0 3;-1 ");
    MetricCalculator metricCalculator;
    metricCalculator.calculate(
            "1520;578 1520;582 1518;594 1512;610 1508;628 1498;650 1488;678 1476;702 1460;746 1444;786 1430;840 1428;848 1418;896 1406;950 1394;998 1390;1026 1380;1062 1374;1106 1370;1120 1368;1136 1366;1150 1366;1160 1366;1174");
    std::cout << "inflection point count: " << metricCalculator._inflcetionPointCount << std::endl;
    std::cout << "distance per path: " << metricCalculator._distancePerPath << std::endl;
    metricCalculator.setWeight();
    std::cout << "weight:  x:" << metricCalculator._weight.first << " y: " << metricCalculator._weight.second << std::endl;
    std::cout << "avarage distance from weight: " << metricCalculator._avarageDistanceFromWeight << std::endl;
    std::cout << "variance from weight: " << metricCalculator._varianceFromWeight << std::endl;
    std::cout<<std::endl;
    std::ofstream outfile ("test.txt");
    for(auto h :metricCalculator._histo)
        outfile<<h.second<<std::endl;
    outfile.close();

//    for (int i = 0; i < 360; ++i) {
//
//    }
//   std::cout<< metricCalculator.setInflectionPointCount()<<std::endl;
    return 0;
}
