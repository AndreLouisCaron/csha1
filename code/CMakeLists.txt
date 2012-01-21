# sha1 library.

set(headers
  sha-1.h
)
set(sources
  sha-1.c
)
add_library(sha1
  STATIC
  ${headers}
  ${sources}
)
