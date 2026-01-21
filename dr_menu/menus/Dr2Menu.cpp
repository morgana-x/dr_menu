#include "../Menu.hpp"
#include "imgui.h"
#include "../Dr2.h"
#include "../pch.h"
using namespace DrLib::Dr2;

int dr2selectedMap = 0;
int dr2selectedDebugMenu = 0;
int dr2selectedSong = 0;
int dr2loadStandSelectedChar = 0;
int dr2loadStandSelectedEmote = 0;
int dr2monocoins = 0;
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
}