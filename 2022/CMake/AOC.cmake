set(AOC_COMPILER_OPTIONS
    -std=c++20
    -fdiagnostics-show-template-tree
    -pedantic-errors
    -Walloca
    -Wcast-align=strict
    -Wcast-qual
    -Wconversion
    -Wdate-time
    -Wduplicated-branches
    -Wduplicated-cond
    -Werror
    -Wextra-semi
    -Wfloat-equal
    -Wformat=2
    -Winvalid-pch
    -Wlogical-op
    -Wmissing-declarations
    -Wmissing-include-dirs
    -Wnoexcept
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wpedantic
    -Wplacement-new=2
    -Wredundant-decls
    -Wregister
    -Wshadow
    -Wsign-promo
    -Wsubobject-linkage
    -Wswitch-default
    -Wswitch-enum
    -Wtrampolines
    -Wundef
    -Wunused
    -Wunused-macros
    -Wuseless-cast
    -Wzero-as-null-pointer-constant
    -Wall
    -Wextra
    "$<$<CONFIG:Debug>:-fstack-protector-strong>"
    "$<$<CONFIG:Debug>:-Wstack-protector>"
    "$<$<CONFIG:Debug>:-ggdb>"
)

function(add_aoc_executable)
  add_executable(${ARGN})
  target_compile_options(${ARGV0} PRIVATE ${AOC_COMPILER_OPTIONS})
endfunction()

function(add_aoc_library)
  add_library(${ARGN})
  if(${ARGV1} STREQUAL INTERFACE)
    set(property_scope INTERFACE)
  else()
    set(property_scope PUBLIC)
  endif()
  add_library(AOC::${ARGV0} ALIAS ${ARGV0})
  target_compile_options(${ARGV0} ${property_scope} ${AOC_COMPILER_OPTIONS})
  set_target_properties(${ARGV0} PROPERTIES LINKER_LANGUAGE CXX)
  target_compile_features(${ARGV0} ${property_scope} cxx_std_20)
  target_include_directories(
    ${ARGV0} ${property_scope} "${CMAKE_CURRENT_SOURCE_DIR}"
  )
endfunction()
