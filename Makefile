main: ./src/engine/engine.hpp ./src/res/strings.hpp
	g++ -std=c++20 -Wall -Wextra -o ./bin/main.exe ./src/main.cpp ./src/engine/engine.cpp && ./bin/main.exe