#include "Menu.hpp"
#include "pch.h"
#include <string>
#include "imgui.h"
enum DrGame
{
    None,
    DR1,
    DR2
};

DrGame Game;
char actualpath[2048];
bool Menu::Init()
{
    TCHAR szEXEPath[2048];
  
    GetModuleFileName(NULL, szEXEPath, 2048);
    for (int j = 0; szEXEPath[j] != 0; j++)
        actualpath[j] = szEXEPath[j];

    std::string filePath(actualpath);
    std::size_t found = filePath.find_last_of("/\\");
    filePath = filePath.substr(found + 1);

    Game = filePath == "DR1_us.exe" ? DR1 : filePath == "DR2_us.exe" ? DR2 : None;

    return true;
}

void Menu::Render()
{
        ImGui::Begin("Menu");
        
        switch (Game)
        {
            case DR1:
                Menu::Menu_DR1();
                break;
            case DR2:
                Menu::Menu_DR2();
                break;
            case None:
                ImGui::Text("No valid game detected.");
                break;
        }

        ImGui::End();
}