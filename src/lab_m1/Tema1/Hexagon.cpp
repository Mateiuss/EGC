#include "Hexagon.h"

Hexagon::Hexagon()
{
	this->x = 0;
	this->y = 0;
	this->colorMesh = "";
}

Hexagon::Hexagon(int x, int y, std::string colorMesh, float mainScale, float colorScale) {
	this->x = x;
	this->y = y;
	this->colorMesh = colorMesh;
	this->mainScale = mainScale;
	this->colorScale = colorScale;
	this->lives = 3;
}

Hexagon::Hexagon(int x, int y, std::string colorMesh, float mainScale, float colorScale, std::string color) {
	this->x = x;
	this->y = y;
	this->colorMesh = colorMesh;
	this->mainScale = mainScale;
	this->colorScale = colorScale;
	this->color = color;
	this->lives = 3;
}

Hexagon::~Hexagon()
{
}

void Hexagon::setX(int x) {
	this->x = x;
}

void Hexagon::setY(int y) {
	this->y = y;
}

void Hexagon::setLives(int lives) {
	this->lives = lives;
}

void Hexagon::setMainScale(float mainScale) {
	this->mainScale = mainScale;
}

void Hexagon::setColorScale(float colorScale) {
	this->colorScale = colorScale;
}

int Hexagon::getLives() {
	return this->lives;
}

int Hexagon::getX() {
	return this->x;
}

int Hexagon::getY() {
	return this->y;
}

std::string Hexagon::getColor() {
	return this->color;
}

float Hexagon::getMainScale() {
	return this->mainScale;
}

float Hexagon::getColorScale() {
	return this->colorScale;
}

std::string Hexagon::getColorMesh() {
	return this->colorMesh;
}


