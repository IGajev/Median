/*
 * Test_Decreasing_Sample.c
 *
 *  Created on: May 17, 2018
 *      Author: gajev
 */


/*
 * main.c
 *
 *  Created on: May 17, 2018
 *      Author: IGAJEV
 */
#include "Median.h"
#include <stdio.h>
#include <stdlib.h>

#define output_init ((data_type) 0.0)
#define Highest_Elemet_Value ((data_type) 100.0)

typedef unsigned int uint_type;

uint_type TestDecreasingSample(void)
{
	uint_type failure_indicator = 0;
	uint_type counterL;
	data_type outputL;


	printf("********************************************************************************\n");
	printf("Test: Testing decreasing sample with decreasing element values (Value--) \n");
	printf("Output median must be equal to Highest_Elemet_Value - (Highest_Elemet_Value - last_element)/2) \n");
    printf("********************************************************************************\n\n");

    for ( counterL = Highest_Elemet_Value; counterL > 0; counterL-- )
    {
        Push_Data((data_type)counterL);
        outputL = Return_Median();

    	if ( outputL == ( Highest_Elemet_Value - (Highest_Elemet_Value - counterL)/2.0 ) )
    	{
    		printf("Test No. %d ------------------> OK\n\n", (uint_type)Highest_Elemet_Value - counterL + 1);
    	}

    	else
    	{
    		printf("Test No. %d ------------------> FAILURE\n\n", (uint_type)Highest_Elemet_Value - counterL + 1 );
    		failure_indicator++;
    	}
    }

    printf("********************************************************************************\n");
	printf("End of Test: Testing decreasing sample \n");
    printf("********************************************************************************\n\n\n");
    return failure_indicator;
}

int main(void) {
	uint_type failure_indicator = 0;
	failure_indicator += TestDecreasingSample();

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
