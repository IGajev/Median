/*
 ============================================================================
 Name        : Median.c
 Author      : Ivan Gajev
 Version     : 1.0
 Description : Used to calculate the median of a sample in C, Ansi-style
 ============================================================================
 */

//======================================================================================================================
// INCLUDED FILES
//======================================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include "Median.h"

//======================================================================================================================
// PRIVATE MACROS
//======================================================================================================================

#define Null ( ( void * ) 0 )

//======================================================================================================================
// PRIVATE TYPES
//======================================================================================================================

typedef struct sElement
{
    data_type data;
    struct sElement * Left_Element;
    struct sElement * Right_Element;
}tElement;

typedef tElement * pElement;

//======================================================================================================================
// FORWARD DECLARATIONS OF PRIVATE FUNCTIONS
//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
///@brief   Called to dynamically allocate memory for every pushed element on the heap
//----------------------------------------------------------------------------------------------------------------------
static pElement Allocate_New_Element(void);

//----------------------------------------------------------------------------------------------------------------------
///@brief   Called to find the correct place of current element on the left side of pNeighbour_Elementp
//----------------------------------------------------------------------------------------------------------------------
static void Push_Left( pElement const pNeighbour_Elementp, pElement const pCurrentElementL );

//----------------------------------------------------------------------------------------------------------------------
///@brief   Called to find the correct place of current element on the right side of pNeighbour_Elementp
//----------------------------------------------------------------------------------------------------------------------
static void Push_Right( pElement const pNeighbour_Elementp, pElement const pCurrentElementL );

//----------------------------------------------------------------------------------------------------------------------
///@brief   Called to store the current element between pNeighbour_Element_Leftp and pNeighbour_Element_Rightp
//----------------------------------------------------------------------------------------------------------------------
static void Push_Middle( pElement const pNeighbour_Element_Leftp, pElement const pNeighbour_Element_Rightp, pElement const pCurrentElementL );

//----------------------------------------------------------------------------------------------------------------------
///@brief   Called within public function Push_Data to push an element when the sample is even before the push
//----------------------------------------------------------------------------------------------------------------------
static void Push_Element_in_Even_Sample( pElement const pCurrentElementL );

//----------------------------------------------------------------------------------------------------------------------
///@brief   Called within public function Push_Data to push an element when the sample is uneven before the push
//----------------------------------------------------------------------------------------------------------------------
static void Push_Element_in_Uneven_Sample( pElement const pCurrentElementL );

//======================================================================================================================
// PRIVATE DATA IN STATIC RAM
//======================================================================================================================

//This is the primary pointer to the median element when the sample is uneven.
static pElement pLeft_Median_Element = Null;

//This is the secondary pointer to the median element when the sample is even, Null when sample is uneven.
static pElement pRight_Median_Element = Null;

