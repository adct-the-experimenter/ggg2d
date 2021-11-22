cmake_minimum_required(VERSION 3.1.1)


set(PROJECT_NAME stick-figure-control)
project (${PROJECT_NAME} LANGUAGES C)



#-DCMAKE_BUILD_TYPE=Release
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_C_FLAGS} -g -Wall -fPIE")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_C_FLAGS} -Wall -fPIE")



#SDL2 specific stuff and its add on libraries
INCLUDE(FindPkgConfig)

#pkg_check_modules(openal REQUIRED openal)

# Let CMake search for a raylib-config.cmake
find_package(raylib 3.5 QUIET) 

set ( PROJECT_LINK_LIBS  raylib )


#For the shared library:
link_directories( /usr/lib /usr/local/lib) 
 

set ( PROJECT_INCLUDE_DIR  ../ ../../../ggg2d-core )
include_directories(/usr/include /usr/local/include ${PROJECT_INCLUDE_DIR})


if (MINGW)
    # need to link with mingw32 before SDL2
    list(APPEND _link_libraries mingw32)
endif ()

if(WIN32)
	set ( PROJECT_LINK_LIBS  ${PROJECT_LINK_LIBS} opengl32 gdi32 winmm)
	set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -DWITH_WINMM")
endif()


#Specific thread library linking to make miniaudio work
if( ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD" )
	set ( PROJECT_LINK_LIBS  ${PROJECT_LINK_LIBS} pthread m )
	set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -pthread")
	message( STATUS "System detected is FreeBSD")
	
elseif( ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
	set ( PROJECT_LINK_LIBS  ${PROJECT_LINK_LIBS} pthread m dl )
	set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -pthread")
	message(STATUS "System detected is Linux")
else ()

endif()


set(SOURCES stick-figure-control-raylib.c
			../../../ggg2d-core/ggg-2d.c
			 )

#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()

#make executable sphere from simple-sphere.cpp 
add_executable(${PROJECT_NAME} ${SOURCES})
#link libraries
target_link_libraries(${PROJECT_NAME} ${PROJECT_LINK_LIBS} )
