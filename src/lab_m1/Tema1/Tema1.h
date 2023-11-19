#pragma once

#include "components/simple_scene.h"
#include "lab_m1/Tema1/Background.h"
#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"
#include "lab_m1/Tema1/Hexagon.h"
#include "lab_m1/Tema1/Rectangle.h"

namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        Background background;
        Rhombus* selectedRhombus;
        Hexagon hexagon_types[4];
        std::vector<Square> lives;
        std::vector<Star> collectableStars;
        std::vector<Star> collectedStars;
        std::vector<Hexagon> hexagons;
        std::vector<Star> shootingStars;
        std::vector<Rhombus> deletedRhombus;
        std::vector<Hexagon> deletedHexagon;
        float starTime;
        float hexagonTime;
        float rombusTime;
        int enemySpawnPoints[3][2];
    };
}   // namespace m1
