cmake_minimum_required(VERSION 3.8)
project(bitwa)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -Wall)

add_executable(bitwa main.cpp bitwa/Gra.cpp bitwa/Gra.h bitwa/Gracz.cpp bitwa/Gracz.h bitwa/pole/PoleBitwy.cpp bitwa/pole/PoleBitwy.h bitwa/pole/Pole.cpp bitwa/pole/Pole.h bitwa/pole/PolePierwszejLinii.cpp bitwa/pole/PolePierwszejLinii.h bitwa/wojsko/oddzial/Oddzial.cpp bitwa/wojsko/oddzial/Oddzial.h bitwa/wojsko/Wojsko.cpp bitwa/wojsko/Wojsko.h bitwa/pole/PoleDrugiejLinii.cpp bitwa/pole/PoleDrugiejLinii.h bitwa/pole/PolePosilkow.cpp bitwa/pole/PolePosilkow.h)