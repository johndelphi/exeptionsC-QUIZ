
#include <iostream>
#include <exception>
using namespace std;

class InvalidRadiusThrow : public exception
{
public:
	const char* what() const throw ()
	{
		return "Invalid circle radius.\n";
	}
};