#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <vulkan/vulkan.h>

namespace sm {
namespace platform {

class Window {
 public:
  struct Extent {
    unsigned int width;
    unsigned int height;
  };

  virtual ~Window() = default;

  // Window interface
  virtual bool Init(const std::string& title, const Extent& extent) = 0;
  virtual VkSurfaceKHR CreateSurface(VkInstance instance) = 0;
  virtual std::vector<std::string> GetRequiredExtensions() const = 0;
  virtual void ProcessEvents() = 0;
  virtual void Close() = 0;

  // Window state.
  bool ShouldClose() const { return should_close_; }



 protected:
  bool should_close_ = false;

  void InitBase(std::string title, Extent extent) {
    title_ = title;
    extent_ = extent;
  }

 private:
  std::string title_;
  Extent extent_;
};

}  // namespace platform
}  // namespace sm