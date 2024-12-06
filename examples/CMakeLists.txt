file(GLOB headers ../safe/*.h)
file(GLOB sources *.cpp)

add_executable(must_init ${headers} must_init.cpp)
target_link_directories(must_init PUBLIC ../safe)

add_executable(bounds ${headers} bounds.cpp)
target_link_directories(bounds PUBLIC ../safe)

add_executable(safe_int ${headers} safe_int.cpp)
target_link_directories(safe_int PUBLIC ../safe)
