#include "Input.h"
#include "StaticFunctions.h"
#include "Types.h"
#include <iostream>
#include <sstream>

int main()
{
	std::cout << "Hello Advent of Code 2021!" << std::endl;
	std::cout << "Day 01_1: " << Functions::slidingSonarSweep(day1) << std::endl;			   // 1316
	std::cout << "Day 01_2: " << Functions::slidingSonarSweep(day1, 3) << std::endl;		   // 1344
	std::cout << "Day 02_1: " << Functions::processDiveInstructions(day2) << std::endl;		   // 2070300
	std::cout << "Day 02_2: " << Functions::processDiveInstructionsWithAim(day2) << std::endl; // 2078985210
	std::cout << "Day 03_1: " << Functions::calculatePowerConsumption(day3, 12) << std::endl;  // 1025636
	std::cout << "Day 03_2: " << Functions::calculateLifeSupportRating(day3, 12) << std::endl; // 793873

	std::vector<BingoCard> cards(day4cards.size());
	for (size_t i = 0; i < cards.size(); i++)
	{
		cards[i] = Utils::createBingoCard(day4cards[i]);
	}

	std::cout << "Day 04_1: " << Functions::calculateWinningBingoScore(cards, day4numbers) << std::endl; // 6592
	std::cout << "Day 04_2: " << Functions::calculateLosingBingoScore(cards, day4numbers) << std::endl;	 // 31755
	std::cout << "Day 05_1: " << Functions::calculateHydrothermalDanger(day5, false) << std::endl;		 // 7380
	std::cout << "Day 05_2: " << Functions::calculateHydrothermalDanger(day5, true) << std::endl;		 // 21373
	std::cout << "Day 06_1: " << Functions::calculateFishPopulation(day6, 80) << std::endl;				 // 352151
	std::cout << "Day 06_2: " << Functions::calculateFishPopulation(day6, 256) << std::endl;			 // 1601616884019

	auto answer = Functions::calculateCrabSubmarineFuelReq(day7);
	std::stringstream ss;
	ss << std::get<0>(answer) << ", " << std::get<1>(answer);
	std::cout << "Day 07_1: " << ss.str() << std::endl; // 1601616884019

	answer = Functions::calculateCrabSubmarineFuelReq(day7, true);
	std::stringstream sstr;
	sstr << std::get<0>(answer) << ", " << std::get<1>(answer);
	std::cout << "Day 07_2: " << sstr.str() << std::endl; // 1601616884019

	std::cout << "Day 08_1: " << Functions::calculateUniqueNumber(day8) << std::endl; // 514
	std::cout << "Day 08_2: " << Functions::decodeUniqueNumber(day8) << std::endl;	  // 1012272
	std::cout << "Day 09_1: " << Functions::calculateSmokeHazard(day9) << std::endl;  // 489
	std::cout << "Day 09_2: " << Functions::calculateLargeCavern(day9) << std::endl;  // 1012272
	std::cout << "Day 10_1: " << Functions::calculateSyntaxScore(day10) << std::endl;  // 1012272
	std::cout << "Day 10_2: " << Functions::calculateSyntaxFixScore(day10) << std::endl;  // 1012272
}