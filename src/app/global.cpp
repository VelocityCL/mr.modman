#include "global.hpp"

bool global::shutdown = false;
HWND global::hwnd;
SDL_Window* global::window = 0;
SDL_Renderer* global::renderer = 0;
SDL_Surface* global::surface = 0;
ImVec2 global::resolution = { 1280, 720 };
bool global::always_on_top = false;
bool global::use_hardware = false;
std::uint32_t global::winver = -1;
float global::framerate = 0.0f;
std::uint32_t  global::desired_framerate;
std::uint32_t global::framelimit;
std::uint64_t global::counter;
std::uint32_t global::start;