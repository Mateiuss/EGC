#pragma once
#include <string>

class Square
{
private:
	int x, y;
	int side;
	std::string mesh_name;

public:
	Square();
	Square(int x, int y, std::string mesh_name);
	Square(int x, int y, int side, std::string mesh_name);
	~Square();

	int getX();
	int getY();
	int getSide();
	std::string getMeshName();

	void setX(int x);
	void setY(int y);
	void setMeshName(std::string mesh_name);
	void setSide(int side);

	bool inSquare(int x, int y);
};
