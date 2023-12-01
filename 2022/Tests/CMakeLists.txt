set(TESTS
    Day01
    Day02
    Day03
    Day04
    Day05
    Day06
    Day07
    Day08
    Day09
)
foreach(test IN LISTS TESTS)
  add_aoc_executable(${test} ${test}.cpp)
  target_link_libraries(
    ${test} PRIVATE AOC::Challenges AOC::Utils Catch2::Catch2WithMain
  )
  configure_file(Input/${test}.txt ${test}.txt COPYONLY)
  catch_discover_tests(${test} PROPERTIES LABELS unit)
endforeach()
