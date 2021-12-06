#include "StaticFunctions.h"
#include "Types.h"
#include <algorithm>
#include <iostream>
#include <map>

const uint Functions::slidingSonarSweep(const std::vector<uint>& vec, const uint window)
{
	if (vec.size() == 0)
	{
		return 0u;
	}
	uint count = 0;
	uint prevwindow = 0;

	for (size_t i = window - 1; i < vec.size(); i++)
	{
		uint currentwindow = 0;
		for (size_t j = 0; j < window; j++)
		{
			currentwindow += vec.at(i - j);
		}

		if (currentwindow > prevwindow && prevwindow != 0)
		{
			count++;
		}
		prevwindow = currentwindow;
	}
	return count;
}

const uint Functions::processDiveInstructions(const std::vector<DiveInstruction>& vec)
{
	if (vec.size() == 0)
	{
		return 0u;
	}

	uint horizontalmove = 0;
	uint verticalmove = 0;

	for (auto& i : vec)
	{
		switch (std::get<0>(i))
		{
		case DiveCommand::forward:
			horizontalmove += std::get<1>(i);
			break;
		case DiveCommand::up:
			verticalmove -= std::get<1>(i);
			break;
		case DiveCommand::down:
			verticalmove += std::get<1>(i);
			break;
		}
	}
	return horizontalmove * verticalmove;
}

const uint Functions::processDiveInstructionsWithAim(const std::vector<DiveInstruction>& vec)
{
	if (vec.size() == 0)
	{
		return 0u;
	}

	uint horizontalmove = 0;
	uint verticalmove = 0;
	uint aim = 0;

	for (auto& i : vec)
	{
		switch (std::get<0>(i))
		{
		case DiveCommand::forward:
		{
			uint num = std::get<1>(i);
			horizontalmove += num;
			if (aim != 0)
			{
				verticalmove += (aim * num);
			}
			break;
		}
		case DiveCommand::up:
			aim -= std::get<1>(i);
			break;
		case DiveCommand::down:
			aim += std::get<1>(i);
			break;
		}
	}
	return horizontalmove * verticalmove;
}

const uint count(const std::vector<std::bitset<16>>& vec, const size_t& pos)
{
	uint count = 0;
	for (auto& set : vec)
	{
		if (set[pos])
		{
			count++;
		}
	}
	return count;
}

const uint Functions::calculatePowerConsumption(const std::vector<std::bitset<16>>& vec, const uint validbitnum)
{
	if (vec.size() == 0)
	{
		return 0u;
	}

	uint gammaRate = 0;
	uint epsilonRate = 0;

	std::vector<uint> counts(validbitnum);
	std::fill(counts.begin(), counts.end(), 0u);

	for (size_t i = 0; i < counts.size(); i++)
	{
		counts[i] = count(vec, i);
	}

	for (size_t i = 0; i < counts.size(); i++)
	{
		gammaRate |= (counts[i] > (vec.size() / 2)) << i;
		epsilonRate |= (counts[i] < (vec.size() / 2)) << i;
	}

	return gammaRate * epsilonRate;
}

const uint getRating(const std::vector<std::bitset<16>>& vec, const uint validbitnum, bool greater)
{
	std::vector<uint> counts(validbitnum);
	std::fill(counts.begin(), counts.end(), 0u);

	std::vector<std::bitset<16>> shortlist = vec;
	std::vector<std::bitset<16>> o2shortlist;
	uint i = validbitnum - 1;
	do
	{
		o2shortlist.clear();
		std::fill(counts.begin(), counts.end(), 0u);
		for (size_t j = 0; j < counts.size(); j++)
		{
			counts[j] = count(shortlist, j);
		}
		bool pref = false;
		if (greater)
		{
			pref = (counts[i] * 2) >= shortlist.size();
		}
		else
		{
			pref = (counts[i] * 2) < shortlist.size();
		}

		for (auto& set : shortlist)
		{
			if (set[i] == pref)
			{
				o2shortlist.push_back(set);
			}
		}
		shortlist.clear();
		shortlist = o2shortlist;
		i--;
	} while (shortlist.size() > 1 || i == 0);

	return shortlist[0].to_ulong();
}

const uint Functions::calculateLifeSupportRating(const std::vector<std::bitset<16>>& vec, const uint validbitnum)
{
	if (vec.size() == 0)
	{
		return 0u;
	}

	uint O2Rating = getRating(vec, validbitnum, true);
	uint CO2Rating = getRating(vec, validbitnum, false);

	return O2Rating * CO2Rating;
}

