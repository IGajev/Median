# add the executable
add_executable(Test_Init Test_Init.c)

# include files from ProjectB
include_directories(${CMAKE_SOURCE_DIR}/Median_Library) 

# Link the library
target_link_libraries(Test_Init Median_Library)

install(TARGETS Test_Init RUNTIME DESTINATION bin)


