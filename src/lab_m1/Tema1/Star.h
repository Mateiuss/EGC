#pragma once
#include <string>

class Star
{
public:
	Star();
	Star(int x, int y);
	Star(int x, int y, std::string meshName);
	Star(int x, int y, std::string meshName, float scale);
	Star(int x, int y, std::string meshName, float scale, std::string color);
	~Star();
	void setX(int x);
	void setY(int y);
	void setAngle(float angle);
	int getX();
	int getY();
	std::string getColor();
	float getAngle();
	float getScale();
	std::string getMeshName();
	bool inStar(int x, int y);
private:
	int x, y;
	float scale;
	float angle;
	std::string meshName;
	std::string color;
};

