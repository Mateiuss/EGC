#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
    background = Background();
    selectedRhombus = nullptr;
    lives = {
        Heart(735, 665, 17, "circle", "heart_fill"),
        Heart(835, 665, 17, "circle", "heart_fill"),
        Heart(935, 665, 17, "circle", "heart_fill")
    };
    starTime = 0;
    hexagonTime = 0;
    rombusTime = 0;
    gameTime = 0;
    nrOfSpawningStars = 3;

    randomHexTime = 5;
    randomRombusTime = 3;

    enemySpawnPoints[0][0] = 1320;
    enemySpawnPoints[0][1] = 70;
    enemySpawnPoints[1][0] = 1320;
    enemySpawnPoints[1][1] = 220;
    enemySpawnPoints[2][0] = 1320;
    enemySpawnPoints[2][1] = 370;

    hexagon_types[0] = Hexagon(0, 0, "orange_hexagon", 30, 40, "orange");
    hexagon_types[1] = Hexagon(0, 0, "blue_hexagon", 30, 40, "blue");
    hexagon_types[2] = Hexagon(0, 0, "yellow_hexagon", 30, 40, "yellow");
    hexagon_types[3] = Hexagon(0, 0, "purple_hexagon", 30, 40, "purple");
}



Tema1::~Tema1()
{
}


void Tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    float squareSide = 100;

    Mesh* square1 = object2D::CreateSquare("square1", corner, squareSide, glm::vec3(0, 1, 0), true);
    AddMeshToList(square1);

    Mesh* square2 = object2D::CreateSquare("square2", corner, squareSide, glm::vec3(0, 0, 0));
    AddMeshToList(square2);

    Mesh* red_square = object2D::CreateSquare("red_square", corner, 75, glm::vec3(1, 0, 0), true);
    AddMeshToList(red_square);

    Mesh* rectangle1 = object2D::CreateRectangle("rectangle1", corner, 50.0f, 400.0f, glm::vec3(1, 0, 0), true);
    AddMeshToList(rectangle1);

    Mesh* rhombus1 = object2D::CreateRhombus("rhombus_orange", glm::vec3(1.0f, 0.64f, 0.0f));
    AddMeshToList(rhombus1);

    Mesh* rhombus2 = object2D::CreateRhombus("rhombus_blue", glm::vec3(0.0f, 0.0f, 1.0f));
    AddMeshToList(rhombus2);

    Mesh* rhombus3 = object2D::CreateRhombus("rhombus_yellow", glm::vec3(1.0f, 1.0f, 0.0f));
    AddMeshToList(rhombus3);

    Mesh* rhombus4 = object2D::CreateRhombus("rhombus_purple", glm::vec3(0.5f, 0.0f, 0.5f));
    AddMeshToList(rhombus4);

    Mesh* star = object2D::CreateStar("star", glm::vec3(0.5f, 0.5f, 0.5f));
    AddMeshToList(star);

    Mesh* pink_star = object2D::CreateStar("pink_star", glm::vec3(1.0f, 0.0f, 1.0f));
    AddMeshToList(pink_star);

    Mesh* hexagon = object2D::CreateHexagon("green_hexagon", glm::vec3(0.0f, 1.0f, 0.0f), 2);
    AddMeshToList(hexagon);

    Mesh* hexagon2 = object2D::CreateHexagon("orange_hexagon", glm::vec3(1.0f, 0.64f, 0.0f), 1);
    AddMeshToList(hexagon2);

    Mesh* hexagon3 = object2D::CreateHexagon("blue_hexagon", glm::vec3(0.0f, 0.0f, 1.0f), 1);
    AddMeshToList(hexagon3);

    Mesh* hexagon4 = object2D::CreateHexagon("yellow_hexagon", glm::vec3(1.0f, 1.0f, 0.0f), 1);
    AddMeshToList(hexagon4);

    Mesh* hexagon5 = object2D::CreateHexagon("purple_hexagon", glm::vec3(0.5f, 0.0f, 0.5f), 1);
    AddMeshToList(hexagon5);

    Mesh* star1 = object2D::CreateStar("orange_star", glm::vec3(1.0f, 0.64f, 0.0f));
    AddMeshToList(star1);

    Mesh* star2 = object2D::CreateStar("blue_star", glm::vec3(0.0f, 0.0f, 1.0f));
    AddMeshToList(star2);

    Mesh* star3 = object2D::CreateStar("yellow_star", glm::vec3(1.0f, 1.0f, 0.0f));
    AddMeshToList(star3);

    Mesh* star4 = object2D::CreateStar("purple_star", glm::vec3(0.5f, 0.0f, 0.5f));
    AddMeshToList(star4);

    Mesh* circle = object2D::CreateCircle("circle", glm::vec3(1.0f, 0.0f, 0.0f), 1);
    AddMeshToList(circle);

    Mesh* heart_fill = object2D::CreateHeartFill("heart_fill", glm::vec3(1.0f, 0.0f, 0.0f));
    AddMeshToList(heart_fill);
}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0.35f, 0.35f, 0.35f, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);

    // Check if the player ran out of lives
    if (lives.size() == 0) {
		cout << "GAME OVER" << endl;
		exit(0);
	}

    // Render the squares on which the rhombuses can be placed
    for (int i = 0; i < 9; i++) {
        glm::mat3 modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(background.base_squares[i].getX(), background.base_squares[i].getY());
        RenderMesh2D(meshes[background.base_squares[i].getMeshName()], shaders["VertexColor"], modelMatrix);
    }

    // Render the shop rhombuses along with the outer line of the squares
    for (int i = 0; i < 4; i++) {
		glm::mat3 modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(background.rhombus_squares[i].getX(), background.rhombus_squares[i].getY());
        RenderMesh2D(meshes[background.rhombus_squares[i].getMeshName()], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(background.rhombuses[i].getX(), background.rhombuses[i].getY());
        modelMatrix *= transform2D::Scale(23.0f, 23.0f);
        RenderMesh2D(meshes[background.rhombuses[i].getMeshName()], shaders["VertexColor"], modelMatrix);
    }

    // Render the stars beneath the shop rhombuses
    for (int i = 0; i < 8; i++) {
		glm::mat3 modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(background.stars[i].getX(), background.stars[i].getY());
        modelMatrix *= transform2D::Scale(17.0f, 17.0f);
		RenderMesh2D(meshes["star"], shaders["VertexColor"], modelMatrix);
    }

    // Render the base rectangle
    glm::mat3 modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(background.base_rectangle.getX(), background.base_rectangle.getY());
    RenderMesh2D(meshes["rectangle1"], shaders["VertexColor"], modelMatrix);

    // Render dynamic objects
    renderLives();
    renderSelectedRhombus();
    renderRhombus();
    renderHexagon();
    renderCollectedStars();
    renderCollectableStars();
    renderShootingStars();
    renderDeletedRhombus();
    renderDeletedHexagon();
}


