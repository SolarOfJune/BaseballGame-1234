#include <stdexcept>
using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const string& question)
		: question(question)
	{
	}

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		if (guessNumber == question)
			return { true, 3, 0 };

		return { false, getStrikes(guessNumber), getBalls(guessNumber)};
	}

private:
	string question;

	bool isDuplicatedNumber(const string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
			throw length_error("Must be three letters.");

		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9')
				continue;
			throw invalid_argument("Must be number.");
		}

		if (isDuplicatedNumber(guessNumber))
		{
			throw invalid_argument("Must not have the same number.");
		}
	}

	int getStrikes(const string& guessNumber)
	{
		int strikes = 0;
		for (int n = 0; n < guessNumber.length(); n++)
		{
			if (guessNumber[n] == question[n])
				strikes++;
		}
		return strikes;
	}

	int getBalls(const string& guessNumber)
	{
		int balls = 0;
		for (int n = 0; n < guessNumber.length(); n++)
		{
			for (int m = 0; m < question.length(); m++)
			{
				if (n == m)
					continue;
				if (guessNumber[n] == question[m])
					balls++;
			}
		}
		return balls;
	}
};