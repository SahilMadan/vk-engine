cmake_minimum_required (VERSION 3.12)

set(SM_PROJECT_NAME "vk-engine")

project(${SM_PROJECT_NAME})
find_package(Vulkan REQUIRED)

add_executable(${SM_PROJECT_NAME})
add_subdirectory(src)
add_subdirectory(third_party)

set_property(TARGET ${SM_PROJECT_NAME} PROPERTY CXX_STANDARD 23)


target_link_options(${SM_PROJECT_NAME} PRIVATE -mwindows)
target_link_libraries(${SM_PROJECT_NAME} PRIVATE SDL3::SDL3-static)
target_link_libraries(${SM_PROJECT_NAME} PRIVATE Vulkan::Vulkan)