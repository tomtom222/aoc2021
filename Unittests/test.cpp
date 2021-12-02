#include "pch.h"

#include "Types.h"
#include "StaticFunctions.h"


TEST(Day01, SonarSweep)
{
	std::vector<uint> test = {199,200,208,210,200,207,240,269,260,263};
	
	EXPECT_EQ(Functions::slidingSonarSweep(test), 7u);
	EXPECT_EQ(Functions::slidingSonarSweep(test,2), 5u);
	EXPECT_EQ(Functions::slidingSonarSweep(test,3), 5u);
	EXPECT_EQ(Functions::slidingSonarSweep(test,4), 6u);
	EXPECT_EQ(Functions::slidingSonarSweep(test,5), 5u);
	EXPECT_EQ(Functions::slidingSonarSweep(test,6), 4u);
	EXPECT_EQ(Functions::slidingSonarSweep(test,7), 3u);
	EXPECT_EQ(Functions::slidingSonarSweep(test,8), 2u);
	EXPECT_EQ(Functions::slidingSonarSweep(test,9), 1u);
}

TEST(Day02, Diving)
{
	std::vector<DiveInstruction> test =
	{
		DiveInstruction(DiveCommand::forward, 5),
		DiveInstruction(DiveCommand::down, 5),
		DiveInstruction(DiveCommand::forward, 8),
		DiveInstruction(DiveCommand::up, 3),
		DiveInstruction(DiveCommand::down, 8),
		DiveInstruction(DiveCommand::forward, 2),
	};

	EXPECT_EQ(Functions::processDiveInstructions(test), 150u);
	EXPECT_EQ(Functions::processDiveInstructionsWithAim(test), 900u);
}