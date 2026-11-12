cmake_minimum_required(VERSION 4.3)
project(projeto_final_ C)

set(CMAKE_C_STANDARD 11)

include_directories(patas)

add_executable(projeto_final_
        patas/arvore.c
        patas/arvore.h
        patas/cadastro.c
        patas/cadastro.h
        patas/imagens.c
        patas/lista.c
        patas/lista.h
        patas/main.c)
