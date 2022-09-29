add_executable(2022-circle circle.c)

add_executable(2022-sphere sphere.c)
target_link_libraries(2022-sphere m)

add_executable(2022-mol mol.c)

add_executable(2022-admin admin.c)
target_link_libraries(2022-admin m)

add_executable(2022-admin-scanf admin-scanf.c)
target_link_libraries(2022-admin-scanf m)