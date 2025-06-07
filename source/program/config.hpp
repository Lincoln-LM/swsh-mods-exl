#pragma once
#include "tomlplusplus/toml.hpp"

struct PatchConfig {
    bool initialized = false;

    struct {
        bool active;
    } underworld;

    struct {
        bool active;
        u32 boosted_percentage;
        std::string sound;
        std::string shiny_ptcl;
        bool show_aura_for_brilliants;
        bool include_battle_sounds;
        bool play_sound_for_following;
        bool show_ptcl_for_following;
        bool show_message_box;
    } overworld_shiny;

    struct {
        bool active;
    } randomizer;

    struct {
        bool active;
        float adjustment_speed;
        float min_pitch;
        float max_pitch;
        float min_distance;
        float max_distance;
    } camera_tweaks;

    struct {
        bool active;
        bool fully;
    } uncap_level;

    struct {
        bool active;
        bool disable_terrain_culling;
        bool always_use_extended_camera;
    } freecam;

    struct {
        bool active;
        s32 maximum_spawns;
    } glimwood_overworld;

    struct {
        bool active;
    } synchro_mode;

    struct {
        bool active;
    } extended_following;

    struct {
        bool active;
        bool keep_chain_after_brilliant;
    } fishing_tweaks;

    struct {
        bool active;
    } dex_animations;

    void from_table(toml::parse_result &table) {
        underworld.active = table["underworld"]["active"].value_or(false);

        overworld_shiny.active = table["overworld_shiny"]["active"].value_or(false);
        overworld_shiny.boosted_percentage = table["overworld_shiny"]["boosted_percentage"].value_or(0);
        overworld_shiny.sound = table["overworld_shiny"]["sound"].value_or("Play_Camp_Cooking_Explosion");
        overworld_shiny.shiny_ptcl = table["overworld_shiny"]["shiny_ptcl"].value_or("bin/field/effect/particle/ef_cyc_aura/ef_cyc_aura_rare_bk.ptcl");
        overworld_shiny.show_aura_for_brilliants = table["overworld_shiny"]["show_aura_for_brilliants"].value_or(true);
        overworld_shiny.show_message_box = table["overworld_shiny"]["show_message_box"].value_or(false);
        overworld_shiny.include_battle_sounds = table["overworld_shiny"]["include_battle_sounds"].value_or(true);
        overworld_shiny.play_sound_for_following = table["overworld_shiny"]["play_sound_for_following"].value_or(false);
        overworld_shiny.show_ptcl_for_following = table["overworld_shiny"]["show_ptcl_for_following"].value_or(true);

        randomizer.active = table["randomizer"]["active"].value_or(false);

        camera_tweaks.active = table["camera_tweaks"]["active"].value_or(false);
        camera_tweaks.adjustment_speed = table["camera_tweaks"]["adjustment_speed"].value_or(3.0);
        camera_tweaks.min_pitch = table["camera_tweaks"]["min_pitch"].value_or(-20.0);
        camera_tweaks.max_pitch = table["camera_tweaks"]["max_pitch"].value_or(-5.0);
        camera_tweaks.min_distance = table["camera_tweaks"]["min_distance"].value_or(370.0);
        camera_tweaks.max_distance = table["camera_tweaks"]["max_distance"].value_or(800.0);

        uncap_level.active = table["uncap_level"]["active"].value_or(false);
        uncap_level.fully = table["uncap_level"]["fully"].value_or(true);

        freecam.active = table["freecam"]["active"].value_or(false);
        freecam.disable_terrain_culling = table["freecam"]["disable_terrain_culling"].value_or(true);
        freecam.always_use_extended_camera = table["freecam"]["always_use_extended_camera"].value_or(false);

        glimwood_overworld.active = table["glimwood_overworld"]["active"].value_or(false);
        glimwood_overworld.maximum_spawns = table["glimwood_overworld"]["maximum_spawns"].value_or(1);

        synchro_mode.active = table["synchro_mode"]["active"].value_or(false);

        extended_following.active = table["extended_following"]["active"].value_or(false);

        fishing_tweaks.active = table["fishing_tweaks"]["active"].value_or(false);
        fishing_tweaks.keep_chain_after_brilliant = table["fishing_tweaks"]["keep_chain_after_brilliant"].value_or(true);

        dex_animations.active = table["dex_animations"]["active"].value_or(false);

        initialized = true;
    }
};

extern PatchConfig global_config;