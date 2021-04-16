if (NOT WIN32)
	find_package(Curses REQUIRED)
	include_directories(${CURSES_INCLUDE_DIR})
ENDIF()

add_executable(${PROJECT_NAME} main.cpp engine.cpp engine.hpp strings.hpp)

if (NOT WIN32)
	target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
ENDIF()

install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})