//======================================================================================================================
// LOCAL FUNCTIONS
//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Function used to dynamically allocate memory for every pushed element on the heap.
//
// PARAMETERS:          None
//
// RETURN VALUE:        Pointer to the dynamically allocated element
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
static pElement Allocate_New_Element(void)
{
    //Dynamic allocation of one element, returns a pointer to one element.
    return (pElement) malloc(sizeof(tElement));
}

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Function used to find the correct place of current element on the left side of pNeighbour_Elementp.
//
// PARAMETERS:          pNeighbour_Elementp, pCurrentElementL
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
static void Push_Left( pElement const pNeighbour_Elementp, pElement const pCurrentElementL )
{
    //if pCurrentElementL's data is lower or equal than the pNeighbour_Elementp's data -> either push more on the left or make it the first element because of beginning of sample.
    if( pCurrentElementL->data <= pNeighbour_Elementp->data )
    {
        if ( Null != pNeighbour_Elementp->Left_Element )
        {
            Push_Left( pNeighbour_Elementp->Left_Element, pCurrentElementL );
        }


        //End of sample on the left. This is the lowest element so far.
        else
        {
            pCurrentElementL->Right_Element = pNeighbour_Elementp;
            pCurrentElementL->Left_Element = Null;
            pNeighbour_Elementp->Left_Element = pCurrentElementL;
        }
    }


    //Current data is higher or equal to the pNeighbour_Elementp's data and it must be placed on the right of the pNeighbour_Elementp.
    else
    {
        pCurrentElementL->Left_Element = pNeighbour_Elementp;                 //Initialize current element's left pointer
        pCurrentElementL->Right_Element = pNeighbour_Elementp->Right_Element; //Initialize current element's right pointer
        pNeighbour_Elementp->Right_Element->Left_Element = pCurrentElementL;  //Change neighbour on the right side's left pointer
        pNeighbour_Elementp->Right_Element = pCurrentElementL;                //Change neighbour on the left side's right pointer
    }
}

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Function used to find the correct place of current element on the right side of pNeighbour_Elementp.
//
// PARAMETERS:          pNeighbour_Elementp, pCurrentElementL
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
static void Push_Right( pElement const pNeighbour_Elementp, pElement const pCurrentElementL )
{
    //if pCurrentElementL's data is larger than the pNeighbour_Elementp's data -> either push more on the right or make it the last element because of end of sample.
    if( pCurrentElementL->data > pNeighbour_Elementp->data )
    {
        if( Null != pNeighbour_Elementp->Right_Element )
        {
            Push_Right( pNeighbour_Elementp->Right_Element, pCurrentElementL );
        }

        //End of sample on the right. This is the biggest element so far.
        else
        {
            pCurrentElementL->Left_Element = pNeighbour_Elementp;
            pCurrentElementL->Right_Element = Null;
            pNeighbour_Elementp->Right_Element = pCurrentElementL;
        }
    }

    //Current data is lower or equal to the pNeighbour_Elementp's data and it must be placed on the left of the pNeighbour_Elementp.
    else
    {
        pCurrentElementL->Right_Element = pNeighbour_Elementp;               //Initialize current element's right pointer
        pCurrentElementL->Left_Element = pNeighbour_Elementp->Left_Element;  //Initialize current element's left pointer
        pNeighbour_Elementp->Left_Element->Right_Element = pCurrentElementL; //Change neighbour on the left side's right pointer
        pNeighbour_Elementp->Left_Element = pCurrentElementL;                //Change neighbour on the right side's left pointer
    }
}

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Function used to store the current element between pNeighbour_Element_Leftp and pNeighbour_Element_Rightp.
//
// PARAMETERS:          pNeighbour_Element_Leftp, pNeighbour_Element_Rightp, pCurrentElementL
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
static void Push_Middle( pElement const pNeighbour_Element_Leftp, pElement const pNeighbour_Element_Rightp, pElement const pCurrentElementL )
{
    pCurrentElementL->Left_Element = pNeighbour_Element_Leftp;

    pCurrentElementL->Right_Element = pNeighbour_Element_Rightp;

    pNeighbour_Element_Leftp->Right_Element = pCurrentElementL;

    pNeighbour_Element_Rightp->Left_Element = pCurrentElementL;

    pLeft_Median_Element = pCurrentElementL;
}

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Function used to push an element when the sample is even before the push.
//
// PARAMETERS:          pCurrentElementL
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
static void Push_Element_in_Even_Sample( pElement const pCurrentElementL )
{
    //If pCurrentElementL's data is between pLeft_Median_Element and pRight_Median_Element push it in the middle between them and make it pLeft_Median_Element
    if ( ( pLeft_Median_Element->data <= pCurrentElementL->data) && ( pCurrentElementL->data <= pRight_Median_Element->data ) )
    {
        Push_Middle(pLeft_Median_Element, pRight_Median_Element, pCurrentElementL);
    }

    //If pCurrentElementL's data is larger than pRight_Median_Element's data push it on the right
    else if ( pCurrentElementL->data > pRight_Median_Element->data )
    {
        Push_Right( pRight_Median_Element, pCurrentElementL );
        pLeft_Median_Element = pRight_Median_Element;
    }

    //If pCurrentElementL's data is lower than pLeft_Median_Element push it on the left
    else
    {
        Push_Left( pLeft_Median_Element, pCurrentElementL );
    }

    pRight_Median_Element = Null;
}

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Function used to push an element when the sample is uneven before the push.
//
// PARAMETERS:          pCurrentElementL
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
static void Push_Element_in_Uneven_Sample( pElement const pCurrentElementL )
{
    //if pLeft_Median_Element is not Null, sample is not empty. It is the primary static pointer to the median.
    if (Null != pLeft_Median_Element )
    {
        //if pCurrentElementL's data is larger than the left median -> push it on the right
        if ( pCurrentElementL->data > pLeft_Median_Element->data )
        {
            Push_Right(pLeft_Median_Element, pCurrentElementL);
            pRight_Median_Element = pLeft_Median_Element->Right_Element;
        }

        //if pCurrentElementL's data is lower or equal than the left median -> push it on the left
        else
        {
            Push_Left(pLeft_Median_Element, pCurrentElementL);
            pRight_Median_Element = pLeft_Median_Element;
            pLeft_Median_Element = pLeft_Median_Element->Left_Element;
        }
    }
    //if pLeft_Median_Element is Null, sample is empty. It is the primary static pointer to the median.
    else
    {
        pLeft_Median_Element = pCurrentElementL;
        pLeft_Median_Element->Left_Element = Null;
        pLeft_Median_Element->Right_Element = Null;
    }
}

