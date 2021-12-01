#include "pch.h"

#include "Types.h"
#include "StaticFunctions.h"


TEST(SonarSweep, Day01)
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