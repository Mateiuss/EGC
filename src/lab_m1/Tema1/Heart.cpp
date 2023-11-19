#include "lab_m1/Tema1/Heart.h"

Heart::Heart()
{
}

Heart::Heart(int x, int y, float scale, std::string circleMesh, std::string heartFillMesh)
{
	this->x = x;
	this->y = y;
	this->scale = scale;
	this->circleMesh = circleMesh;
	this->heartFillMesh = heartFillMesh;
}

Heart::~Heart()
{
}

void Heart::setX(int x)
{
	this->x = x;
}

void Heart::setY(int y)
{
	this->y = y;
}

void Heart::setScale(float scale)
{
	this->scale = scale;
}

int Heart::getX()
{
	return x;
}

int Heart::getY()
{
	return y;
}

float Heart::getScale()
{
	return scale;
}

std::string Heart::getCircleMesh()
{
	return circleMesh;
}

std::string Heart::getHeartFillMesh()
{
	return heartFillMesh;
}