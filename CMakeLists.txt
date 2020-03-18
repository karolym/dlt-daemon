cmake_minimum_required(VERSION 3.16)
include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(dlt_lib)

zephyr_get_include_directories_for_lang_as_string(       C includes)
zephyr_get_system_include_directories_for_lang_as_string(C system_includes)
zephyr_get_compile_definitions_for_lang_as_string(       C definitions)
zephyr_get_compile_options_for_lang_as_string(           C options)

set(external_project_cflags
  "${includes} ${definitions} ${options} ${system_includes}"
  )

include(ExternalProject)

if(CMAKE_GENERATOR STREQUAL "Unix Makefiles")
# https://www.gnu.org/software/make/manual/html_node/MAKE-Variable.html
set(submake "$(MAKE)")
else() # Obviously no MAKEFLAGS. Let's hope a "make" can be found somewhere.
set(submake "make")
endif()

ExternalProject_Add(
	automotive-dlt
  )

option(BUILD_SHARED_LIBS OFF)
option(WITH_DLT_CONSOLE OFF)
option(WITH_DLT_EXAMPLES OFF)
option(WITH_DLT_PKGCONFIG OFF)
option(WITH_DLT_TESTS OFF)
set(DLT_IPC UNIX_SOCKET)
include(CMakeLists.txt.in)

