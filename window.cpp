#include "rlImGui/rlImGui.h"
#include <imgui.h>
#include <raylib.h>

int main() {

    int screendWidth = 1920 / 2;
    int screenHeight = 1080 / 2;

    bool showMessage = false;

    InitWindow(screendWidth, screenHeight, "Physics Engine");
    rlImGuiSetup(true);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        rlImGuiBegin();

        {
            const float imguiSidebarWidth = 200.0f;
            const float halfScreenHeight = GetScreenHeight() * 0.5f;

            ImGui::Begin("Physics Controller", NULL,
                         ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);

            ImGui::SetWindowPos(ImVec2(20, 20), ImGuiCond_Always);
            ImGui::SetWindowSize(ImVec2(imguiSidebarWidth, halfScreenHeight));

            ImGui::TextWrapped("Press the button to show text.");

            if (ImGui::Button("Button!!")) {
                showMessage = !showMessage;
            }

            if (showMessage) {
                DrawText("Example text: 'Hello, World!'", GetScreenWidth() / 2,
                         GetScreenHeight() / 2, 12, WHITE);
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
