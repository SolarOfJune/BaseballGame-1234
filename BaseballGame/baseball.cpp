#include <stdexcept>
using namespace std;

class baseball
{
public:
	void guess(const string& string)
	{
		throw length_error("Must be three letters.");
	}
};