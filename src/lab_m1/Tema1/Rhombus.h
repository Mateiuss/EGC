#pragma once
#include <string>

class Rhombus
{
	public:
	Rhombus();
	Rhombus(int x, int y, std::string meshName);
	Rhombus(int x, int y, int price, std::string meshName);
	Rhombus(int x, int y, int price, std::string meshName, std::string color);
	Rhombus(int x, int y, int price, std::string meshName, std::string color, float scale);
	~Rhombus();

	std::string getMeshName();
	int getX();
	int getY();
	int getPrice();
	float getScale();
	std::string getColor();

	void setX(int x);
	void setY(int y);
	void setScale(float scale);

	private:
		int x, y;
		int price;
		float scale;
		std::string meshName;
		std::string color;
};

