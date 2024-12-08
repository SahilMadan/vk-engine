#include <SDL3/SDL_main.h>

#include <memory>
#include <platform/platform_main.hpp>
#include <platform/window.hpp>
#include <print>

int main(int argc, char** argv) {
  std::unique_ptr<sm::platform::Window> window = sm::platform::CreatePlatformWindow();
  window->Init("vk-engine", sm::platform::Window::Extent{800, 600});

  while (!window->ShouldClose()) {
    window->ProcessEvents();
  }

  return 0;
}