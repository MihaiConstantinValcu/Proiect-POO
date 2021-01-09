cmake_minimum_required(VERSION 3.17)
project(ProiectPOO)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Weffc++")

add_executable(ProiectPOO main.cpp Include/Animal.h Source/Animal.cpp Include/Planta.h Source/Planta.cpp Include/Soi.h Source/Soi.cpp Include/Colonie.h Source/Colonie.cpp Include/Ecosistem.h Source/Ecosistem.cpp Include/EcosistemArtificial.h Source/EcosistemArtificial.cpp Include/Tester.h Source/Tester.cpp Include/AnimalFactory.h Source/AnimalFactory.cpp Include/PlantaFactory.h Source/PlantaFactory.cpp)