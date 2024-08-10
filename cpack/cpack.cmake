set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME "wind-core")

set(CPACK_SOURCE_IGNORE_FILES
  "/build/;/.git/;/.vscode/;/CMakeFiles/;/CMakeCache.txt;/Makefile;/cmake_install.cmake"
)


install(DIRECTORY "${CMAKE_SOURCE_DIR}/wind/core/" DESTINATION ".")

message("Here: ${CMAKE_SOURCE_DIR}")

include(CPack)