void Tema1::Update(float deltaTimeSeconds)
{
    gameTime += deltaTimeSeconds;

    if (gameTime >= 30) {
        nrOfSpawningStars = 2;
    }

    if (gameTime >= 60) {
		nrOfSpawningStars = 1;
	}

    // add new collectable stars
    starTime += deltaTimeSeconds;
    if (starTime >= randomRombusTime) {
        starTime = 0;

        randomRombusTime = rand() % 5 + 5;
        
        for (int i = 0; i < nrOfSpawningStars; i++) {
            collectableStars.push_back(Star(rand() % 1280, rand() % 720, "pink_star", 25));
        }  
    }

    // move the hexagons
    for (int i = 0; i < hexagons.size(); i++) {
        hexagons[i].setX(hexagons[i].getX() - 20 * deltaTimeSeconds);
    }

    hexagonTime += deltaTimeSeconds;

    // add new hexagons
    if (hexagonTime > randomHexTime) {
        hexagonTime = 0;

        randomHexTime = rand() % 3 + 3;

        int row = rand() % 3;
        int hexagonType = rand() % 4;

        Hexagon newHexagon = hexagon_types[hexagonType];
        newHexagon.setX(enemySpawnPoints[row][0]);
        newHexagon.setY(enemySpawnPoints[row][1]);

        hexagons.push_back(newHexagon);
    }

    for (int i = 0; i < hexagons.size(); i++) {
        // check collision between the hexagons and the rhombuses
        for (int j = 0; j < 9; j++) {
            if (background.playingRhombuses[j].getMeshName() == "") continue;

            glm::vec2 firstCenter = glm::vec2(background.playingRhombuses[j].getX(), background.playingRhombuses[j].getY());
            glm::vec2 secondCenter = glm::vec2(hexagons[i].getX(), hexagons[i].getY());

            float distance = glm::distance(firstCenter, secondCenter);
            float sumOfRadiuses = background.playingRhombuses[j].getScale() * 2 + hexagons[i].getMainScale();

            if (distance <= sumOfRadiuses) {
                deletedRhombus.push_back(background.playingRhombuses[j]);
				background.playingRhombuses[j] = Rhombus();
			}
        }

        // check collision between the hexagons and the base rectangle
        if (background.base_rectangle.inRectangle(hexagons[i].getX(), hexagons[i].getY())) {
            deletedHexagon.push_back(hexagons[i]);
            hexagons.erase(hexagons.begin() + i);
            lives.pop_back();
            i--;
        }
    }

    // check if the rhombus can shoot at an hexagon
    rombusTime += deltaTimeSeconds;
    if (rombusTime >= 2) {
        rombusTime = 0;

        for (int i = 0; i < 9; i++) {
			if (background.playingRhombuses[i].getMeshName() == "") continue;

            for (int j = 0; j < hexagons.size(); j++) {
                if (hexagons[j].getColor() == background.playingRhombuses[i].getColor() && hexagons[j].getY() == background.playingRhombuses[i].getY()) {
					shootingStars.push_back(Star(background.playingRhombuses[i].getX() + 30, background.playingRhombuses[i].getY(), background.playingRhombuses[i].getColor() + "_star", 25, background.playingRhombuses[i].getColor()));
                    break;
				}
			}
		}
    }

    for (int i = 0; i < shootingStars.size(); i++) {
        bool deleteStar = false;

        // check for collision of the shooting stars with the hexagons
        for (int j = 0; j < hexagons.size(); j++) {
            if (hexagons[j].getColor() != shootingStars[i].getColor()) continue;

            glm::vec2 firstCenter = glm::vec2(shootingStars[i].getX(), shootingStars[i].getY());
			glm::vec2 secondCenter = glm::vec2(hexagons[j].getX(), hexagons[j].getY());

			float distance = glm::distance(firstCenter, secondCenter);
			float sumOfRadiuses = shootingStars[i].getScale() + hexagons[j].getMainScale();

			if (distance <= sumOfRadiuses) {
                deleteStar = true;
                hexagons[j].setLives(hexagons[j].getLives() - 1);
                if (hexagons[j].getLives() == 0) {
                    deletedHexagon.push_back(hexagons[j]);
                    hexagons.erase(hexagons.begin() + j);
                }

                break;
            }
        }

        // check if the star colided with a hexagon or has left the screen
        if (deleteStar || shootingStars[i].getX() > 1280) {
            shootingStars.erase(shootingStars.begin() + i);
            i--;
            continue;
        }

        // rotate the star
        shootingStars[i].setAngle(shootingStars[i].getAngle() - 5 * deltaTimeSeconds);
        shootingStars[i].setX(shootingStars[i].getX() + 200 * deltaTimeSeconds);
    }

    // shrink the deleted rhombuses
    for (int i = 0; i < deletedRhombus.size(); i++) {
        deletedRhombus[i].setScale(deletedRhombus[i].getScale() - 23.f * deltaTimeSeconds);
    }

    // shrink the deleted hexagons
    for (int i = 0; i < deletedHexagon.size(); i++) {
        deletedHexagon[i].setMainScale(deletedHexagon[i].getMainScale() - 30.f * deltaTimeSeconds);
        deletedHexagon[i].setColorScale(deletedHexagon[i].getColorScale() - 40.f * deltaTimeSeconds);
    }
}


void Tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    if (selectedRhombus) {
		selectedRhombus->setX(mouseX);
		selectedRhombus->setY(720 - mouseY);
	}
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_3) {
        for (int i = 0; i < 9; i++) {
			if (background.base_squares[i].inSquare(mouseX, 720 - mouseY) && background.playingRhombuses[i].getMeshName() != "") {
                deletedRhombus.push_back(background.playingRhombuses[i]);
                background.playingRhombuses[i] = Rhombus();
            }
        }

        return;
    }

    if (button != GLFW_MOUSE_BUTTON_2) return;

    for (int i = 0; i < 4; i++) {
        if (background.rhombus_squares[i].inSquare(mouseX, 720 - mouseY) && collectedStars.size() >= background.rhombuses[i].getPrice()) {
			selectedRhombus = new Rhombus(mouseX, 720 - mouseY, background.rhombuses[i].getPrice(), background.rhombuses[i].getMeshName(), background.rhombuses[i].getColor(), background.rhombuses[i].getScale());
			break;
		}
    }

    for (int i = 0; i < collectableStars.size(); i++) {
        if (collectableStars[i].inStar(mouseX, 720 - mouseY)) {
			collectableStars.erase(collectableStars.begin() + i);
            
            if (collectedStars.size() == 0) {
				collectedStars.push_back(Star(635, 580, "star", 17));
			}
            else {
                int x = collectedStars[collectedStars.size() - 1].getX();
                int y = collectedStars[collectedStars.size() - 1].getY();

                if (x + 55 > 1280) {
					collectedStars.push_back(Star(635, y - 40, "star", 17));
				}
                else {
					collectedStars.push_back(Star(x + 40, y, "star", 17));
				}
            }
			break;
		}
	}
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    if (!selectedRhombus) return;

    for (int i = 0; i < 9; i++) {
        if (background.base_squares[i].inSquare(mouseX, 720 - mouseY) && background.playingRhombuses[i].getMeshName() == "") {
            background.playingRhombuses[i] = *selectedRhombus;
            background.playingRhombuses[i].setX(background.base_squares[i].getX() + 45);
            background.playingRhombuses[i].setY(background.base_squares[i].getY() + 50);
            background.playingRhombuses[i].setScale(23.0f);

            for (int i = 0; i < selectedRhombus->getPrice(); i++) {
                collectedStars.pop_back();
            }

            delete selectedRhombus;
            selectedRhombus = nullptr;
            return;
        }
    }

    delete selectedRhombus;
    selectedRhombus = nullptr;
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}

