#include "Menu.hpp"
#include "Core.hpp"
#include "imgui.h"


void Menu::Render()
{
        ImGui::Begin("Menu");
        
        switch (Core::Game)
        {
            case Core::DR1:
                Menu::Menu_DR1();
                break;
            case Core::DR2:
                Menu::Menu_DR2();
                break;
            case Core::None:
                ImGui::Text("No valid game detected.");
                break;
        }

        ImGui::End();
}