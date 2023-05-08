include(${CMAKE_SCRIPTS_DIR}/googletest.cmake)

add_executable(
  opengl-starter-test
  test_main.cpp
)

target_link_libraries(
  opengl-starter-test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(opengl-starter-test)
