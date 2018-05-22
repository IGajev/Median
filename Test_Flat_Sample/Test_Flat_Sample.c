/*
 * Test_Flat_Sample.c
 *
 *  Created on: May 17, 2018
 *      Author: gajev
 */


#include "Median.h"
#include <stdio.h>
#include <stdlib.h>

#define output_init ((data_type) 0.0)
#define Highest_Elemet_Value ((data_type) 100.0)

typedef unsigned int uint_type;

uint_type TestFlatSample(void)
{
	uint_type failure_indicator = 0;
	uint_type counterL;
	data_type outputL;


	printf("********************************************************************************\n");
	printf("Test: Testing flat sample with flat element values (1.0) \n");
	printf("Output median must be equal to (1.0) \n");
    printf("********************************************************************************\n\n");

    for ( counterL = 1; counterL <= Highest_Elemet_Value; counterL++ )
    {
        Push_Data(1.0);
        outputL = Return_Median();

    	if ( outputL == (1.0) )
    	{
    		printf("Test No. %d ------------------> OK\n\n", counterL);
    	}

    	else
    	{
    		printf("Test No. %d ------------------> FAILURE\n\n", counterL);
    		failure_indicator++;
    	}
    }

    printf("********************************************************************************\n");
	printf("End of Test: Testing flat sample \n");
    printf("********************************************************************************\n\n\n");

    return failure_indicator;
}

int main(void) {
	uint_type failure_indicator = 0;
	failure_indicator += TestFlatSample();

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
