# add the executable
add_executable(Test_Flat_Sample Test_Flat_Sample.c)

# include files from ProjectB
include_directories(${CMAKE_SOURCE_DIR}/Median_Library) 

# Link the library
target_link_libraries(Test_Flat_Sample Median_Library)

install(TARGETS Test_Flat_Sample RUNTIME DESTINATION bin)


