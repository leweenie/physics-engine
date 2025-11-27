#include "rlImGui/rlImGui.h"
#include <imgui.h>
#include <raylib.h>

int main() {
    int screenWidth = 1920 / 2;
    int screenHeight = 1080 / 2;
    bool showMessage = false;

    InitWindow(screenWidth, screenHeight, "Physics Engine");
    rlImGuiSetup(true);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        const float halfScreenWidth = GetScreenWidth() * 0.5f;
        const float halfScreenHeight = GetScreenHeight() * 0.5f;
        DrawCircle(halfScreenWidth, halfScreenHeight, 80, ORANGE);

        if (showMessage) {
            DrawText("Example text: 'Hello, World!'", GetScreenWidth() / 2,
                     GetScreenHeight() / 2, 12, WHITE);
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
