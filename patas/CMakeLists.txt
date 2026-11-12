cmake_minimum_required(VERSION 4.3)
project(patas C)

set(CMAKE_C_STANDARD 23)

add_executable(patas main.c
        cadastro.h
        cadastro.c
        lista.c
        lista.h
        arvore.h
        arvore.c)
