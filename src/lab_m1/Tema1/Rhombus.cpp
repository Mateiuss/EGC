#include "Rhombus.h"

Rhombus::Rhombus()
{
	this->x = 0;
	this->y = 0;
	this->meshName = "";
}

Rhombus::Rhombus(int x, int y, std::string meshName)
{
	this->x = x;
	this->y = y;
	this->meshName = meshName;
}

Rhombus::Rhombus(int x, int y, int price, std::string meshName)
{
	this->x = x;
	this->y = y;
	this->price = price;
	this->meshName = meshName;
}

Rhombus::Rhombus(int x, int y, int price, std::string meshName, std::string color)
{
	this->x = x;
	this->y = y;
	this->price = price;
	this->meshName = meshName;
	this->color = color;
}

Rhombus::Rhombus(int x, int y, int price, std::string meshName, std::string color, float scale)
{
	this->x = x;
	this->y = y;
	this->price = price;
	this->meshName = meshName;
	this->color = color;
	this->scale = scale;
}

Rhombus::~Rhombus()
{
}

std::string Rhombus::getColor() {
	return this->color;
}

std::string Rhombus::getMeshName() {
	return this->meshName;
}

int Rhombus::getX() {
	return this->x;
}

int Rhombus::getY() {
	return this->y;
}

float Rhombus::getScale() {
	return this->scale;
}

int Rhombus::getPrice() {
	return this->price;
}

void Rhombus::setX(int x) {
	this->x = x;
}

void Rhombus::setY(int y) {
	this->y = y;
}

void Rhombus::setScale(float scale) {
	this->scale = scale;
}

