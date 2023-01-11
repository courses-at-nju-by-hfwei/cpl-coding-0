add_executable(2022-int-limits int-limits.c)
add_executable(2022-int-overflow int-overflow.c)

add_executable(2022-unsigned unsigned.c)
add_executable(2022-timing timing.c)

add_executable(2022-char char.c)

add_executable(2022-implicit-conversion implicit-conversion.c)
add_executable(2022-explict-conversion explict-conversion.c)

add_executable(2022-float-limits float-limits.c)

add_executable(2022-sums sum-product.c)
add_executable(2022-loop loop.c)

add_executable(2022-compare compare.c)
target_link_libraries(2022-compare m)