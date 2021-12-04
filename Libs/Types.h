#pragma once
#include <tuple>
#include <vector>

typedef unsigned int uint;

enum class DiveCommand : uint
{
	forward,
	down,
	up,
};
typedef std::tuple<DiveCommand, uint> DiveInstruction;
typedef std::tuple<uint, bool> BingoNumber;

struct BingoCard
{
	BingoCard() 
	{
		data.resize(5);
		for (size_t i = 0; i < data.size(); i++)
		{
			data[i].resize(5);
		}
	}
	std::vector<std::vector<BingoNumber>> data;
	bool isSet= false;
};