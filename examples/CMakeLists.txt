file(GLOB headers ../safe/*.h)

add_executable(must_init ${headers} must_init.cpp)
target_include_directories(must_init PRIVATE ${CMAKE_SOURCE_DIR}/safe)

add_executable(bounds ${headers} bounds.cpp)
target_include_directories(bounds PRIVATE ${CMAKE_SOURCE_DIR}/safe)

add_executable(safe_int ${headers} safe_int.cpp)
target_include_directories(safe_int PRIVATE ${CMAKE_SOURCE_DIR}/safe)
