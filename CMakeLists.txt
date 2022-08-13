cmake_minimum_required(VERSION 3.5)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++14")
# --------- ONLY For My Laptop, TO BE REMOVED-------------
if (${BUILD_MACHINE} STREQUAL "MY_LAPTOP")
    message("LOADING KIM API FROM MODULES")
    find_package(EnvModules REQUIRED)
    env_module(load kim_api)
    env_module(load python39)
endif ()
# --------------------------------------------------------

# set the project name
project(MDStressLab++ VERSION 1.0)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include/MDStressLab++)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(unit_tests)

find_package(PythonInterp REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(pybind11/include)

add_subdirectory(pybind11)
include_directories("include/MDStressLab++/Eigen")
include_directories("include/MDStressLab++")
pybind11_add_module(pymdstresslab py_modules.cpp
                        src/BoxConfiguration.cpp
                        src/Configuration.cpp
                        src/neighbor_list.cpp)
