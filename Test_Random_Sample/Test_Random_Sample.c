/*
 * Testing_Random_Sample.c
 *
 *  Created on: May 17, 2018
 *      Author: gajev
 */


#include "Median.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define output_init ((data_type) 0.0)
#define Highest_Elemet_Index ((uint_type) 9900.0)//Each time a new chunk is added sample will change from uneven to even.
#define Chunk_Elemet_Index ((uint_type) 99.0)//99 so that sample could be even and uneven.

typedef unsigned int uint_type;
typedef signed int   sint_type;
typedef time_t time_type;

//Copied from https://en.wikiversity.org/wiki/C_Source_Code/Find_the_median_and_mean
float median(int n, int x[])
{
    float temp;
    int i, j;
    // the following two loops sort the array x in ascending order
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(x[j] < x[i]) {
                // swap elements
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    if(n%2==0) {
        // if there is an even number of elements, return mean of the two elements in the middle
        return((x[n/2] + x[n/2 - 1]) / 2.0);
    } else {
        // else return the element in the middle
        return x[n/2];
    }
}
//End of copy

uint_type TestRandomSample(void)
{
	uint_type failure_indicator = 0;
	uint_type counterL;
	uint_type loop_counterL;
	sint_type inputL[Highest_Elemet_Index];
	data_type outputL;
	data_type calculatedL;
	time_type t;

	/* Initializes random number generator */
	srand( (uint_type) time(&t) );

    for ( counterL = 0; counterL < Highest_Elemet_Index; counterL++ )
    {
    	/* Generate a random number range from 0 to 1000000*/
    	inputL[counterL] = rand() % 1000000;
    }

    for ( loop_counterL = 0; loop_counterL < (Highest_Elemet_Index/Chunk_Elemet_Index); loop_counterL++ )
    {
    	printf("********************************************************************************\n");
    	printf("Test: Testing random sample with random element values \n");
    	printf("Inputs added to sample: [");
        for ( counterL = 0; counterL < Chunk_Elemet_Index - 1; counterL++ )
        {
        	printf("%d, ", inputL[loop_counterL*Chunk_Elemet_Index + counterL]);
        }
    	printf("%d", inputL[loop_counterL*Chunk_Elemet_Index + counterL]);
    	printf("]\n");
        printf("********************************************************************************\n\n");

        for ( counterL = 0; counterL < Chunk_Elemet_Index; counterL++ )
        {
            Push_Data((data_type)inputL[loop_counterL*Chunk_Elemet_Index + counterL]);
        }
        outputL = Return_Median();

        calculatedL = median( ((loop_counterL+1)*Chunk_Elemet_Index), inputL );
    	printf("Output: median must be equal to %f \n\n", calculatedL);


    	if ( outputL == calculatedL )
    	{
    		printf("Test No. %d ------------------> OK\n\n", loop_counterL + 1);
    	}

    	else
    	{
    		printf("Test No. %d ------------------> FAILURE\n\n", loop_counterL + 1);
    		failure_indicator++;
    	}

        printf("********************************************************************************\n");
    	printf("End of Test: Testing random sample \n");
        printf("********************************************************************************\n\n\n");
    }

    return failure_indicator;
}

int main(void) {
	uint_type failure_indicator = 0;
	failure_indicator += TestRandomSample();

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
