cmake_minimum_required(VERSION 3.0.0)
project(ExVectrProjectTemplate VERSION 0.1.0) #Your project name here instead of ExVectrProjectTemplate


file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)


function(addExVectrLibrary libName)
    add_subdirectory(lib/${libName})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${libName})
endfunction()

#Add ExVectr libraries here. You must pay attention to their dependecies. Just head into each ExVectr libraries CMakeLists.txt files and check addExVectrDependency() calls.

addExVectrLibrary(ExVectrCore)
addExVectrLibrary(ExVectrHAL)

#End of libraries

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 