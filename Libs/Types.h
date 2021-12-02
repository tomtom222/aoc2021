#pragma once
#include <tuple>

typedef unsigned int uint;

enum class DiveCommand : uint
{
	forward,
	down,
	up,
};
typedef std::tuple<DiveCommand, uint> DiveInstruction;