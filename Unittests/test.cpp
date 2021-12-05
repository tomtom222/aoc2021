#include "pch.h"

#include "StaticFunctions.h"
#include "Types.h"
#include <bitset>

TEST(Day01, SonarSweep)
{
	std::vector<uint> test = {199, 200, 208, 210, 200, 207, 240, 269, 260, 263};

	EXPECT_EQ(Functions::slidingSonarSweep(test), 7u);
	EXPECT_EQ(Functions::slidingSonarSweep(test, 2), 5u);
	EXPECT_EQ(Functions::slidingSonarSweep(test, 3), 5u);
	EXPECT_EQ(Functions::slidingSonarSweep(test, 4), 6u);
	EXPECT_EQ(Functions::slidingSonarSweep(test, 5), 5u);
	EXPECT_EQ(Functions::slidingSonarSweep(test, 6), 4u);
	EXPECT_EQ(Functions::slidingSonarSweep(test, 7), 3u);
	EXPECT_EQ(Functions::slidingSonarSweep(test, 8), 2u);
	EXPECT_EQ(Functions::slidingSonarSweep(test, 9), 1u);
}

TEST(Day02, Diving)
{
	std::vector<DiveInstruction> test =
		{
			DiveInstruction(DiveCommand::forward, 5),
			DiveInstruction(DiveCommand::down, 5),
			DiveInstruction(DiveCommand::forward, 8),
			DiveInstruction(DiveCommand::up, 3),
			DiveInstruction(DiveCommand::down, 8),
			DiveInstruction(DiveCommand::forward, 2),
		};

	EXPECT_EQ(Functions::processDiveInstructions(test), 150u);
	EXPECT_EQ(Functions::processDiveInstructionsWithAim(test), 900u);
}

TEST(Day03, PowerConsumption)
{
	std::vector<std::bitset<16>> test =
		{
			std::bitset<16>{"00100"},
			std::bitset<16>{"11110"},
			std::bitset<16>{"10110"},
			std::bitset<16>{"10111"},
			std::bitset<16>{"10101"},
			std::bitset<16>{"01111"},
			std::bitset<16>{"00111"},
			std::bitset<16>{"11100"},
			std::bitset<16>{"10000"},
			std::bitset<16>{"11001"},
			std::bitset<16>{"00010"},
			std::bitset<16>{"01010"},
		};

	EXPECT_EQ(Functions::calculatePowerConsumption(test, 5), 198u);
	EXPECT_EQ(Functions::calculateLifeSupportRating(test, 5), 230u);
}

TEST(Day04, Bingo)
{
	std::vector<uint> numbers = {7, 4, 9, 5, 11, 17, 23, 2, 0, 14, 21, 24, 10, 16, 13, 6, 15, 25, 12, 22, 18, 20, 8, 19, 3, 26, 1};

	std::vector<std::vector<uint>> bingoCards =
		{
			{22, 13, 17, 11, 0, 8, 2, 23, 4, 24, 21, 9, 14, 16, 7, 6, 10, 3, 18, 5, 1, 12, 20, 15, 19},
			{3, 15, 0, 2, 22, 9, 18, 13, 17, 5, 19, 8, 7, 25, 23, 20, 11, 10, 24, 4, 14, 21, 16, 12, 6},
			{14, 21, 17, 24, 4, 10, 16, 15, 9, 19, 18, 8, 23, 26, 20, 22, 11, 13, 6, 5, 2, 0, 12, 3, 7}};

	std::vector<BingoCard> cards;
	cards.resize(bingoCards.size());

	for (size_t i = 0; i < cards.size(); i++)
	{
		cards[i] = Utils::createBingoCard(bingoCards[i]);
	}

	EXPECT_EQ(Functions::calculateWinningBingoScore(cards, numbers), 4512u);
	EXPECT_EQ(Functions::calculateLosingBingoScore(cards, numbers), 1924u);
}

TEST(Day05, Hydrothermal)
{
	Lines test =
		{
			{{0, 9}, {5, 9}},
			{{8, 0}, {0, 8}},
			{{9, 4}, {3, 4}},
			{{2, 2}, {2, 1}},
			{{7, 0}, {7, 4}},
			{{6, 4}, {2, 0}},
			{{0, 9}, {2, 9}},
			{{3, 4}, {1, 4}},
			{{0, 0}, {8, 8}},
			{{5, 5}, {8, 2}}};

	EXPECT_EQ(Functions::calculateHydrothermalDanger(test, false), 5u);
	EXPECT_EQ(Functions::calculateHydrothermalDanger(test, true), 12u);
}