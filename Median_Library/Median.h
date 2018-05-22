/*
 ============================================================================
 Name        : Median.h
 Author      : Ivan Gajev
 Version     : 1.0
 Description : Used as an interface header file for Median.c
 ============================================================================
 */

#ifndef MEDIAN_H_
#define MEDIAN_H_

//======================================================================================================================
// PUBLIC TYPES
//======================================================================================================================
typedef double data_type;

//----------------------------------------------------------------------------------------------------------------------
///@brief   Used to execute the main functionality of the component.
///         The task call is done from the OS/System StateManager.
///         The scheduling mechanism is defined by the OS configuration dependent on the needs of
///         the individual components.
//----------------------------------------------------------------------------------------------------------------------
extern data_type Return_Median( void );

//----------------------------------------------------------------------------------------------------------------------
///@brief   Used to execute the main functionality of the component.
///         The task call is done from the OS/System StateManager.
///         The scheduling mechanism is defined by the OS configuration dependent on the needs of
///         the individual components.
//----------------------------------------------------------------------------------------------------------------------
extern void Push_Data( data_type const data );

#endif /* MEDIAN_H_ */
