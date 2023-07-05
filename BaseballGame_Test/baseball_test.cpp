#include "pch.h"
#include "../BaseballGame/baseball.cpp"

class BaseballFixture: public testing::Test
{
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber)
	{
		try
		{
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e)
		{
			//PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvaidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}
