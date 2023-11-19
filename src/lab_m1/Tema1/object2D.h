#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateSquare(const std::string &name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateRectangle(const std::string &name, glm::vec3 leftBottomCorner, float length, float width, glm::vec3 color, bool fill = false);
    Mesh* CreateRhombus(const std::string &name, glm::vec3 color);
    Mesh* CreateStar(const std::string &name, glm::vec3 color);
    Mesh* CreateHexagon(const std::string &name, glm::vec3 color, float depth);
    Mesh* CreateCircle(const std::string &name, glm::vec3 color, float radius);
    Mesh* CreateHeartFill(const std::string &name, glm::vec3 color);
}
