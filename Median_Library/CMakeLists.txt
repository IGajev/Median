add_library(Median_Library Median.c)

install(TARGETS Median_Library
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
