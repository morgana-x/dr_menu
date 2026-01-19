#include "Menu.hpp"
#include "DrValues.h"
#include "DrFuncs.h"
#include "imgui.h"
bool show_demo_window = true;
bool show_another_window = false;
int selectedMap = 0;
int selectedMovie = 0;
int selectedAchievement = 0;

int monocoins = 0;

float selectedCamPos[3];
float selectedCamRotX = 0;

int selectedScript[3];
#define IM_MIN(A, B)            (((A) < (B)) ? (A) : (B))
void Menu::Render()
{
    // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
    if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);
        // Most framed widgets share a common width settings. Remaining width is used for the label.
    // The width of the frame may be changed with PushItemWidth() or SetNextItemWidth().
    // - Positive value for absolute size, negative value for right-alignment.
    // - The default value is about GetWindowWidth() * 0.65f.
    // - See 'Demo->Layout->Widgets Width' for details.
// Here we change the frame width based on how much width we want to give to the label.
    const float label_width_base = ImGui::GetFontSize() * 2;               // Some amount of width for label, based on font size.
    const float label_width_max = ImGui::GetContentRegionAvail().x * 0.40f; // ...but always leave some room for framed widgets.
    const float label_width = IM_MIN(label_width_base, label_width_max);
    ImGui::PushItemWidth(-label_width);

    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
    {
        ImGui::Begin("Menu");

        if (ImGui::CollapsingHeader("Map"))
        {
            ImGui::Text("Map::CurrentMap = %i", *DrValues::Dr1::Map::CurrentMap);
            ImGui::InputFloat3("Map::Pos", (float*)DrValues::Dr1::Map::Pos);
            if (ImGui::Button("Map::LoadMap("))
                DrFuncs::Dr1::Map::Load(selectedMap);
            ImGui::SameLine();
            ImGui::InputInt("Map_ID", &selectedMap);
            ImGui::SameLine();
            ImGui::Text(")");
        }

       
        if (ImGui::CollapsingHeader("Movie"))
        {
            if (ImGui::Button("Movie::LoadMovie("))
                DrFuncs::Dr1::Movie::Load(selectedMovie);
            ImGui::SameLine();
            ImGui::InputInt("Movie_ID", &selectedMovie);
            ImGui::SameLine();
            ImGui::Text(")");
        }

        if (ImGui::CollapsingHeader("Game Data"))
        {
            monocoins = (int)*DrValues::Dr1::Game::Monocoins;
            int oldmonocoins = monocoins;
            ImGui::Text("GameData::Monocoins = ");
            ImGui::SameLine();
            ImGui::InputInt("MonocoinAmount", &monocoins);
            if (oldmonocoins != monocoins)
                *DrValues::Dr1::Game::Monocoins = monocoins;
        }

        /*
        if (ImGui::CollapsingHeader("Achievement"))
        {
            if (ImGui::Button("(CRASH) Achivement::UnlockAchivement("))
                DrFuncs::Dr1::Achievement::UnlockAchievement(selectedAchievement);
            ImGui::SameLine();
            ImGui::InputInt("Trophy_ID", &selectedAchievement);
            ImGui::SameLine();
            ImGui::Text(")");
        }*/

        
        if (ImGui::CollapsingHeader("Player"))
        {
            ImGui::Text("Player::Pos = %f, %f, %f", DrValues::Dr1::Player::Pos->x, DrValues::Dr1::Player::Pos->y, DrValues::Dr1::Player::Pos->z);
            ImGui::Text("Player::Rot = %f, %f", DrValues::Dr1::Camera::Rot->x, DrValues::Dr1::Camera::Rot->y);
            if (ImGui::Button("Player::SetPos("))
                DrFuncs::Dr1::Player::SetPos(selectedCamPos[0], selectedCamPos[1], selectedCamPos[2], selectedCamRotX);
            ImGui::SameLine();
            ImGui::PushItemWidth(-label_width / 2);
            ImGui::InputFloat3("P_Pos", selectedCamPos, "%.3f");
            ImGui::SameLine();
            ImGui::InputFloat("P_Rot", &selectedCamRotX);
            ImGui::PopItemWidth();
            ImGui::SameLine();
            ImGui::Text(")");
        }

        if (ImGui::CollapsingHeader("Script"))
        {
            ImGui::Text("Script::CurrentScript = %i, %i, %i", DrValues::Dr1::Script::ScriptId->Chapter, DrValues::Dr1::Script::ScriptId->Scene, DrValues::Dr1::Script::ScriptId->Variant);
        //    ImGui::Text("Script::CurrentSpeaker = %i", *DrValues::Dr1::Script::Speaker);
            if (ImGui::Button("Script::LoadAndRun("))
                DrFuncs::Dr1::Script::LoadAndRun(0, selectedScript[0], selectedScript[1], selectedScript[2]);
            ImGui::SameLine();
            ImGui::InputInt3("Script", selectedScript);
            ImGui::SameLine();
            ImGui::Text(")");
        }

        ImGui::End();
    }

    ImGui::PopItemWidth();
}