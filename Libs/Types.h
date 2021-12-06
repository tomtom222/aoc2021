#pragma once
#include <tuple>
#include <vector>

typedef unsigned int uint;
typedef unsigned long long int uint64;

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
	bool isSet = false;
};

struct Coordinate
{
	uint x = 0;
	uint y = 0;

	friend bool operator<(const Coordinate& lhs, const Coordinate& rhs)
	{
		return std::tie(lhs.x, lhs.y) < std::tie(rhs.x, rhs.y);
	};
};

typedef std::vector<Coordinate> Coordinates;

struct Line
{
	Coordinate p1;
	Coordinate p2;
};
typedef std::vector<Line> Lines;

typedef std::pair<uint, uint64> fishage;

