#pragma once
#include "Types.h"
#include <bitset>
#include <vector>

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
	static const uint calculateHydrothermalDanger(const Lines& lines, bool diag);
	static const uint64 calculateFishPopulation(std::vector<uint> fish, const uint days);
	static const std::pair<uint, uint> calculateCrabSubmarineFuelReq(std::vector<uint> crabs, bool correctfuel = false);
	static const uint calculateUniqueNumber(const std::vector<std::string>& input);
	static const uint decodeUniqueNumber(const std::vector<std::string>& input);
};

class Utils
{
public:
	static BingoCard createBingoCard(const std::vector<uint>& input);
	static bool checkBingo(BingoCard& card, uint number);
	static std::vector<std::string> split(const std::string& input, const std::string& pattern);
};