#pragma once
#include "lab_m1/Tema1/Rhombus.h"
#include "lab_m1/Tema1/Square.h"
#include "lab_m1/Tema1/Star.h"
#include "lab_m1/Tema1/Rectangle.h"

class Background
{
public:
	Background();
	~Background();

	Star stars[8];
	Rhombus rhombuses[4];
	Rhombus playingRhombuses[9];
	Square base_squares[9];
	Square rhombus_squares[4];
	Rectangle base_rectangle;
};

