cmake_minimum_required(VERSION 2.8.3)
project(sandbox_robot_navigation)

find_package(catkin REQUIRED
    COMPONENTS
    cmake_modules
    roscpp
    #tf
    #costmap_2d
    #mbf_costmap_core
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

catkin_package(
    CATKIN_DEPENDS
    roscpp
)

add_executable(simple_navigation_goals_tests src/navigation_test.cpp)
add_dependencies(simple_navigation_goals_tests ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(simple_navigation_goals_tests ${catkin_LIBRARIES})


#add_executable(costmap_saver_node src/costmap_saver.cpp)
#add_dependencies(costmap_saver_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
#target_link_libraries(costmap_saver_node ${catkin_LIBRARIES})



