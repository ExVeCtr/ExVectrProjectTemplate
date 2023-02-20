# ExVectr Project Template
Part of the ExVectr project. 
This repository contains a template for creating ExVectr projects on a windows machine.
## **This project is under initial development. Things will probably break.**
## How to start:
- Install VSCode, cmake, git and the visual studio compiler.
- Get VSCode extensions: c++, cmake.
- Create a folder for the project, open terminal in said folder and give following commands:
- `git clone https://github.com/ExVectr/ExVectrProjectTemplate.git`
- `cd ./ExVectrProjectTemplate/`
- `git submodule init`
- `git submodule update`
- `code .`
- ...
- Open project in VSCode and go into CMakeLists file. Save and CMake should prepare.
- At bottom of VSCode press the play button to build and run.
- ...
- Profit
## Structure:##
Add ExVectr Libraries are inside the lib folder. Add source libaries of this project are inside the src folder.
## Adding ExVectr Libraries:##
Simply copy or clone them as submodules into the lib folder. Cloning can be done by opening a terminal inside the main project folder and typing:
- git submodule add https://github.com/ExVectr/ExVectrCore.git ./lib/ExVectrCore
Keep in mind that the library folder must have the exact name of the library.
