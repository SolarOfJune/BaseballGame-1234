#include <stdexcept>
using namespace std;

class baseball
{
public:
	void guess(const string& string)
	{
		if (string.length() != 3)
			throw length_error("Must be three letters.");
	}
};