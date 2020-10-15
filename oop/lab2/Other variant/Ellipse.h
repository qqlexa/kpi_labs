#ifndef UNTITLED_PRODUCT_H
#define UNTITLED_PRODUCT_H
#include <string>

class Ellipse
{
private:
	std::string name_;
	float radius1_, radius2_;
	float x_, y_;
	float square_;

public:
	Ellipse();
	Ellipse(std::string name);
	Ellipse(std::string name, float x, float y, float radius1 = 0, float radius2 = 0);
	Ellipse(std::string name, float x, float y, float radius1, float radius2, float square);
	Ellipse(const Ellipse&);
	~Ellipse();

	void setName(std::string);
	std::string getName();
	void printName();

	void setRadiusses(float radius1 = 1.0, float radius2 = 1.0);
	void setRadius1(float);
	void setRadius2(float);
	float getRadius1();
	float getRadius2();
	void printRadiusses();

	void setX(float x);
	float getX();

	void printX();
	void setY(float y);

	void setCenter(float, float);

	float getY();
	void printY();

	void setSquare(float);
	float getSquare();
	void printSquare();
	float countSquare();

	Ellipse operator+(const Ellipse&);
	bool operator>(const Ellipse&);
	bool operator<(const Ellipse&);
	bool operator==(const Ellipse&);
	bool operator>=(const Ellipse&);
	bool operator<=(const Ellipse&);

	Ellipse& operator++();
	Ellipse operator++(int);
	Ellipse& operator--();
	Ellipse operator--(int);

private:
	// value checks
	bool checkName();
	bool checkRadiusses();
	bool checkRadius1();
	bool checkRadius2();
	bool checkX();
	bool checkY();
	bool checkSquare();
	void checkIntegrity();
};

#endif