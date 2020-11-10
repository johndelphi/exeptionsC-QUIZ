#include <iostream>
#include <cmath> //for value of pi
#include "InvalidRadiusThrow.h" //for radius exception
using namespace std;

template <class T>
class Circle
{
private:
	T radius;

public:
	Circle() //default constructor
	{
		radius = 1;
	}

	Circle(T r) //parameterized constructor
	{
		setRadius(r);
	}

	void setRadius(T r) //function to set radius of the circle
	{
		try
		{
			if (r >= 1 && r <= 1000) //check validity
				radius = r;
			else
				throw InvalidRadiusThrow(); //throw exception
		}
		catch (InvalidRadiusThrow& e)
		{
			cout << e.what(); //display the exception
		}
	}

	void getRadius() const //function to get radius
	{
		return radius;
	}

	T calcPerimeter() const;
	T calcArea() const;
};

template<class T>
T Circle<T>::calcPerimeter() const //function to calculate perimeter
{
	T perimeter;
	perimeter = 2 * 3.14159 * radius;
	return perimeter; //return the perimeter
}

template<class T> //function to calculate area
T Circle<T>::calcArea() const
{
	T area;
	area = 3.14159 * radius * radius;
	return area; //return the area
}

int main()
{
	Circle<double> c1(5.0);
	cout << c1.calcPerimeter() << " " << c1.calcArea() << "\n";

	Circle<int> c2;
	c2.setRadius(5);
	cout << c2.calcPerimeter() << " " << c2.calcArea() << "\n";

	Circle<float> c3;
	c3.setRadius(-1); //will throw exception
	cout << c3.calcPerimeter() << " " << c3.calcArea() << "\n"; //result will be printed for default radius 1
	return 0;
}
//HEADER FILE "InvalidRadiusThrow.h" IS BELOW

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