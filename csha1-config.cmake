# Library configuration file used by dependent projects
# via find_package() built-in directive in "config" mode.

if(NOT DEFINED csha1_FOUND)

  # Locate library headers.
  find_path(csha1_include_dirs
    NAMES sha-1.h
    PATHS ${csha1_DIR}/code
  )

  # Common name for exported library targets.
  set(csha1_libraries
    sha1
    CACHE INTERNAL "csha1 library" FORCE
  )

  # Usual "required" et. al. directive logic.
  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(
    csha1 DEFAULT_MSG
    csha1_include_dirs
    csha1_libraries
  )

  # Add targets to dependent project.
  add_subdirectory(
    ${csha1_DIR}
    ${CMAKE_BINARY_DIR}/csha1
  )
endif()
