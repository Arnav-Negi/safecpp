file(GLOB headers ../safe/*.h)
file(GLOB sources *.cpp)

add_executable(safe_cpp ${headers} ${sources})
target_link_directories(safe_cpp PUBLIC ../safe)
