#pragma once

#include <SDL3/SDL.h>

#include "window.hpp"

namespace sm {
namespace platform {

class SDLWindow : public Window {
 public:
  SDLWindow();
  ~SDLWindow() override;

  bool Init(const std::string& title, const Extent& extent) override;
  VkSurfaceKHR CreateSurface(VkInstance instance) override;
  std::vector<std::string> GetRequiredExtensions() const override;
  void ProcessEvents() override;
  void Close() override;

 private:
  SDL_Window* window_;
  const char* const* extensions_;
};

}  // namespace platform
}  // namespace sm