add_library(
  fileSearcher STATIC
  fileSearcher.c
)

target_include_directories (
  fileSearcher PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
