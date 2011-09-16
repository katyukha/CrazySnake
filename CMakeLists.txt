cmake_minimum_required ( VERSION 2.8)
project (Snake)
include_directories ("${PROJECT_SOURCE_DIR}")


# Searching for OpenGL library
find_package(OpenGL REQUIRED)
if( NOT OPENGL_FOUND)
    message(ERROR, " OpenGL not found!")
else()
    set(LIBRARIES ${OPENGL_LIBRARIES})
endif()

# Searching for Glut library
find_package(GLUT REQUIRED)
if( NOT GLUT_FOUND )
    message(ERROR, " Glut not found!")
else()
    set(LIBRARIES ${LIBRARIES} ${GLUT_glut_LIBRARY})
endif()

# Project sources
add_executable(Snake 
                       main.cpp 
                       Application.cpp 
                       BaseEventHandler.cpp 
                       CollisionChecker.cpp 
                       CollisionObject.cpp 
                       SnakeHead.cpp 
                       SnakeSegment.cpp 
                       Timer.cpp)

#Link Libraries
target_link_libraries(Snake ${LIBRARIES} )

