#include "sdl_window.hpp"

#include <SDL3/SDL_video.h>
#include <SDL3/SDL_vulkan.h>

#include <print>

namespace sm {
namespace platform {

SDLWindow::SDLWindow() : Window() {}

bool SDLWindow::Init(const std::string& title, const Extent& extent) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    std::println(stderr, "Failed to initialize SDL3");
    return false;
  }
  std::uint32_t window_flags =
      SDL_WINDOW_RESIZABLE | (SDL_WindowFlags)(SDL_WINDOW_VULKAN);
  SDL_Window* window = SDL_CreateWindow(title.c_str(), extent.width,
                                        extent.height, window_flags);

  InitBase(title, extent);

  return true;
}

SDLWindow::~SDLWindow() {
  if (should_close_) {
    Close();
  }
}

VkSurfaceKHR SDLWindow::CreateSurface(VkInstance instance) {
  VkSurfaceKHR surface;
  SDL_Vulkan_CreateSurface(window_, instance, nullptr, &surface);
  return surface;
}

std::vector<std::string> SDLWindow::GetRequiredExtensions() const {
  std::uint32_t extension_count = 0;
  const char* const* n = SDL_Vulkan_GetInstanceExtensions(&extension_count);
  if (n == nullptr) {
    std::println(stderr, "Failed to get SDL Vulkan extensions");
    return {};
  }
  std::vector<std::string> names(extension_count);
  for (std::uint32_t i = 0; i < extension_count; i++) {
    names[i] = n[i];
  }
  return names;
}

void SDLWindow::ProcessEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_EVENT_QUIT) {
      should_close_ = true;
    }
  }
}

void SDLWindow::Close() {
  should_close_ = false;
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

}  // namespace platform
}  // namespace sm
