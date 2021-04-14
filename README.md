# TinyTerm 
## A Terminal Game Engine

# Use on Linux:
For now, I will be using Make on Linux to compile the needed files for the program. This is due to my lack of familiarity with CMake. The plan it to ultimately replace Make with CMake. 

Running `make` within the root directory of this project will compile the main and header files, and launch the program. 

# Use on Windows and Visual Studio 2019:
To compile and use this project on Windows, and Visual Studio, you will need CMake installed. Visit cmake.org and download the appropriate version. 

To build using CMake:
1. Once Cmake is install and added to the path, open your environment variables. 
2. Under "System Variables" add a new variable titled "CMAKE_GENERATOR". 
3. The value of this variable, for me, is: `C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.28.29333\bin\Hostx64\x64\bscmake`. This may differ depending on your version. Before, when attempting to run CMake with an inappropriate generator, it simply used its default configurations to build the project. I believe the important thing here is to define the variable and set it to something that reasonably makes sense.
4. Clone the repository, then open it in your favorite editor.
5. Note the `CMakeLists.txt` files in the `root` and `src` directories, these contain the specific instructions for CMake the properly build our project.
6. Open a terminal (command prompt), and enter the following: `mkdir build && cd build`.
7. Once the `/build` directory has been created and the terminal directory has been changed, run this command: `cmake .. -G "Visual Studio 16 2019" -A x64`
8. CMake should successfully build the project; open a file explorer and navigate to the build directory.
9. A `sln` solution file should be displayed in the directory; this file should be named "TinyTerm". Open this file using Visual Studio.
10. Visual Studio should successfully launch the project, displaying the header and source files within the respective directories.