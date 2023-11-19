#include "Star.h"

Star::Star()
{
	this->meshName = "";
	this->x = 0;
	this->angle = 0;
}

Star::Star(int x, int y) {
	this->x = x;
	this->y = y;
	this->angle = 0;
}

Star::Star(int x, int y, std::string meshName) {
	this->x = x;
	this->y = y;
	this->meshName = meshName;
	this->angle = 0;
}

Star::Star(int x, int y, std::string meshName, float scale) {
	this->x = x;
	this->y = y;
	this->meshName = meshName;
	this->scale = scale;
	this->angle = 0;
}

Star::Star(int x, int y, std::string meshName, float scale, std::string color) {
	this->x = x;
	this->y = y;
	this->meshName = meshName;
	this->scale = scale;
	this->color = color;
	this->angle = 0;
}

Star::~Star()
{
}

void Star::setX(int x) {
	this->x = x;
}

void Star::setY(int y) {
	this->y = y;
}

void Star::setAngle(float angle) {
	this->angle = angle;
}

int Star::getX() {
	return this->x;
}

int Star::getY() {
	return this->y;
}

std::string Star::getColor() {
	return this->color;
}

float Star::getAngle() {
	return this->angle;
}

std::string Star::getMeshName() {
	return this->meshName;
}

float Star::getScale() {
	return this->scale;
}

bool Star::inStar(int x, int y) {
	return x >= this->x - scale && x <= this->x + scale && y >= this->y - scale && y <= this->y + scale;
}