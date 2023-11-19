#include "Square.h"

Square::Square()
{
	this->x = 0;
	this->y = 0;
	this->side = 0;
}

Square::Square(int x, int y, std::string meshName)
{
	this->x = x;
	this->y = y;
	this->mesh_name = meshName;
}

Square::Square(int x, int y, int side, std::string meshName)
{
	this->x = x;
	this->y = y;
	this->side = side;
	this->mesh_name = meshName;
}

Square::~Square()
{
}

int Square::getX()
{
	return this->x;
}

int Square::getY()
{
	return this->y;
}

int Square::getSide()
{
	return this->side;
}

std::string Square::getMeshName()
{
	return this->mesh_name;
}

void Square::setX(int x)
{
	this->x = x;
}

void Square::setY(int y)
{
	this->y = y;
}

void Square::setSide(int side)
{
	this->side = side;
}

void Square::setMeshName(std::string meshName)
{
	this->mesh_name = meshName;
}

bool Square::inSquare(int x, int y) {
	return x >= this->x && x <= this->x + this->side && y >= this->y && y <= this->y + this->side;
}
