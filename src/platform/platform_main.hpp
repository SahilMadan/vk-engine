#pragma once

/** Initialize the platform. Only include this file once from main. */

#include <SDL3/SDL_main.h>

#include <memory>
#include <platform/window.hpp>
#include <platform/sdl_window.hpp>

namespace sm {
namespace platform {

std::unique_ptr<Window> CreatePlatformWindow() {
  // SDL3 implementation.
  return std::make_unique<sm::platform::SDLWindow>();
}

}  // platform
}  // sm

