#include "stats.h"
#include "iostream"

void StatsAlerter::checkAndAlert(const std::vector<float>& data)
{
	float max = data[0];
	for (auto input : data)
	{
		if (input > max)
		{
			max = input;
		}
	}
	if (max > maxThres)
	{
		std::vector<IAlerter*>::iterator iterator = IAlerts.begin();
		while (iterator != IAlerts.end())
		{
			(*iterator)->updateState();
			++iterator;
		}
	}
}

Stats Statistics::ComputeStatistics(const std::vector<float>& data)
{
	std::cout << "Ok" << std::endl;
	stats val;
	if (data.size() > 0)
	{
		float avg = 0;
		float min = data[0];
		float max = data[0];
		for (auto input : data)
		{
			if (input < min)
			{
				min = input;
			}
			if (input > max)
			{
				max = input;
			}
			avg = avg + input;
		}
		avg = avg / data.size();
		val.average = avg;
		val.max = max;
		val.min = min;
	}
	else
	{
		val.average = NAN;
		val.max = NAN;
		val.min = NAN;
	}
	return val;
}

