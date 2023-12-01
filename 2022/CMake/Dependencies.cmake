message(CHECK_START "Updating dependencies")
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${CMAKE_SOURCE_DIR}/.git")
  execute_process(
    COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    RESULT_VARIABLE GIT_SUBMOD_RESULT
    OUTPUT_VARIABLE GIT_SUBMOD_OUTPUT
    ERROR_VARIABLE GIT_SUBMOD_OUTPUT
    OUTPUT_STRIP_TRAILING_WHITESPACE ERROR_STRIP_TRAILING_WHITESPACE
  )
  if(GIT_SUBMOD_RESULT EQUAL "0")
    message(CHECK_PASS "done")
  else()
    message(CHECK_FAIL "failed")
    message(FATAL_ERROR " git submodule update --init --recursive\n \n"
                        " ${GIT_SUBMOD_OUTPUT}"
    )
  endif()
else()
  message(CHECK_PASS "skipped")
endif()

function(fix_dependencies)
  foreach(tgt IN ITEMS ${ARGN})
    if(NOT TARGET ${tgt})
      message(AUTHOR_WARNING "${tgt} is not a target.")
    else()
      message(STATUS "Fixing target ${tgt}")
      get_target_property(real_target ${tgt} ALIASED_TARGET)
      if(NOT real_target)
        set(real_target ${tgt})
      endif()
      get_target_property(directories ${real_target} INCLUDE_DIRECTORIES)
      if(directories)
        target_include_directories(${real_target} SYSTEM PUBLIC ${directories})
      endif()
    endif()
  endforeach()
endfunction()
