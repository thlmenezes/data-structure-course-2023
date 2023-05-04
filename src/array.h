#ifndef ARRAY_H_
	#define ARRAY_H_

	// TODO2: challenge
	// how do we implement a generic data pointer?
	typedef struct {
		int size;
		int* data;
	} Array;
	/**
	 * Instantiates a new dynamic allocated array
	 */	
	Array* array_create(int);
	int array_length(Array*);
	Array* array_clone(Array*);
	void array_fill(Array*,int);
	// TODO1: implement string repr of array for printf
	char* array_to_s(Array*);
	void array_free(Array*);
#endif
