#include "pch.h"
#include "../BaseballGame/baseball.cpp"

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar) {
	baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}
