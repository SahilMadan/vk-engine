set(SDL_STATIC ON)
add_subdirectory(SDL)

target_include_directories(${SM_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/SDL/include)
