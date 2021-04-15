find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp engine.cpp engine.hpp strings.hpp)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})
