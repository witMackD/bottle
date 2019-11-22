// Bottle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Bottle
{
private:
	float Capacity;
	float ActualWaterLevel;

public:
	float const volume();
	float fill(float waterVolumeToBeFilled);
	float pour(float waterVolumeToBePoured);
	
	Bottle(float size)
	{
		Capacity = size;
		ActualWaterLevel = 0;
	};
};

float const Bottle::volume()
{
	return this->ActualWaterLevel;
}

float Bottle::fill(float waterVolumeToBeFilled)
{
	float remainingBottleVolume = this->Capacity - this->ActualWaterLevel;
	if(waterVolumeToBeFilled >= remainingBottleVolume)
	{
		this->ActualWaterLevel += remainingBottleVolume;
		return remainingBottleVolume;
	}
	this->ActualWaterLevel += waterVolumeToBeFilled;
	return waterVolumeToBeFilled;
}

float Bottle::pour(float waterVolumeToBePoured)
{
	if(this->ActualWaterLevel <= waterVolumeToBePoured)
	{
		float tmp = this->ActualWaterLevel;
		this->ActualWaterLevel = 0;
		return tmp;

	}
	this->ActualWaterLevel -= waterVolumeToBePoured;
	return waterVolumeToBePoured;
}


int main()
{
	Bottle bottle(4.5);
	std::cout << bottle.volume() << " ";
	std::cout << bottle.fill(3.5) << " ";
	std::cout << bottle.volume() << " ";
	std::cout << bottle.pour(5.5) << " ";
	std::cout << bottle.volume() << std::endl;

}
