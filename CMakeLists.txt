cmake_minimum_required(VERSION 3.30)
project(9_practica_contenedores_toreno_AndresLopez701)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(9_practica_contenedores_toreno_AndresLopez701
    Jugador.cpp
    Jugador.h
    main.cpp
    main.h
    Torneo.cpp
    Torneo.h
    Videojuego.cpp
    Videojuego.h)
