#pragma once
#include "Report.h"
class Statistics
{
private:
    double averageBMI;
    double maxBMI;
    double minBMI;

public:

    void updateStatistics(Report report) {
        int userCount = report.userCount;
        double sumBMI = 0;
        maxBMI = 0;
        minBMI = 0;

        if (userCount > 0) {
            minBMI = report.bmiData[0];
        }

        for (int i = 0; i < userCount; i++) {
            double bmi = report.bmiData[i];
            sumBMI += bmi;

            if (bmi > maxBMI) {
                maxBMI = bmi;
            }

            if (bmi < minBMI) {
                minBMI = bmi;
            }
        }

        if (userCount > 0) {
            averageBMI = sumBMI / userCount;
        }
        else {
            averageBMI = 0;
        }
    }
    double getAverageBMI() {
        return averageBMI;
    }
    double getMaxBMI() {
        return maxBMI;
    }
    double getMinBMI() {
        return minBMI;
    }
};