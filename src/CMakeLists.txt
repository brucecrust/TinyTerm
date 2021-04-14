add_executable(${PROJECT_NAME} main.cpp engine.cpp engine.hpp strings.hpp)

install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})