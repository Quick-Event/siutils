cmake_minimum_required(VERSION 3.18.4)
project(libsiut LANGUAGES CXX)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_SHARED_LIBRARY_PREFIX "") # we don't want CMake to prepend "lib" to our libraries, we prefer adding that ourselves

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(NECROLOG_WARNING_FLAGS "-Wall -Wextra -pedantic -Wshadow -Wcast-align -Wunused -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual")

	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(NECROLOG_WARNING_FLAGS "-Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast ${NECROLOG_WARNING_FLAGS}")
	endif()

	set(CMAKE_CXX_FLAGS "${NECROLOG_WARNING_FLAGS} ${CMAKE_CXX_FLAGS}")
endif()

add_library(libsiut SHARED
    src/device/crc529.c
    src/device/commport.cpp
    src/device/sidevicedriver.cpp
    src/device/sitask.cpp
    src/message/simessagedata.cpp
    src/sicard.cpp
    src/sipunch.cpp
    )

if(USE_QT6)
	qt6_add_translation(QM_FILES
        libsiut-cs_CZ.ts
        libsiut-fr_FR.ts
        libsiut-nb_NO.ts
        libsiut-nl_BE.ts
        libsiut-pl_PL.ts
        libsiut-ru_RU.ts
        libsiut-uk_UA.ts
        )
else()
    qt5_add_translation(QM_FILES
        libsiut-cs_CZ.ts
        libsiut-fr_FR.ts
        libsiut-nb_NO.ts
        libsiut-nl_BE.ts
        libsiut-pl_PL.ts
        libsiut-ru_RU.ts
        libsiut-uk_UA.ts
        )
endif()

target_sources(libsiut PRIVATE ${QM_FILES})
target_compile_definitions(libsiut PRIVATE SIUT_BUILD_DLL)
target_link_libraries(libsiut PUBLIC Qt::Core Qt::SerialPort libnecrolog)
target_include_directories(libsiut PUBLIC include)

install(TARGETS libsiut)
install(FILES ${QM_FILES} DESTINATION ${CMAKE_INSTALL_BINDIR}/translations)
