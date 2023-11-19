#pragma once
#include "Hexagon.h"
#include <string>

class Hexagon
{
public:
	Hexagon();
	Hexagon(int x, int y, std::string colorMesh, float mainScale, float colorScale);
	Hexagon(int x, int y, std::string colorMesh, float mainScale, float colorScale, std::string color);
	~Hexagon();

	void setX(int x);
	void setY(int y);
	void setLives(int lives);
	void setMainScale(float mainScale);
	void setColorScale(float colorScale);

	int getX();
	int getY();
	int getLives();
	std::string getColor();
	float getMainScale();
	float getColorScale();

	std::string getColorMesh();

private:
	int x, y;
	float mainScale, colorScale;
	int lives;
	std::string colorMesh;
	std::string color;
};

