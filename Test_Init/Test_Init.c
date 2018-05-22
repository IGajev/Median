/*
 * Test_Init.c
 *
 *  Created on: May 17, 2018
 *      Author: gajev
 */


#include "Median.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define output_init ((data_type) 0.0)

typedef unsigned int uint_type;
typedef time_t time_type;

uint_type TestInit(void)
{
    uint_type failure_indicator = 0;
    data_type inputL;
    data_type outputL;
    time_type t;

    /* Initializes random number generator */
    srand( (uint_type) time(&t) );

    /* Generate a random number */
    inputL = rand();

    printf("********************************************************************************\n");
    printf("Test: Testing empty sample, output median must be 0 \n");
    printf("********************************************************************************\n\n");

    outputL = Return_Median();

    if ( outputL == output_init )
    {
        printf("Test No. %d ------------------> OK\n\n", 1);
    }

    else
    {
        printf("Test No. %d ------------------> FAILURE\n\n", 1);
        failure_indicator++;
    }

    printf("********************************************************************************\n");
    printf("End of Test: Testing empty sample\n");
    printf("********************************************************************************\n\n\n");

    printf("********************************************************************************\n");
    printf("Test: Testing sample with one random element, output median must be equal to the element \n");
    printf("Random number: %f \n", inputL);
    printf("********************************************************************************\n\n");

    Push_Data(inputL);
    outputL = Return_Median();

    if ( outputL == inputL )
    {
        printf("Test No. %d ------------------> OK\n\n", 1);
    }

    else
    {
        printf("Test No. %d ------------------> FAILURE\n\n", 1);
        failure_indicator++;
    }

    printf("********************************************************************************\n");
    printf("End of Test: Testing sample with one random element \n");
    printf("********************************************************************************\n\n\n");

    return failure_indicator;
}

int main(void) {
    uint_type failure_indicator = 0;
    failure_indicator += TestInit();

    if (failure_indicator == 0)
    {
        printf("All is OK!\n");
    }

    else
    {
        printf("Some problems were found. See Above ...\n");
    }

    return failure_indicator;
}
