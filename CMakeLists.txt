cmake_minimum_required ( VERSION 2.8)
project (Snake)
add_executable(Snake main.cpp Application.cpp BaseEventHandler.cpp CollisionChecker.cpp CollisionObject.cpp SnakeHead.cpp SnakeSegment.cpp Timer.cpp)
include_directories ("${PROJECT_SOURCE_DIR}")

