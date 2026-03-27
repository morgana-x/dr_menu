#include "../Menu.hpp"
#include "imgui.h"
#include "../drlib/Dr2.h"
#include "../pch.h"
using namespace DrLib::Dr2;

int dr2selectedMap = 0;
int dr2selectedDebugMenu = 0;
int dr2selectedSong = 0;
int dr2loadStandSelectedChar = 0;
int dr2loadStandSelectedEmote = 0;
int dr2monocoins = 0;
int dr2TextLayer = 1;
int dr2TextColor = 0;
int dr2TextPosX = 100;
int dr2TextPosY = 100;
char dr2InputBuf[128] = "Text Custom";


int dr2spawnCharSelectedChar = 0;
int dr2spawnCharSelectedPosDr1 = 0;

int dr2selectedSpawnChar = 0;
void Menu::Menu_DR2()
{

    if (ImGui::CollapsingHeader("Map"))
    {
        ImGui::Text("Map::CurrentMap = %i", *Values::Map::CurrentMap);

        if (ImGui::Button("Map::LoadMap("))
            Funcs::Map::Load(dr2selectedMap);
        ImGui::SameLine();
        ImGui::PushItemWidth(80);
        ImGui::InputInt("##Map_ID", &dr2selectedMap);
        ImGui::PopItemWidth();
        ImGui::SameLine();
        ImGui::Text(")");

        /*ImGui::Text("Map::Pos = ");
        ImGui::SameLine();
        ImGui::PushItemWidth(170);
        ImGui::InputFloat3("##Map::Pos", (float*)Values::Map::Pos);
        ImGui::PopItemWidth();*/
    }

    if (ImGui::CollapsingHeader("Audio"))
    {
        ImGui::Text("Audio::CurrentSong = %i", *Values::Audio::CurrentSong);

        if (ImGui::Button("Audio::PlaySong("))
            Funcs::Audio::PlaySongWrapper(dr2selectedSong);
        ImGui::SameLine();
        ImGui::PushItemWidth(80);
        ImGui::InputInt("##SongId", &dr2selectedSong);
        ImGui::PopItemWidth();
        ImGui::SameLine();
        ImGui::Text(")");
    }

    if (ImGui::CollapsingHeader("Collectables"))
    {
        dr2monocoins = (int)*Values::Collectables::Monocoins;
        int oldmonocoins = dr2monocoins;
        ImGui::Text("Collectables::Monocoins = ");
        ImGui::SameLine();
        ImGui::PushItemWidth(80);
        ImGui::InputInt("##MonocoinAmount", &dr2monocoins);
        ImGui::PopItemWidth();
        if (oldmonocoins != dr2monocoins)
            *Values::Collectables::Monocoins = dr2monocoins;
    }

    if (ImGui::CollapsingHeader("Player"))
    {
        ImGui::Text("Player::Level = %i", *Values::Player::Level);
    }
    if (ImGui::CollapsingHeader("Character"))
    {
        if (ImGui::Button("Character::LoadStand("))
            Funcs::Character::LoadStand(dr2loadStandSelectedChar, dr2loadStandSelectedEmote);
        ImGui::SameLine();
        ImGui::PushItemWidth(80);
        ImGui::InputInt("char##loadStandChar", &dr2loadStandSelectedChar);
        ImGui::PopItemWidth();
        ImGui::SameLine();
        ImGui::SameLine();
        ImGui::PushItemWidth(80);
        ImGui::InputInt("emote##loadStandEmote", &dr2loadStandSelectedEmote);
        ImGui::PopItemWidth();
        ImGui::SameLine();
        ImGui::Text(")");


        if (ImGui::Button("Character::Spawn("))
            Funcs::Character::SpawnChar(dr2spawnCharSelectedChar, (char)dr2spawnCharSelectedPosDr1);
        ImGui::SameLine();
        ImGui::PushItemWidth(80);
        ImGui::InputInt("char##spawnChar", &dr2spawnCharSelectedChar);
        ImGui::PopItemWidth();
        ImGui::SameLine();
        ImGui::PushItemWidth(80);
        ImGui::InputInt("pos##spawnUnk", &dr2spawnCharSelectedPosDr1);
        ImGui::PopItemWidth();
        ImGui::SameLine();
        ImGui::Text(")");

     
    }
    if (ImGui::CollapsingHeader("Text Rendering"))
    {
        ImGui::Text("Layer ID:"); ImGui::SameLine(150);
        ImGui::InputInt("##LayerID", &dr2TextLayer);
        ImGui::Text("CLT Color:"); ImGui::SameLine(150);
        if (ImGui::InputInt("##CltIdx", &dr2TextColor)) {
            if (dr2TextColor < 0) dr2TextColor = 0;
            if (dr2TextColor > 97) dr2TextColor = 97;
        }
        ImGui::SameLine();
        ImGui::TextDisabled("(Max: 97)");
        ImGui::Text("Position X:"); ImGui::SameLine(150);
        ImGui::SliderInt("##PosX", &dr2TextPosX, 0, 1280);
        ImGui::Text("Position Y:"); ImGui::SameLine(150);
        ImGui::SliderInt("##PosY", &dr2TextPosY, 0, 720);
        ImGui::Text("Text:"); ImGui::SameLine(150);
        ImGui::InputText("##InputStr", dr2InputBuf, IM_ARRAYSIZE(dr2InputBuf));
        ImGui::SameLine();

        if (ImGui::Button("Render Text"))
        {
            wchar_t wMsg[128];
            MultiByteToWideChar(CP_UTF8, 0, dr2InputBuf, -1, wMsg, 128);
            Funcs::TextRender::PrintString(dr2TextLayer, dr2TextPosX, dr2TextPosY, wMsg, dr2TextColor);
        }
    }
}