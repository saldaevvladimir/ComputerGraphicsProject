# project

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDART 14)
set(CMAKE_CXX_STANDART_REQUIRED true)


project(GraphicsEngine VERSION 3.0)

# MATH

add_library(ACCURACY 
    STATIC lib/Math/Accuracy/Accuracy.cpp
)

add_library(MATH_EXCEPTION 
    STATIC lib/Exceptions/MathExceptions/MathException.cpp
)

add_library(MATRIX
    STATIC lib/Math/Matrix/Matrix.cpp
)

add_library(VECTOR
    STATIC lib/Math/Vector/Vector.cpp
)

add_library(POINT 
    STATIC lib/Math/Point/Point.cpp
)

add_library(FUNCTIONS 
    STATIC lib/Math/Functions/Functions.cpp
)

add_library(VECTOR_SPACE 
    STATIC lib/Math/VectorSpace/VectorSpace.cpp
)

add_library(COORDINATE_SYSTEM
    STATIC lib/Math/CoordinateSystem/CoordinateSystem.cpp
)

target_link_libraries(MATRIX 
    PUBLIC MATH_EXCEPTION 
    PUBLIC ACCURACY
)

target_link_libraries(VECTOR
    PUBLIC MATRIX
)

target_link_libraries(POINT 
    PUBLIC VECTOR
)

target_link_libraries(FUNCTIONS 
    PUBLIC VECTOR
)

target_link_libraries(VECTOR_SPACE 
    PUBLIC POINT
    PUBLIC FUNCTIONS
)

target_link_libraries(COORDINATE_SYSTEM
    PUBLIC VECTOR_SPACE
)

add_library(ALL_MATH 
    STATIC lib/Math/AllMath/AllMath.cpp
)

target_link_libraries(ALL_MATH
    PUBLIC ACCURACY
    PUBLIC MATH_EXCEPTION
    PUBLIC MATRIX
    PUBLIC VECTOR
    PUBLIC POINT
    PUBLIC FUNCTIONS
    PUBLIC VECTOR_SPACE
    PUBLIC COORDINATE_SYSTEM
)
        
# ENGINE_BASIC_CLASSES

add_library(RAY 
    STATIC ./lib/Engine/BasicClasses/Ray/Ray.cpp
)

add_library(IDENTIFIER
    STATIC ./lib/Engine/BasicClasses/Identifier/Identifier.cpp
)

add_library(ENTITY
    STATIC ./lib/Engine/BasicClasses/Entity/Entity.cpp
)

add_library(ENTITIES_LIST
    STATIC ./lib/Engine/BasicClasses/EntitiesList/EntitiesList.cpp
)

add_library(GAME
    STATIC ./lib/Engine/BasicClasses/Game/Game.cpp
)

add_library(GAME_OBJECT
    STATIC ./lib/Engine/BasicClasses/Game/Object/Object.cpp
)

add_library(GAME_CAMERA
    STATIC ./lib/Engine/BasicClasses/Game/Camera/Camera.cpp
)


target_link_libraries(RAY
    PUBLIC COORDINATE_SYSTEM
)

target_link_libraries(ENTITY
    PUBLIC IDENTIFIER
    PUBLIC COORDINATE_SYSTEM
)

target_link_libraries(ENTITIES_LIST
    PUBLIC ENTITY
)

target_link_libraries(GAME
    PUBLIC RAY
    PUBLIC ENTITIES_LIST
)

target_link_libraries(GAME_OBJECT
    PUBLIC GAME
)

target_link_libraries(GAME_CAMERA
    PUBLIC GAME_OBJECT
)


add_library(ENGINE_BASIC_CLASSES
    STATIC lib/Engine/BasicClasses/AllBasicClasses/AllBasicClasses.cpp
)

target_link_libraries(ENGINE_BASIC_CLASSES
    PUBLIC RAY
    PUBLIC IDENTIFIER
    PUBLIC ENTITY
    PUBLIC ENTITIES_LIST
    PUBLIC GAME_CAMERA
)

# ENGINE_VISUALIZATION



# GoogleTests libs

# local gtests
# link_directories(C:/MinGW/lib)
# include_directories(C:/Mingw/include)

link_directories(./googletest/glib)
include_directories(./googletest/include)

# Tests

add_executable(MathTests 
    ./tests/UnitTests/MathTests.cpp
)

add_executable(EngineTests 
    ./tests/UnitTests/EngineTests.cpp
)

add_executable(GameTests 
    ./tests/UnitTests/GameTests.cpp
)

target_link_libraries(MathTests
    PUBLIC gtest
    PUBLIC gtest_main
    PUBLIC ALL_MATH
)

target_link_libraries(EngineTests
    PUBLIC gtest
    PUBLIC gtest_main
    PUBLIC ENGINE_BASIC_CLASSES
)

target_link_libraries(GameTests
    PUBLIC gtest
    PUBLIC gtest_main
    PUBLIC ENGINE_BASIC_CLASSES
)


add_test(
    NAME MathTests
    COMMAND $<TARGET_FILE:MathTests>
)

add_test(
    NAME EngineTests
    COMMAND $<TARGET_FILE:EngineTests>
)

add_test(
    NAME GameTests
    COMMAND $<TARGET_FILE:GameTests>
)


# GraphicsEngine (main target)

add_executable(GraphicsEngine src/Main.cpp)

target_link_libraries(GraphicsEngine
    PUBLIC ALL_MATH
    PUBLIC ENGINE_BASIC_CLASSES
)

