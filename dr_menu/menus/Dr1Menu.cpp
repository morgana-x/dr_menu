#include "../Menu.hpp"
#include "imgui.h"
#include "../Dr1.h"
#include "../pch.h"
using namespace DrLib::Dr1;

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
int charTeleportSelectedChar = 0;

float selectedFov = 45;


int hudEnableChapterTimeOfDay = 0;
int hudEnableChapterChapter = 1;
int hudEnableChapterAnim = 1;

int selectedTimeOfDay = 0;
void Menu::Menu_DR1()
{
    if (ImGui::CollapsingHeader("Map"))
    {
        ImGui::Text("Map::CurrentMap = %i", *Values::Map::CurrentMap);

        if (ImGui::Button("Map::LoadMap("))
            DrLib::Dr1::Funcs::Map::Load(selectedMap);
        ImGui::SameLine();
        ImGui::PushItemWidth(80);
        ImGui::InputInt("##Map_ID", &selectedMap);
        ImGui::PopItemWidth();
        ImGui::SameLine();
        ImGui::Text(")");

        ImGui::Text("Map::Pos = ");
        ImGui::SameLine();
        ImGui::PushItemWidth(170);
        ImGui::InputFloat3("##Map::Pos", (float*)Values::Map::Pos);
        ImGui::PopItemWidth();
    }

    // Movie Func causes crash
    /* if (ImGui::CollapsingHeader("Movie"))
     {
         if (ImGui::Button("Movie::LoadMovie("))
             Funcs::Movie::Load(selectedMovie);
         ImGui::SameLine();
         ImGui::PushItemWidth(80);
         ImGui::InputInt("##Movie_ID", &selectedMovie);
         ImGui::PopItemWidth();
         ImGui::SameLine();
         ImGui::Text(")");
     }*/

    if (ImGui::CollapsingHeader("Game Data"))
    {
        monocoins = (int)*DrLib::Dr1::Values::Game::Monocoins;
        int oldmonocoins = monocoins;
        ImGui::Text("GameData::Monocoins = ");
        ImGui::SameLine();
        ImGui::PushItemWidth(80);
        ImGui::InputInt("##MonocoinAmount", &monocoins);
        ImGui::PopItemWidth();
        if (oldmonocoins != monocoins)
            *Values::Game::Monocoins = monocoins;

        selectedTimeOfDay = (int)Values::Game::State->TimeOfDay;
        oldmonocoins = selectedTimeOfDay;
        ImGui::Text("GameData::State->TimeOfDay =");
        ImGui::SameLine();
        ImGui::PushItemWidth(80);
        ImGui::SliderInt("##GameDataStateTimeOfDay", &selectedTimeOfDay, 0, 4);
        ImGui::PopItemWidth();
        if (oldmonocoins != selectedTimeOfDay)
            Values::Game::State->TimeOfDay = (short)selectedTimeOfDay;

        ImGui::Text("GameData::State->SkillPoints = %i", Values::Game::State->SkillPoints);
        ImGui::Text("GameData::State->UnlockedRulePages = %i", Values::Game::State->UnlockedRulePages);
        ImGui::Text("GameData::State->ActionDifficulty = %i", Values::Game::State->ActionDifficulty);
        ImGui::Text("GameData::State->LogicDifficulty = %i", Values::Game::State->LogicDifficulty);
    }

    /*
    if (ImGui::CollapsingHeader("Achievement"))
    {
        if (ImGui::Button("(CRASH) Achivement::UnlockAchivement("))
            Funcs::Achievement::UnlockAchievement(selectedAchievement);
        ImGui::SameLine();
        ImGui::InputInt("Trophy_ID", &selectedAchievement);
        ImGui::SameLine();
        ImGui::Text(")");
    }*/


    if (ImGui::CollapsingHeader("Player"))
    {
        ImGui::Text("Player::Pos = %f, %f, %f", Values::Player::Pos->x, Values::Player::Pos->y, Values::Player::Pos->z);
        ImGui::Text("Player::Rot = %f, %f", Values::Camera::Rot->x, Values::Camera::Rot->y);
        if (ImGui::Button("Player::SetPos("))
            Funcs::Player::SetPos(selectedCamPos[0], selectedCamPos[1], selectedCamPos[2], selectedCamRotX);
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
        ImGui::Text("Script::CurrentScript = %i, %i, %i", Values::Script::ScriptId->Chapter, Values::Script::ScriptId->Scene, Values::Script::ScriptId->Variant);
        //    ImGui::Text("Script::CurrentSpeaker = %i", *Values::Script::Speaker);
        if (ImGui::Button("Script::LoadAndRun("))
            Funcs::Script::LoadAndRun(0, selectedScript[0], selectedScript[1], selectedScript[2]);
        ImGui::SameLine();
        ImGui::PushItemWidth(160);
        ImGui::InputInt3("##Script", selectedScript);
        ImGui::PopItemWidth();
        ImGui::SameLine();
        ImGui::Text(")");
    }

    if (ImGui::CollapsingHeader("Audio"))
    {
        ImGui::Text("Audio::CurrentSong = %i", *Values::Audio::CurrentSong);

        if (ImGui::Button("Audio::PlaySong("))
            Funcs::Audio::PlaySongWrapper(selectedSong);
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
            Funcs::Character::LoadStand(loadStandSelectedChar, loadStandSelectedEmote);
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
            Funcs::Character::SpawnChar(spawnCharSelectedChar, spawnCharSelectedEmote);
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
            Funcs::Character::SetPos(charSetPosSelectedChar, charSetPosSelectedPos[0], charSetPosSelectedPos[1], charSetPosSelectedPos[2]);
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

        if (ImGui::Button("Character::TeleportToPlayer("))
            Funcs::Character::SetPos(charTeleportSelectedChar, Values::Player::Pos->x, Values::Player::Pos->y, Values::Player::Pos->z);
        ImGui::SameLine();
        ImGui::PushItemWidth(80);
        ImGui::InputInt("##charTeleportCharID", &charTeleportSelectedChar);
        ImGui::PopItemWidth();
        ImGui::SameLine();
        ImGui::Text(")");
    }

    if (ImGui::CollapsingHeader("Camera"))
    {
        ImGui::Text("Camera::Pos = %f, %f, %f", Values::Camera::Pos->x, Values::Camera::Pos->y, Values::Camera::Pos->z);
        ImGui::Text("Camera::Rot = %f, %f, %f", Values::Camera::Rot->x, Values::Camera::Rot->y, *Values::Camera::Rot_Up);

        selectedFov = (float)*Values::Camera::Fov;
        float oldfov = selectedFov;
        ImGui::Text("Camera::Fov = ");
        ImGui::SameLine();
        ImGui::PushItemWidth(85);
        ImGui::InputFloat("##CamFov", &selectedFov);
        ImGui::PopItemWidth();
        if (oldfov != selectedFov)
            Funcs::Camera::SetFov(selectedFov);
    }
    if (ImGui::CollapsingHeader("HUD"))
    {
        if (ImGui::Button("HUD::ToggleRadio()"))
            *Values::HUD::RadioVisible = !(*Values::HUD::RadioVisible);

        if (ImGui::Button("HUD::HideChapter()"))
            Funcs::HUD::HideChapterAnim();

        if (ImGui::Button("HUD::ShowChapter("))
            Funcs::HUD::ShowChapter(hudEnableChapterTimeOfDay, (char)hudEnableChapterChapter, (char)hudEnableChapterAnim);
        ImGui::SameLine();
        ImGui::PushItemWidth(60);
        ImGui::SliderInt("TimeDay##EnableChapter", &hudEnableChapterTimeOfDay, 0, 4);
        ImGui::SameLine();
        ImGui::SliderInt("Chapter##EnableChapter", &hudEnableChapterChapter, 1, 8);
        ImGui::SameLine();
        ImGui::SliderInt("DoAnim##EnableChapter", &hudEnableChapterAnim, 0, 1);
        ImGui::PopItemWidth();
        ImGui::SameLine();
        ImGui::Text(")");
    }
    if (ImGui::CollapsingHeader("Debug"))
    {
        selectedDebugMenu = (int)*Values::Debug::SelectedMenu;
        int oldSelected = selectedDebugMenu;
        ImGui::Text("Debug::CurrentMenu = ");
        ImGui::SameLine();
        ImGui::PushItemWidth(80);
        ImGui::InputInt("##Debug::CurrentMenu", &selectedDebugMenu);
        ImGui::PopItemWidth();
        if (oldSelected != selectedDebugMenu)
            *Values::Debug::SelectedMenu = (char)selectedDebugMenu;

        if (ImGui::Button("Debug::EnableMenu()"))
            Funcs::Debug::EnableDebugMenu();
    }
}