const uint Functions::calculateWinningBingoScore(std::vector<BingoCard> cards, const std::vector<uint>& numbers)
{
	BingoCard winningcard;
	uint currentnum = 0;

	for (size_t i = 0; i < numbers.size() && !winningcard.isSet; i++)
	{
		for (size_t j = 0; j < cards.size() && !winningcard.isSet; j++)
		{
			if (Utils::checkBingo(cards[j], numbers[i]))
			{
				winningcard = cards[j];
				currentnum = numbers[i];
			}
		}
	}

	if (!winningcard.isSet)
	{
		return 0u;
	}

	uint sum = 0;
	for (size_t i = 0; i < winningcard.data.size(); i++)
	{
		for (size_t j = 0; j < winningcard.data[i].size(); j++)
		{
			if (!std::get<1>(winningcard.data[i][j]))
			{
				sum += std::get<0>(winningcard.data[i][j]);
			}
		}
	}
	return sum * currentnum;
}

const uint Functions::calculateLosingBingoScore(std::vector<BingoCard> cards, const std::vector<uint>& numbers)
{
	BingoCard lastwinningcard;
	uint currentnum = 0;
	std::vector<BingoCard> leftovercards = cards;

	for (size_t i = 0; i < numbers.size() && leftovercards.size() > 0; i++)
	{
		currentnum = numbers[i];

		for (auto it = leftovercards.begin(); it != leftovercards.end();)
		{
			if (Utils::checkBingo(*it, currentnum))
			{
				lastwinningcard = leftovercards[0]; // set card
				it = leftovercards.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

	if (!lastwinningcard.isSet)
	{
		return 0u;
	}

	uint sum = 0;
	for (size_t i = 0; i < lastwinningcard.data.size(); i++)
	{
		for (size_t j = 0; j < lastwinningcard.data[i].size(); j++)
		{
			if (!std::get<1>(lastwinningcard.data[i][j]))
			{
				sum += std::get<0>(lastwinningcard.data[i][j]);
			}
		}
	}
	return sum * currentnum;
}

const uint Functions::calculateHydrothermalDanger(const Lines& lines, bool diag)
{
	Lines xlines;
	Lines ylines;
	Lines diaglines;

	for (auto& line : lines)
	{
		if (line.p1.x == line.p2.x)
		{
			ylines.push_back(line);
		}
		else if (line.p1.y == line.p2.y)
		{
			xlines.push_back(line);
		}
		else if (diag &&
				 (std::abs((int)line.p1.x - (int)line.p2.x) == std::abs((int)line.p1.y - (int)line.p2.y)))
		//((line.p1.x == line.p1.y && line.p2.x == line.p2.y) ||
		// (line.p1.x == line.p2.y && line.p1.y == line.p2.x)))
		{
			diaglines.push_back(line);
		}
	}

	if ((!xlines.size() || !ylines.size()) || (diag && !diaglines.size()))
	{
		return 0u;
	}

	Coordinates c;
	for (auto& line : xlines)
	{
		if (line.p1.x > line.p2.x)
		{
			for (uint i = line.p2.x; i <= line.p1.x; i++)
			{
				c.push_back({i, line.p1.y});
			}
		}
		else
		{
			for (uint i = line.p1.x; i <= line.p2.x; i++)
			{
				c.push_back({i, line.p1.y});
			}
		}
	}

	for (auto& line : ylines)
	{
		if (line.p1.y > line.p2.y)
		{
			for (uint i = line.p2.y; i <= line.p1.y; i++)
			{
				c.push_back({line.p1.x, i});
			}
		}
		else
		{
			for (uint i = line.p1.y; i <= line.p2.y; i++)
			{
				c.push_back({line.p1.x, i});
			}
		}
	}

	if (diag)
	{
		for (auto& line : diaglines)
		{
			if (line.p1.x > line.p2.x && line.p1.y > line.p2.y) // + +
			{
				uint iters = line.p1.x - line.p2.x;
				for (uint i = 0; i <= iters; i++)
				{
					c.push_back({line.p2.x + i, line.p2.y + i});
				}
			}
			else if (line.p1.x > line.p2.x && line.p1.y < line.p2.y) // + -
			{
				uint iters = line.p1.x - line.p2.x;
				for (uint i = 0; i <= iters; i++)
				{
					c.push_back({line.p2.x + i, line.p2.y - i});
				}
			}
			else if (line.p1.x < line.p2.x && line.p1.y < line.p2.y) // - -
			{
				uint iters = line.p2.x - line.p1.x;
				for (uint i = 0; i <= iters; i++)
				{
					c.push_back({line.p2.x - i, line.p2.y - i});
				}
			}
			else // - +
			{
				uint iters = line.p2.x - line.p1.x;
				for (uint i = 0; i <= iters; i++)
				{
					c.push_back({line.p2.x - i, line.p2.y + i});
				}
			}
		}
	}

	std::sort(c.begin(), c.end(),
			  [](Coordinate& a, Coordinate& b) -> bool { return std::tie(a.x, a.y) < std::tie(b.x, b.y); });

	std::map<Coordinate, size_t> dups;
	for (auto& i : c)
	{
		++dups[i];
	}

	uint count = 0;
	for (auto& [key, value] : dups)
	{
		if (value > 1)
		{
			count++;
		}
	}

	return count;
}


std::vector<fishage> daycalc(std::vector<fishage>& fish)
{
	std::vector<fishage> fishies =
		{
			{8, 0},
			{7, 0},
			{6, 0},
			{5, 0},
			{4, 0},
			{3, 0},
			{2, 0},
			{1, 0},
			{0, 0},
		};


	for (size_t i = 0; i < fish.size(); i++)
	{
		switch (std::get<0>(fish[i]))
		{
		case 8:
		case 7:
		case 6:
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		{
			auto f = std::get<1>(fish[i]);
			std::get<1>(fishies[i + 1]) += f; 
			//std::get<1>(fish[i]) -= f; 
			break;
		}
		case 0:
		{
			auto f = std::get<1>(fish[i]);
			std::get<1>(fishies[2]) += f;
			std::get<1>(fishies[0]) += f;
			//std::get<1>(fish[8]) -= f;
			break;
		}
		default:
			break;
		}
	}
	return fishies;
}

const uint64 Functions::calculateFishPopulation(std::vector<uint> fish, const uint days)
{
	std::vector<fishage> fishies = 
	{
			{8,0},
			{7,0},
			{6,0},
			{5,0},
			{4,0},
			{3,0},
			{2,0},
			{1,0},
			{0,0},
	};

	for (size_t i = 0; i < fish.size(); i++)
	{
		for (size_t j = 0; j < fishies.size(); j++)
		{
			if (std::get<0>(fishies[j]) == fish[i])
			{
				std::get<1>(fishies[j])++;
			}
		}
	}

	
	for (size_t i = 0; i < days; i++)
	{
		fishies = daycalc(fishies);
	}

	uint64 count = 0;
	for (auto& f : fishies)
	{
		count += std::get<1>(f);
	}

	return count;
}

BingoCard Utils::createBingoCard(const std::vector<uint>& input)
{
	// Bingo cards are a FIXED 5x5 array!!
	if (input.size() != 25)
	{
		std::cout << "ERROR: Bingocard creation failed!!" << std::endl;
		return BingoCard();
	}

	BingoCard c;

	for (size_t i = 0; i < c.data.size(); i++)
	{
		for (size_t j = 0; j < c.data[i].size(); j++)
		{
			std::get<0>(c.data[i][j]) = input[i * 5 + j];
		}
	}
	c.isSet = true;

	return c;
}

bool Utils::checkBingo(BingoCard& card, uint number)
{
	bool found = false;
	uint row = 0;
	uint col = 0;

	// check if number is in card
	for (row = 0; row < card.data.size() && !found; row++)
	{
		for (col = 0; col < card.data[row].size() && !found; col++)
		{
			if (std::get<0>(card.data[row][col]) == number)
			{
				// mark number as played
				std::get<1>(card.data[row][col]) = true;
				found = true;
			}
			if (found)
			{
				break;
			}
		}
		if (found)
		{
			break;
		}
	}

	if (!found)
	{
		return false;
	}

	// check row of number
	bool bingo = true;
	for (size_t i = 0; i < card.data[row].size(); i++)
	{
		bingo &= std::get<1>(card.data[row][i]);
	}

	if (bingo)
	{
		return bingo;
	}

	// check column of number
	bingo = true;
	for (size_t i = 0; i < card.data.size(); i++)
	{
		bingo &= std::get<1>(card.data[i][col]);
	}

	return bingo;
}