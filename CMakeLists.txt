cmake_minimum_required(VERSION 3.8)
project(bitwa)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -Werror -Wpedantic")

add_executable(bitwa main.cpp bitwa/Gra.cpp bitwa/Gra.h bitwa/Gracz.cpp bitwa/Gracz.h bitwa/pole/PoleBitwy.cpp bitwa/pole/PoleBitwy.h bitwa/pole/Pole.cpp bitwa/pole/Pole.h bitwa/pole/PolePierwszejLinii.cpp bitwa/pole/PolePierwszejLinii.h bitwa/wojsko/oddzial/SRC/Oddzial.cpp bitwa/wojsko/oddzial/Headers/Oddzial.h bitwa/wojsko/Wojsko.cpp bitwa/wojsko/Wojsko.h bitwa/pole/PoleDrugiejLinii.cpp bitwa/pole/PoleDrugiejLinii.h bitwa/pole/PolePosilkow.cpp bitwa/pole/PolePosilkow.h bitwa/wojsko/oddzial/SRC/Zwarcie.cpp bitwa/wojsko/oddzial/Headers/Zwarcie.h bitwa/wojsko/oddzial/SRC/Wsparcie.cpp bitwa/wojsko/oddzial/Headers/Wsparcie.h bitwa/wojsko/oddzial/SRC/Zasiegowa.cpp bitwa/wojsko/oddzial/Headers/Zasiegowa.h bitwa/wojsko/oddzial/SRC/Konny.cpp bitwa/wojsko/oddzial/Headers/Konny.h bitwa/wojsko/oddzial/SRC/Tarczownik.cpp bitwa/wojsko/oddzial/Headers/Tarczownik.h bitwa/wojsko/oddzial/SRC/Kusznik.cpp bitwa/wojsko/oddzial/Headers/Kusznik.h bitwa/wojsko/oddzial/SRC/Bebniarz.cpp bitwa/wojsko/oddzial/Headers/Bebniarz.h bitwa/wojsko/oddzial/SRC/Halabardzista.cpp bitwa/wojsko/oddzial/Headers/Halabardzista.h bitwa/wojsko/oddzial/SRC/Miecznik.cpp bitwa/wojsko/oddzial/Headers/Miecznik.h bitwa/wojsko/oddzial/SRC/Lucznik.cpp bitwa/wojsko/oddzial/Headers/Lucznik.h)