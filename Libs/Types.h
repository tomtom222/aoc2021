#pragma once
#include <tuple>
#include <vector>
#include <map>
#include <string>

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

typedef std::pair<uint, uint64> fishage;

struct Line
{
	Coordinate p1;
	Coordinate p2;
};
typedef std::vector<Line> Lines;


struct SevenSegmentDisplay
{
	// Display positions
	//	 0000
	//	6    1
	//	6    1
	//	 5555
	//	4    2
	//	4    2
	//	 3333

	void add(std::string& code, uint digit)
	{
		mapping[code] = digit;
		rmapping[digit] = code;
	};

	uint at(const std::string& code)
	{
		auto it = mapping.find(code);
		if (it != mapping.end())
		{
			return it->second;
		}
	};
	std::string& at(uint digit)
	{
		auto it = rmapping.find(digit);
		if (it != rmapping.end())
		{
			return it->second;
		}
	};
	std::string getstring(const std::string& code)
	{
		auto it = mapping.find(code);
		if (it != mapping.end())
		{
			return std::to_string(it->second);
		}
	};

	bool find(const std::string& code)
	{
		auto it = mapping.find(code);
		return (it != mapping.end()) ?  true : false;
	};
	bool find(uint digit)
	{
		auto it = rmapping.find(digit);
		return (it != rmapping.end()) ? true : false;
	};

private:
	std::map<std::string, uint> mapping;
	std::map<uint, std::string> rmapping;
};


