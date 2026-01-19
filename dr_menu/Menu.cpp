#include "Menu.hpp"
#include "DrValues.h"
#include "DrFuncs.h"
#include "imgui.h"
bool show_another_window = false;
int selectedMap = 0;
int selectedMovie = 0;
int selectedAchievement = 0;
int selectedDebugMenu = 0;

int selectedSong = 0;

int monocoins = 0;

float selectedCamPos[3];
float selectedCamRotX = 0;

int selectedScript[3];


int charSetPosSelectedChar = 0;
float charSetPosSelectedPos[3];

int loadStandSelectedChar = 0;
int loadStandSelectedEmote = 0;

int spawnCharSelectedChar = 0;
int spawnCharSelectedEmote = 0;

#define IM_MIN(A, B)            (((A) < (B)) ? (A) : (B))
void Menu::Render()
{
    /*
    const float label_width_base = ImGui::GetFontSize() * 2;               // Some amount of width for label, based on font size.
    const float label_width_max = ImGui::GetContentRegionAvail().x * 0.40f; // ...but always leave some room for framed widgets.
    const float label_width = IM_MIN(label_width_base, label_width_max);
    ImGui::PushItemWidth(-label_width);*/

    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
    {
        ImGui::Begin("Menu");

        if (ImGui::CollapsingHeader("Map"))
        {
            ImGui::Text("Map::CurrentMap = %i", *DrValues::Dr1::Map::CurrentMap);

            if (ImGui::Button("Map::LoadMap("))
                DrFuncs::Dr1::Map::Load(selectedMap);
            ImGui::SameLine();
            ImGui::PushItemWidth(80);
            ImGui::InputInt("##Map_ID", &selectedMap);
            ImGui::PopItemWidth();
            ImGui::SameLine();
            ImGui::Text(")");

            ImGui::Text("Map::Pos = ");
            ImGui::SameLine();
            ImGui::PushItemWidth(170);
            ImGui::InputFloat3("##Map::Pos", (float*)DrValues::Dr1::Map::Pos);
            ImGui::PopItemWidth();
        }

       
        if (ImGui::CollapsingHeader("Movie"))
        {
            if (ImGui::Button("Movie::LoadMovie("))
                DrFuncs::Dr1::Movie::Load(selectedMovie);
            ImGui::SameLine();
            ImGui::PushItemWidth(80);
            ImGui::InputInt("##Movie_ID", &selectedMovie);
            ImGui::PopItemWidth();
            ImGui::SameLine();
            ImGui::Text(")");
        }

        if (ImGui::CollapsingHeader("Game Data"))
        {
            monocoins = (int)*DrValues::Dr1::Game::Monocoins;
            int oldmonocoins = monocoins;
            ImGui::Text("GameData::Monocoins = ");
            ImGui::SameLine();
            ImGui::PushItemWidth(80);
            ImGui::InputInt("##MonocoinAmount", &monocoins);
            ImGui::PopItemWidth();
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
            ImGui::PushItemWidth(160);
            ImGui::InputFloat3("pos##P_Pos", selectedCamPos, "%.3f");
            ImGui::PopItemWidth();
            ImGui::SameLine();
            ImGui::PushItemWidth(50);
            ImGui::InputFloat("rot##P_Rot", &selectedCamRotX);
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
            ImGui::PushItemWidth(160);
            ImGui::InputInt3("##Script", selectedScript);
            ImGui::PopItemWidth();
            ImGui::SameLine();
            ImGui::Text(")");
        }
        
        if (ImGui::CollapsingHeader("Audio"))
        {
            ImGui::Text("Audio::CurrentSong = %i", *DrValues::Dr1::Audio::CurrentSong);

            if (ImGui::Button("Audio::PlaySong("))
                DrFuncs::Dr1::Audio::PlaySongWrapper(selectedSong);
            ImGui::SameLine();
            ImGui::PushItemWidth(80);
            ImGui::InputInt("##SongId", &selectedSong);
            ImGui::PopItemWidth();
            ImGui::SameLine();
            ImGui::Text(")");
        }
        if (ImGui::CollapsingHeader("Character"))
        {
            if (ImGui::Button("Character::LoadStand("))
                DrFuncs::Dr1::Character::LoadStand(loadStandSelectedChar, loadStandSelectedEmote);
            ImGui::SameLine();
            ImGui::PushItemWidth(80);
            ImGui::InputInt("char##loadStandChar", &loadStandSelectedChar);
            ImGui::PopItemWidth();
            ImGui::SameLine();  
            ImGui::SameLine();
            ImGui::PushItemWidth(80);
            ImGui::InputInt("emote##loadStandEmote", &loadStandSelectedEmote);
            ImGui::PopItemWidth();
            ImGui::SameLine();
            ImGui::Text(")");


            if (ImGui::Button("Character::Spawn("))
                DrFuncs::Dr1::Character::SpawnChar(spawnCharSelectedChar, spawnCharSelectedEmote);
            ImGui::SameLine();
            ImGui::PushItemWidth(80);
            ImGui::InputInt("char##spawnChar", &spawnCharSelectedChar);
            ImGui::PopItemWidth();
            ImGui::SameLine();
            ImGui::SameLine();
            ImGui::PushItemWidth(80);
            ImGui::InputInt("?##spawnUnk", &spawnCharSelectedEmote);
            ImGui::PopItemWidth();
            ImGui::SameLine();
            ImGui::Text(")");

            if (ImGui::Button("Character::SetPos("))
                DrFuncs::Dr1::Character::SetPos(charSetPosSelectedChar, charSetPosSelectedPos[0], charSetPosSelectedPos[1], charSetPosSelectedPos[2]);
            ImGui::SameLine();
            ImGui::PushItemWidth(80);
            ImGui::InputInt("char##setPosID", &charSetPosSelectedChar);
            ImGui::PopItemWidth();
            ImGui::SameLine();
            ImGui::PushItemWidth(170);
            ImGui::InputFloat3("pos##charsetPosPos", charSetPosSelectedPos);
            ImGui::PopItemWidth();
            ImGui::SameLine();
            ImGui::Text(")");
        }

        if (ImGui::CollapsingHeader("Debug"))
        {
            selectedDebugMenu = (int)*DrValues::Dr1::Debug::SelectedMenu;
            int oldSelected = selectedDebugMenu;
            ImGui::Text("Debug::CurrentMenu = ");
            ImGui::SameLine();
            ImGui::PushItemWidth(80);
            ImGui::InputInt("##Debug::CurrentMenu", &selectedDebugMenu);
            ImGui::PopItemWidth();
            if (oldSelected != selectedDebugMenu)
                *DrValues::Dr1::Debug::SelectedMenu = (char)selectedDebugMenu;

            if (ImGui::Button("Debug::EnableMenu()"))
                DrFuncs::Dr1::Debug::EnableDebugMenu();
        }

        ImGui::End();
    }

//    ImGui::PopItemWidth();
}