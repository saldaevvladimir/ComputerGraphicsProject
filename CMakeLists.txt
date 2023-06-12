# project

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED true)


project(GraphicsEngine VERSION 3.0)

# JSONCPP

find_package(PkgConfig REQUIRED)

pkg_check_modules(JSONCPP jsoncpp)

include_directories(${JSONCPP_INCLUDE_DIRS})
link_directories(${JSONCPP_LIBRARY_DIRS})

# EXCEPTIONS

add_library(MATH_EXCEPTION 
    STATIC lib/Exceptions/MathExceptions/MathException.cpp
)

add_library(ENGINE_EXCEPTION
    STATIC lib/Exceptions/EngineExceptions/EngineException.cpp
)

# MATH

add_library(ACCURACY 
    STATIC lib/Math/Accuracy/Accuracy.cpp
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

add_library(GAME_ENTITY
    STATIC ./lib/Engine/BasicClasses/Game/GameEntity/GameEntity.cpp
)

add_library(GAME_OBJECT
    STATIC ./lib/Engine/BasicClasses/Game/Object/Object.cpp
)

add_library(GAME_CAMERA
    STATIC ./lib/Engine/BasicClasses/Game/Camera/Camera.cpp
)

add_library(CANVAS
    STATIC ./lib/Engine/BasicClasses/Canvas/Canvas.cpp
)

add_library(HYPER_PLANE
    STATIC ./lib/Engine/BasicClasses/Game/HyperPlane/HyperPlane.cpp
)

add_library(HYPER_ELLIPSOID
    STATIC ./lib/Engine/BasicClasses/Game/HyperEllipsoid/HyperEllipsoid.cpp
)

add_library(EVENT_SYSTEM
    STATIC ./lib/Engine/BasicClasses/EventSystem/EventSystem.cpp
)

add_library(CONFIGURATION
    STATIC ./lib/Engine/BasicClasses/Configuration/Configuration.cpp
)

add_library(CONSOLE
    STATIC ./lib/Engine/BasicClasses/Game/Console/Console.cpp
)


target_link_libraries(RAY
    PUBLIC COORDINATE_SYSTEM
)

target_link_libraries(ENTITY
    PUBLIC IDENTIFIER
    PUBLIC RAY
)

target_link_libraries(ENTITIES_LIST
    PUBLIC ENTITY
    PUBLIC ENGINE_EXCEPTION
)

target_link_libraries(CONFIGURATION
    PUBLIC ENGINE_EXCEPTION
    PUBLIC ${JSONCPP_LIBRARIES}
)

target_link_libraries(GAME
    PUBLIC RAY
    PUBLIC ENTITIES_LIST
    PUBLIC MATH_EXCEPTION
    PUBLIC CONFIGURATION
    PUBLIC EVENT_SYSTEM
)

target_link_libraries(GAME_ENTITY
    PUBLIC GAME
)

target_link_libraries(GAME_OBJECT
    PUBLIC GAME
    PUBLIC GAME_ENTITY
)

target_link_libraries(GAME_CAMERA
    PUBLIC GAME_OBJECT
)

target_link_libraries(CANVAS
    PUBLIC MATRIX
    PUBLIC GAME
    PUBLIC GAME_CAMERA
)

target_link_libraries(HYPER_PLANE
    PUBLIC GAME
)

target_link_libraries(HYPER_ELLIPSOID
    PUBLIC GAME
)

target_link_libraries(CONSOLE
    PUBLIC CANVAS
    PUBLIC MATRIX
)

add_library(ENGINE_BASIC_CLASSES
    STATIC lib/Engine/BasicClasses/AllBasicClasses/AllBasicClasses.cpp
)

target_link_libraries(ENGINE_BASIC_CLASSES
    PUBLIC RAY
    PUBLIC IDENTIFIER
    PUBLIC ENTITY
    PUBLIC ENTITIES_LIST
    PUBLIC GAME
    PUBLIC GAME_ENTITY
    PUBLIC GAME_OBJECT
    PUBLIC GAME_CAMERA
    PUBLIC CANVAS
    PUBLIC HYPER_PLANE
    PUBLIC HYPER_ELLIPSOID
    PUBLIC EVENT_SYSTEM
    PUBLIC CONFIGURATION
    PUBLIC CONSOLE
)

# ENGINE_VISUALIZATION



# Tests

enable_testing()

link_directories(./googletest/lib)

include_directories(./googletest/googletest/include)


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

# copying binary files frome /build/ to /bin/

file(GLOB EXECUTABLES
    "${CMAKE_CURRENT_SOURCE_DIR}/build/*.exe"
)

file(COPY ${EXECUTABLES} DESTINATION
    ${CMAKE_CURRENT_SOURCE_DIR}/bin/
)