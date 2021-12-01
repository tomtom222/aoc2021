#include <iostream>
#include "StaticFunctions.h"
#include "Input.h"
#include "Types.h"

int main()
{
    std::cout << "Hello Advent of Code 2021!" << std::endl;
	std::cout << "Day 01_1: " << Functions::slidingSonarSweep(day1) << std::endl;	// 1316
	std::cout << "Day 01_2: " << Functions::slidingSonarSweep(day1,3) << std::endl;	// 1344

}