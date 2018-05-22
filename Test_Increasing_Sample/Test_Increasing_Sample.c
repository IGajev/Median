/*
 * Test_Increasing_Sample.c
 *
 *  Created on: May 17, 2018
 *      Author: gajev
 */


#include "Median.h"
#include <stdio.h>
#include <stdlib.h>

#define output_init ((data_type) 0.0)
#define Highest_Elemet_Value ((uint_type) 100.0)

typedef unsigned int uint_type;

uint_type TestIncreasingSample(void)
{
	uint_type failure_indicator = 0;
	uint_type counterL;
	data_type outputL;


	printf("********************************************************************************\n");
	printf("Test: Testing increasing sample with increasing element values (Value++) \n");
	printf("Output median must be equal to (last_element/2 + 0.5) \n");
    printf("********************************************************************************\n\n");

    for ( counterL = 1; counterL <= Highest_Elemet_Value; counterL++ )
    {
        Push_Data((data_type)counterL);
        outputL = Return_Median();

    	if ( outputL == (counterL/2.0 + 0.5) )
    	{
    		printf("Test No. %d ------------------> OK\n\n", counterL );
    	}

    	else
    	{
    		printf("Test No. %d ------------------> FAILURE\n\n", counterL );
    		failure_indicator++;
    	}
    }

    printf("********************************************************************************\n");
	printf("End of Test: Testing increasing sample \n");
    printf("********************************************************************************\n\n\n");
    return failure_indicator;
}

int main(void) {
	uint_type failure_indicator = 0;
	failure_indicator += TestIncreasingSample();

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
