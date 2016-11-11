cmake_minimum_required(VERSION 3.6)
project(EngineeringWork)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(C:/mingw-w64/i686-6.2.0-posix-dwarf-rt_v5-rev1/mingw32/i686-w64-mingw32/include)

add_executable(EngineeringWork src/main.cpp
        src/cam_device/CamDevice.h
        src/cam_device/CamDevice.cpp
        src/propertie/AppProperties.h
        src/propertie/AppProperties.cpp
        src/propertie/Property.h
        src/propertie/PropertyTypes.h
        src/propertie/ListCamDevice.cpp
        src/propertie/ListCamDevice.h
        src/initialize/AppInit.cpp
        src/initialize/AppInit.h src/initialize/CamDevicesListInit.cpp)

target_link_libraries(EngineeringWork
        C:/mingw-w64/i686-6.2.0-posix-dwarf-rt_v5-rev1/mingw32/i686-w64-mingw32/lib/libstrmiids.a)