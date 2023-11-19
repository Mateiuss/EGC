#pragma once
#include "string"

class Rectangle
{
public:
	Rectangle();
	Rectangle(int x, int y, int width, int height, std::string meshName);
	~Rectangle();

	int getX();
	int getY();
	int getWidth();
	int getHeight();
	std::string getMeshName();

	void setX(int x);
	void setY(int y);
	void setWidth(int width);
	void setHeight(int height);
	void setMeshName(std::string meshName);

	bool inRectangle(int x, int y);

private:
	int x, y;
	int width, height;
	std::string meshName;
};

