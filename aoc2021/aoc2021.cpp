#include "Input.h"
#include "StaticFunctions.h"
#include "Types.h"
#include <iostream>

int main()
{
	std::cout << "Hello Advent of Code 2021!" << std::endl;
	std::cout << "Day 01_1: " << Functions::slidingSonarSweep(day1) << std::endl;			   // 1316
	std::cout << "Day 01_2: " << Functions::slidingSonarSweep(day1, 3) << std::endl;		   // 1344
	std::cout << "Day 02_1: " << Functions::processDiveInstructions(day2) << std::endl;		   // 2070300
	std::cout << "Day 02_1: " << Functions::processDiveInstructionsWithAim(day2) << std::endl; // 2078985210
}