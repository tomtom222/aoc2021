#pragma once
#include "Types.h"
#include <vector>

class Functions
{
public:
	static const uint slidingSonarSweep(const std::vector<uint>& vec, const uint window = 1u);
};
