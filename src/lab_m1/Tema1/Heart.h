#pragma once
#include <string>

class Heart
{
public:
	Heart();
	Heart(int x, int y, float scale, std::string circleMesh, std::string heartFillMesh);
	~Heart();
	void setX(int x);
	void setY(int y);
	void setScale(float scale);
	int getX();
	int getY();
	float getScale();
	std::string getCircleMesh();
	std::string getHeartFillMesh();

private:
	int x, y;
	float scale;
	std::string circleMesh;
	std::string heartFillMesh;
};

