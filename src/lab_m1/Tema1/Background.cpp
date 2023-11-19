#include "Background.h"

Background::Background()
{
	base_squares[0] = Square(100, 20, 100, "square1");
	base_squares[1] = Square(250, 20, 100, "square1");
	base_squares[2] = Square(400, 20, 100, "square1");
	base_squares[3] = Square(100, 170, 100, "square1");
	base_squares[4] = Square(250, 170, 100, "square1");
	base_squares[5] = Square(400, 170, 100, "square1");
	base_squares[6] = Square(100, 320, 100, "square1");
	base_squares[7] = Square(250, 320, 100, "square1");
	base_squares[8] = Square(400, 320, 100, "square1");

	rhombus_squares[0] = Square(30, 600, 100, "square2");
	rhombus_squares[1] = Square(180, 600, 100, "square2");
	rhombus_squares[2] = Square(330, 600, 100, "square2");
	rhombus_squares[3] = Square(480, 600, 100, "square2");

	rhombuses[0] = Rhombus(rhombus_squares[0].getX() + 45, rhombus_squares[0].getY() + 50, 1, "rhombus_orange", "orange", 23.0f);
	rhombuses[1] = Rhombus(rhombus_squares[1].getX() + 45, rhombus_squares[1].getY() + 50, 2, "rhombus_blue", "blue", 23.0f);
	rhombuses[2] = Rhombus(rhombus_squares[2].getX() + 45, rhombus_squares[2].getY() + 50, 2, "rhombus_yellow", "yellow", 23.0f);
	rhombuses[3] = Rhombus(rhombus_squares[3].getX() + 45, rhombus_squares[3].getY() + 50, 3, "rhombus_purple", "purple", 23.0f);

	stars[0] = Star(rhombus_squares[0].getX() + 5, rhombus_squares[0].getY() - 20);
	stars[1] = Star(rhombus_squares[1].getX() + 5, rhombus_squares[1].getY() - 20);
	stars[2] = Star(rhombus_squares[1].getX() + 50, rhombus_squares[1].getY() - 20);
	stars[3] = Star(rhombus_squares[2].getX() + 5, rhombus_squares[2].getY() - 20);
	stars[4] = Star(rhombus_squares[2].getX() + 50, rhombus_squares[2].getY() - 20);
	stars[5] = Star(rhombus_squares[3].getX() + 5, rhombus_squares[3].getY() - 20);
	stars[6] = Star(rhombus_squares[3].getX() + 50, rhombus_squares[3].getY() - 20);
	stars[7] = Star(rhombus_squares[3].getX() + 95, rhombus_squares[3].getY() - 20);

	base_rectangle = Rectangle(0, 20, 50, 400, "rectangle1");
}

Background::~Background()
{
}