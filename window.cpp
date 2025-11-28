#include "rlImGui/rlImGui.h"
#include <imgui.h>
#include <raylib.h>
#include <raymath.h>

int main() {
    int screenWidth = 1920 / 2;
    int screenHeight = 1080 / 2;
    bool showMessage = false;

    Vector2 circlePos = {100, 100};
    Vector2 targetPos = circlePos;

    InitWindow(screenWidth, screenHeight, "Physics Engine");
    rlImGuiSetup(true);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        float speed = 500.0f;
        float step = speed * dt;

        Vector2 direction = Vector2Subtract(targetPos, circlePos);
        float distance = Vector2Length(direction);

        if (distance <= step) {
            circlePos = targetPos;
        } else {
            Vector2 normalized = Vector2Scale(direction, 1.0 / distance);
            circlePos =
                Vector2Add(circlePos, Vector2Scale(normalized, speed * dt));
        }

        BeginDrawing();
        ClearBackground(BLACK);

        const float halfScreenWidth = GetScreenWidth() * 0.5f;
        const float halfScreenHeight = GetScreenHeight() * 0.5f;
        DrawCircleV(circlePos, 80, ORANGE);

        if (showMessage) {
            DrawText("Example text: 'Hello, World!'", GetScreenWidth() / 2,
                     GetScreenHeight() / 2, 12, WHITE);
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            targetPos = GetMousePosition();
        }

        rlImGuiBegin();
        {
            const float imguiSidebarWidth = 200.0f;
            ImGui::Begin("Physics Controller", NULL,
                         ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
            ImGui::SetWindowPos(ImVec2(20, 20), ImGuiCond_Always);
            const float halfScreenHeight = GetScreenHeight() * 0.5f;
            ImGui::SetWindowSize(ImVec2(imguiSidebarWidth, halfScreenHeight));
            ImGui::TextWrapped("Press the button to show text.");

            if (ImGui::Button("Button!!")) {
                showMessage = !showMessage;
            }

            ImGui::End();
        }
        rlImGuiEnd();

        EndDrawing();
    }

    rlImGuiShutdown();
    CloseWindow();
    return 0;
}
