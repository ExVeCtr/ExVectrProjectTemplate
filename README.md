# VectrProjectTemplate
Part of the VECTR project. 
This repository contains a template for creating Vectr projects on a windows machine.
## **This project is under initial development. Things will probably break.**
## How to start:
- Install VSCode, cmake, git and the visual studio compiler.
- Get VSCode extensions: c++, cmake.
- Create a folder for the project, open console in said folder and give following commands:
- git clone https://github.com/ChSt15/VectrProjectTemplate.git
- cd ./VectrProjectTemplate/
- git submodule init
- git submodule update
- ...
- Open project in VSCode and go into CMakeLists file. Save and CMake should prepare.
- At bottom of VSCode press the play button to build and run.
- ...
- Profit
## To implement onto a platform:##
- A library must be made to implement multiple functions in the hardware abstraction layer:
    - These will be named in the future once basic implementation is finished.