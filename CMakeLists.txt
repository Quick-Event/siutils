cmake_minimum_required(VERSION 3.18.4)
project(libsiut LANGUAGES CXX)

# set(LIBSIUT_USE_QT6 ON CACHE BOOL "Qt6 build")
set(BUILD_SHARED_LIBS ON CACHE BOOL "Build shared libraries instead of static")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_SHARED_LIBRARY_PREFIX "") # we don't want CMake to prepend "lib" to our libraries, we prefer adding that ourselves

message(STATUS "Enabling Qt6 support")
find_package(Qt6 COMPONENTS Core SerialPort LinguistTools)
set(Qt_FOUND ${Qt6_FOUND})

add_library(libsiut SHARED
    src/device/crc529.c
    src/device/commport.cpp
    src/device/sidevicedriver.cpp
    src/device/sitask.cpp
    src/message/simessagedata.cpp
    src/sicard.cpp
    src/sipunch.cpp
    )

add_subdirectory(3rdparty/necrolog)

qt6_add_translation(QM_FILES
	libsiut-cs_CZ.ts
	libsiut-fr_FR.ts
	libsiut-nb_NO.ts
	libsiut-nl_BE.ts
	libsiut-pl_PL.ts
	libsiut-ru_RU.ts
	libsiut-uk_UA.ts
)

target_sources(libsiut PRIVATE ${QM_FILES})
target_compile_definitions(libsiut PRIVATE SIUT_BUILD_DLL)
target_link_libraries(libsiut PUBLIC Qt::Core Qt::SerialPort libnecrolog)
target_include_directories(libsiut PUBLIC include)

install(TARGETS libsiut)
install(FILES ${QM_FILES} DESTINATION ${CMAKE_INSTALL_BINDIR}/translations)
