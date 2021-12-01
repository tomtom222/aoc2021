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
