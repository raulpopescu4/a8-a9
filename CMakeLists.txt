cmake_minimum_required(VERSION 3.21)
project(a8_a9)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(domain)
include_directories(repository)
include_directories(service)
include_directories(UI)

add_executable(a8_a9
        domain/Tutorial.cpp
        domain/Tutorial.h
        repository/CSVRepository.cpp
        repository/CSVRepository.h
        repository/HTMLRepository.cpp
        repository/HTMLRepository.h
        repository/Repository.cpp
        repository/Repository.h
        repository/UserRepository.cpp
        repository/UserRepository.h
        service/Service.cpp
        service/Service.h
        service/UserService.cpp
        service/UserService.h
        UI/UI.cpp
        UI/UI.h
        Exceptions.cpp
        Exceptions.h
        main.cpp
        TutorialValidator.cpp
        TutorialValidator.h)
