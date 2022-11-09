add_executable(2022-int-limits int-limits.c)
add_executable(2022-float-limits float-limits.c)

add_executable(2022-fp fp.c)
add_executable(2022-loop loop.c)
add_executable(2022-sums sums.c)

add_executable(2022-compare compare.c)
target_link_libraries(2022-compare m)

add_executable(2022-rand rand.c)