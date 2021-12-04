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
	std::cout << "Day 02_2: " << Functions::processDiveInstructionsWithAim(day2) << std::endl; // 2078985210
	std::cout << "Day 03_1: " << Functions::calculatePowerConsumption(day3,12) << std::endl;   // 1025636
	std::cout << "Day 03_2: " << Functions::calculateLifeSupportRating(day3,12) << std::endl;  // 793873
	
	std::vector<BingoCard> cards(day4cards.size());
	for (size_t i = 0; i < cards.size(); i++)
	{
		cards[i] = Utils::createBingoCard(day4cards[i]);
	}
	
	std::cout << "Day 04_1: " << Functions::calculateWinningBingoScore(cards, day4numbers) << std::endl; // 6592
	std::cout << "Day 04_2: " << Functions::calculateLosingBingoScore(cards, day4numbers) << std::endl;	 // 31755
}