//======================================================================================================================
// EXTERNAL FUNCTIONS
//======================================================================================================================

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Interface function used to extract the median of the sample
//
// PARAMETERS:          None
//
// RETURN VALUE:        Median of the sample
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
extern data_type Return_Median( void )
{
    //Local variable used for holding the calculated median.
    data_type dtReturn_ElementL = 0;

    //If pLeft_Median_Element is initialized -> we have at least one pushed element.
    if ( Null != pLeft_Median_Element )
    {
        //if pRight_Median_Element is not Null -> we have even number of elements and median is extracted as mean of the two middle elements.
        if (Null != pRight_Median_Element)
        {
            dtReturn_ElementL = ( (pLeft_Median_Element->data + pRight_Median_Element->data ) / 2.0 );
        }
        //if pRight_Median_Element is Null -> we have uneven number of elements and pLeft_Median_Element is pointing to the median.
        else
        {
            dtReturn_ElementL = pLeft_Median_Element->data;
        }
    }
    //if pLeft_Median_Element is Null -> there are no elements pushed.
    else
    {
        dtReturn_ElementL = 0;
    }

    return dtReturn_ElementL;
}

//----------------------------------------------------------------------------------------------------------------------
// DESCRIPTION:         Interface function used to push an element in the sample
//
// PARAMETERS:          Data to be pushed in the sample
//
// RETURN VALUE:        None
//
// DESIGN INFORMATION:  None
//----------------------------------------------------------------------------------------------------------------------
void Push_Data( const data_type dtDataP )
{
    pElement pCurrentElementL;

    pCurrentElementL = Allocate_New_Element();

    if ( Null != pCurrentElementL )
    {
        pCurrentElementL->data = dtDataP;

        //if pRight_Median_Element is not Null -> current sample is even. It is the secondary static pointer to the median.
        if (Null != pRight_Median_Element)
        {
            Push_Element_in_Even_Sample( pCurrentElementL );
        }
        //if pRight_Median_Element is Null -> current sample is uneven or empty. It is the secondary static pointer to the median.
        else
        {
            Push_Element_in_Uneven_Sample ( pCurrentElementL );
        }
    }
}

