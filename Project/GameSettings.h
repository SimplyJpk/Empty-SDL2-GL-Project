#pragma once
#include <gl/GLEW.h>

#include "ConfigFile.h"

#include "Constants.h"
#include "Vec2.h"

struct GameSettings
{
   GLint default_shader;

   /* Game Settings that will be global */
   IVec2 screen_size = IVec2(1280, 720);
   float aspect_ratio = screen_size.x / screen_size.y;

   float target_frames_per_second = 60.0f;
   float calculated_frame_delay = 1000.0f / target_frames_per_second;

   float fixed_update_rate = 0.02f;
   // Max number of updates we want the fixed update to run, this prevents complete lockup.
   short max_fixed_steps = 10;

   void LoadSettings(ConfigFile& config)
   {
      screen_size.x = config.screen_x;
      screen_size.y = config.screen_y;
      // Set aspect ratio for future use
      aspect_ratio = screen_size.x / static_cast<float>(screen_size.y);
      // Target updates from config (FPS)
      target_frames_per_second = config.target_frames_per_second;

      calculated_frame_delay = 1000.0f / target_frames_per_second;

      fixed_update_rate = config.fixed_updates_per_second;

      max_fixed_steps = config.max_fixed_steps;
   };
};
