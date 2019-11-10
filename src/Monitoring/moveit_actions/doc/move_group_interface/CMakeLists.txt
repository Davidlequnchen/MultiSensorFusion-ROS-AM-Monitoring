add_executable(abb_move_group_interface src/abb_move_group_interface.cpp)
target_link_libraries(abb_move_group_interface ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS abb_move_group_interface DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