void Tema1::renderLives() {
    for (auto life : lives) {
        glm::mat3 modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(life.getX() - life.getScale(), life.getY());
        modelMatrix *= transform2D::Scale(life.getScale(), life.getScale());
        RenderMesh2D(meshes[life.getCircleMesh()], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(life.getX() + life.getScale(), life.getY());
        modelMatrix *= transform2D::Scale(life.getScale(), life.getScale());
        RenderMesh2D(meshes[life.getCircleMesh()], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(life.getX(), life.getY());
        modelMatrix *= transform2D::Scale(life.getScale(), life.getScale());
        RenderMesh2D(meshes[life.getHeartFillMesh()], shaders["VertexColor"], modelMatrix);
    }
}

void Tema1::renderSelectedRhombus() {
    if (selectedRhombus) {
		glm::mat3 modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(selectedRhombus->getX(), selectedRhombus->getY());
		modelMatrix *= transform2D::Scale(selectedRhombus->getScale(), selectedRhombus->getScale());
		RenderMesh2D(meshes[selectedRhombus->getMeshName()], shaders["VertexColor"], modelMatrix);
	}
}

void Tema1::renderRhombus() {
    for (int i = 0; i < 9; i++) {
        if (background.playingRhombuses[i].getMeshName() != "") {
            glm::mat3 modelMatrix = glm::mat3(1);
            modelMatrix *= transform2D::Translate(background.playingRhombuses[i].getX(), background.playingRhombuses[i].getY());
            modelMatrix *= transform2D::Scale(23.0f, 23.0f);
            RenderMesh2D(meshes[background.playingRhombuses[i].getMeshName()], shaders["VertexColor"], modelMatrix);
        }
    }
}

void Tema1::renderHexagon() {
    for (auto hexagon : hexagons) {
        glm::mat3 modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(hexagon.getX(), hexagon.getY());
        modelMatrix *= transform2D::Scale(hexagon.getMainScale(), hexagon.getMainScale());
        RenderMesh2D(meshes["green_hexagon"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(hexagon.getX(), hexagon.getY());
        modelMatrix *= transform2D::Scale(hexagon.getColorScale(), hexagon.getColorScale());
        RenderMesh2D(meshes[hexagon.getColorMesh()], shaders["VertexColor"], modelMatrix);
    }
}

void Tema1::renderCollectedStars() {
    for (auto star : collectedStars) {
        glm::mat3 modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(star.getX(), star.getY());
        modelMatrix *= transform2D::Scale(star.getScale(), star.getScale());
        RenderMesh2D(meshes[star.getMeshName()], shaders["VertexColor"], modelMatrix);
    }
}

void Tema1::renderCollectableStars() {
    for (auto star : collectableStars) {
        glm::mat3 modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(star.getX(), star.getY());
        modelMatrix *= transform2D::Scale(star.getScale(), star.getScale());
        RenderMesh2D(meshes[star.getMeshName()], shaders["VertexColor"], modelMatrix);
    }
}

void Tema1::renderShootingStars() {
    for (int i = 0; i < shootingStars.size(); i++) {
        glm::mat3 modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(shootingStars[i].getX(), shootingStars[i].getY());
        modelMatrix *= transform2D::Scale(shootingStars[i].getScale(), shootingStars[i].getScale());
        modelMatrix *= transform2D::Rotate(shootingStars[i].getAngle());
        RenderMesh2D(meshes[shootingStars[i].getMeshName()], shaders["VertexColor"], modelMatrix);
    }
}

void Tema1::renderDeletedRhombus() {
    for (int i = 0; i < deletedRhombus.size(); i++) {
        glm::mat3 modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(deletedRhombus[i].getX(), deletedRhombus[i].getY());
        modelMatrix *= transform2D::Scale(deletedRhombus[i].getScale(), deletedRhombus[i].getScale());
        RenderMesh2D(meshes[deletedRhombus[i].getMeshName()], shaders["VertexColor"], modelMatrix);

        if (deletedRhombus[i].getScale() <= 0.1) {
            deletedRhombus.erase(deletedRhombus.begin() + i);
            i--;
        }
    }
}

void Tema1::renderDeletedHexagon() {
    for (int i = 0; i < deletedHexagon.size(); i++) {
        glm::mat3 modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(deletedHexagon[i].getX(), deletedHexagon[i].getY());
        modelMatrix *= transform2D::Scale(deletedHexagon[i].getMainScale(), deletedHexagon[i].getMainScale());
        RenderMesh2D(meshes["green_hexagon"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(deletedHexagon[i].getX(), deletedHexagon[i].getY());
        modelMatrix *= transform2D::Scale(deletedHexagon[i].getColorScale(), deletedHexagon[i].getColorScale());
        RenderMesh2D(meshes[deletedHexagon[i].getColorMesh()], shaders["VertexColor"], modelMatrix);

        if (deletedHexagon[i].getMainScale() <= 0.1) {
            deletedHexagon.erase(deletedHexagon.begin() + i);
            i--;
        }
    }
}
