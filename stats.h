#include <vector>
#include <iostream>
#include <cmath>
class Stats
{
public:
    float average;
    float min;
    float max;
};
class IAlerter
{
public:
    virtual void updateState()=0;
};

class EmailAlert: public IAlerter
{
    
    void updateState() override
    {
        emailSent = true;
        std::cout << "EmailAlered called..." << std::endl;
    }
public:
    bool emailSent = false;
    EmailAlert()
    {
        emailSent = false;
    }
};
class LEDAlert: public IAlerter
{

    void updateState() override 
    {
        ledGlows = true;
        std::cout << "LedAlered called..." << std::endl;
    }
public:
    bool ledGlows;
    LEDAlert()
    {
        ledGlows = false;
    }
};

class StatsAlerter
{
    int maxThres;
    std::vector<IAlerter*> IAlerts;
public:
    StatsAlerter(int maxThreshold, std::vector<IAlerter*> IAlerters)
    {
        maxThres = maxThreshold;
        IAlerts = IAlerters;
    }
    void checkAndAlert(const std::vector<float>& data);
};
namespace Statistics {   
    Stats ComputeStatistics(const std::vector<float>& data);
}



