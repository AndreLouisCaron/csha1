# sha1 library demo projects.

set(sources
  sha.cpp
)
add_executable(sha
  ${headers}
  ${sources}
)
target_link_libraries(sha sha1)
add_dependencies(sha sha1)

set(sources
  demo.cpp
)
add_executable(demo
  ${headers}
  ${sources}
)
target_link_libraries(demo sha1)
add_dependencies(demo sha1)
