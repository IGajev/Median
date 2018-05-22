# add the executable
add_executable(Test_Decreasing_Sample Test_Decreasing_Sample.c)

# include files from ProjectB
include_directories(${CMAKE_SOURCE_DIR}/Median_Library) 

# Link the library
target_link_libraries(Test_Decreasing_Sample Median_Library)

install(TARGETS Test_Decreasing_Sample RUNTIME DESTINATION bin)


