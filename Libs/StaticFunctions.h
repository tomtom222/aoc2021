#pragma once
#include "Types.h"
#include <vector>
#include <bitset>

class Functions
{
public:
	static const uint slidingSonarSweep(const std::vector<uint>& vec, const uint window = 1u);
	static const uint processDiveInstructions(const std::vector<DiveInstruction>& vec);
	static const uint processDiveInstructionsWithAim(const std::vector<DiveInstruction>& vec);
	static const uint calculatePowerConsumption(const std::vector<std::bitset<16>>& vec, const uint validbitnum);
	static const uint calculateLifeSupportRating(const std::vector<std::bitset<16>>& vec, const uint validbitnum);
	static const uint calculateWinningBingoScore(std::vector<BingoCard> cards, const std::vector<uint>& numbers);
	static const uint calculateLosingBingoScore(std::vector<BingoCard> cards, const std::vector<uint>& numbers);
};

class Utils
{
public:
	static BingoCard createBingoCard(const std::vector<uint>& input);
	static bool checkBingo(BingoCard& card, uint number);
};