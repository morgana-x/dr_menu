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
static int dr2TextLayer = 1;
static int dr2TextColor = 1;
static int dr2TextPosX = 100;
static int dr2TextPosY = 100;
static char dr2InputBuf[128] = "Text Custom";

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
    }
    if (ImGui::CollapsingHeader("Text Engine Test"))
    {
        ImGui::InputInt("Layer", &dr2TextLayer);
        ImGui::InputInt("Color ID", &dr2TextColor);
        ImGui::SliderInt("Pos X", &dr2TextPosX, 0, 1280);
        ImGui::SliderInt("Pos Y", &dr2TextPosY, 0, 720);

        ImGui::InputText("Texto", dr2InputBuf, IM_ARRAYSIZE(dr2InputBuf));

        if (ImGui::Button("Desenhar Texto Digitado"))
        {
            wchar_t wMsg[128];
            MultiByteToWideChar(CP_UTF8, 0, dr2InputBuf, -1, wMsg, 128);

            int currentX = dr2TextPosX;
            size_t len = wcslen(wMsg);

            for (size_t i = 0; i < len; i++)
            {
                int charWidth = Funcs::textBuffer::Draw(dr2TextLayer, currentX, dr2TextPosY, (short)wMsg[i], dr2TextColor);

                // The function returns the size of the drawn character
                currentX += (charWidth > 0) ? charWidth : 20;
            }
        }
    }
}
