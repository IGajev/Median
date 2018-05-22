# add the executable
add_executable(Test_Increasing_Sample Test_Increasing_Sample.c)

# include files from ProjectB
include_directories(${CMAKE_SOURCE_DIR}/Median_Library) 

# Link the library
target_link_libraries(Test_Increasing_Sample Median_Library)

install(TARGETS Test_Increasing_Sample RUNTIME DESTINATION bin)


