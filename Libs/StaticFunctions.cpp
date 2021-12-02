#include "StaticFunctions.h"
#include "Types.h"

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
