# add the executable
add_executable(Test_Middle_Around_Flat Test_Middle_Around_Flat.c)

# include files from ProjectB
include_directories(${CMAKE_SOURCE_DIR}/Median_Library) 

# Link the library
target_link_libraries(Test_Middle_Around_Flat Median_Library)

install(TARGETS Test_Middle_Around_Flat RUNTIME DESTINATION bin)


