cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(jnilibs ${CMAKE_SOURCE_DIR}/../jniLibs)
set(libname my_mavlink_demo)

include_directories(Demo_heart)

link_directories(
        ${jnilibs}/${ANDROID_ABI})

file(GLOB src-files
        ${CMAKE_SOURCE_DIR}/*.hpp
        ${CMAKE_SOURCE_DIR}/*.h
        ${CMAKE_SOURCE_DIR}/*.cpp
        ${CMAKE_SOURCE_DIR}/Demo_heart/*.hpp
        ${CMAKE_SOURCE_DIR}/Demo_heart/*.h
        ${CMAKE_SOURCE_DIR}/Demo_heart/gtestuite.hpp
        )



add_library( # Sets the name of the library.
        ${libname}

        # Sets the library as a shared library.
        SHAR

        # Provides a relative path to your source file(s).
        ${src-files}
        )

set(native-libs
        android
        mediandk
        EGL
        GLESv3
        OpenSLES
        log
        m
        z
        )

target_link_libraries( # Specifies the target library.
        ${libname}

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
        ${third-party-libs}
        ${native-libs}
        ${GTEST_INCLUDE_DIRS}
        )