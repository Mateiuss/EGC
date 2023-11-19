#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateRectangle(
	const std::string &name,
	glm::vec3 leftBottomCorner,
	float length,
	float width,
	glm::vec3 color,
	bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, width, 0), color),
		VertexFormat(corner + glm::vec3(0, width, 0), color)
	};

	Mesh* rectangle = new Mesh(name);
	std::vector<unsigned int> indices = { 0, 1, 2, 3 };

	if (!fill) {
		rectangle->SetDrawMode(GL_LINE_LOOP);
	} else {
		// Draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	rectangle->InitFromData(vertices, indices);
	return rectangle;
}

Mesh* object2D::CreateRhombus(
	const std::string &name,
	glm::vec3 color
	)
{
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(0, 2, 1), color),
		VertexFormat(glm::vec3(-1, 0, 1), color),
		VertexFormat(glm::vec3(0, -2, 1), color),
		VertexFormat(glm::vec3(0.75f, -0.5f, 1), color),
		VertexFormat(glm::vec3(0.75f, 0.5f, 1), color),
		VertexFormat(glm::vec3(2, 0.5f, 1), color),
		VertexFormat(glm::vec3(2, -0.5f, 1), color),
	};

	Mesh* rhombus = new Mesh(name);
	std::vector<unsigned int> indices = {
		0, 1, 4,
		4, 1, 3,
		3, 1, 2,
		5, 4, 3,
		5, 3, 6
	};

	rhombus->SetDrawMode(GL_TRIANGLES);

	rhombus->InitFromData(vertices, indices);
	return rhombus;
}

Mesh* object2D::CreateStar(
	const std::string& name,
	glm::vec3 color
	)
{
	glm::vec3 corner = glm::vec3(0, 0, 0);

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(0, 1, 3), color),
		VertexFormat(glm::vec3(-0.3f, 0.2f, 3), color),
		VertexFormat(glm::vec3(0.3f, 0.2f, 3), color),
		VertexFormat(glm::vec3(-1, 0.2f, 3), color),
		VertexFormat(glm::vec3(1, 0.2f, 3), color),
		VertexFormat(glm::vec3(-0.5f, -0.3f, 3), color),
		VertexFormat(glm::vec3(0.5, -0.3f, 3), color),
		VertexFormat(glm::vec3(0, -0.6f, 3), color),
		VertexFormat(glm::vec3(-0.7f, -1, 3), color),
		VertexFormat(glm::vec3(0.7, -1, 3), color)
	};

	Mesh* star = new Mesh(name);
	std::vector<unsigned int> indices = {
		2, 0, 1,
		5, 1, 3,
		4, 2, 6,
		5, 2, 1,
		6, 2, 5,
		9, 6, 5,
		7, 5, 8,
		9, 6, 7
	};

	star->SetDrawMode(GL_TRIANGLES);
	
	star->InitFromData(vertices, indices);
	return star;
}

Mesh* object2D::CreateHexagon(
	const std::string& name,
	glm::vec3 color,
	float depth
	)
{
	glm::vec3 corner = glm::vec3(0, 0, 0);

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(-1, 0, depth), color),
		VertexFormat(glm::vec3(-0.5f, 0.86f, depth), color),
		VertexFormat(glm::vec3(0.5f, 0.86f, depth), color),
		VertexFormat(glm::vec3(1, 0, depth), color),
		VertexFormat(glm::vec3(0.5f, -0.86f, depth), color),
		VertexFormat(glm::vec3(-0.5f, -0.86f, depth), color)
	};

	Mesh* hexagon = new Mesh(name);
	std::vector<unsigned int> indices = {
		5, 1, 2,
		2, 5, 4,
		1, 0, 5,
		3, 2, 4
	};

	hexagon->SetDrawMode(GL_TRIANGLES);

	hexagon->InitFromData(vertices, indices);
	return hexagon;
}

Mesh* object2D::CreateCircle(
	const std::string& name,
	glm::vec3 color,
	float radius
)
{
	glm::vec3 corner = glm::vec3(0, 0, 0);

	std::vector<VertexFormat> vertices;

	for (int i = 0; i < 360; i++) {
		vertices.push_back(VertexFormat(glm::vec3(radius * cos(i * M_PI / 180), radius * sin(i * M_PI / 180), 1), color));
	}

	Mesh* circle = new Mesh(name);
	std::vector<unsigned int> indices;

	for (int i = 0; i < 360; i++) {
		indices.push_back(i);
	}

	circle->SetDrawMode(GL_TRIANGLE_FAN);

	circle->InitFromData(vertices, indices);
	return circle;
}

Mesh* object2D::CreateHeartFill(
	const std::string& name,
	glm::vec3 color
)
{
	std::vector<VertexFormat> vertices = {
		VertexFormat(glm::vec3(-1.55f, -0.87f, 3), color),
		VertexFormat(glm::vec3(0, -2.5f, 3), color),
		VertexFormat(glm::vec3(1.55f, -0.87f, 3), color),
		VertexFormat(glm::vec3(0, 0, 3), color)
	};

	Mesh* heart = new Mesh(name);

	std::vector<unsigned int> indices = {
		0, 1, 2,
		3, 0, 2
	};

	heart->SetDrawMode(GL_TRIANGLES);
	heart->InitFromData(vertices, indices);
	return heart;
}
