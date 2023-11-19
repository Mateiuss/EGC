#include "Rectangle.h"

Rectangle::Rectangle()
{
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
	this->meshName = "";
}

Rectangle::Rectangle(int x, int y, int width, int height, std::string meshName)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->meshName = meshName;
}

Rectangle::~Rectangle()
{
}

int Rectangle::getX()
{
	return x;
}

int Rectangle::getY()
{
	return y;
}

int Rectangle::getWidth()
{
	return width;
}

int Rectangle::getHeight()
{
	return height;
}

std::string Rectangle::getMeshName()
{
	return meshName;
}

void Rectangle::setX(int x)
{
	this->x = x;
}

void Rectangle::setY(int y)
{
	this->y = y;
}

void Rectangle::setWidth(int width)
{
	this->width = width;
}

void Rectangle::setHeight(int height)
{
	this->height = height;
}

void Rectangle::setMeshName(std::string meshName)
{
	this->meshName = meshName;
}

bool Rectangle::inRectangle(int x, int y)
{
	return x >= this->x && x <= this->x + this->width && y >= this->y && y <= this->y + this->height;
}
