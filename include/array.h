#ifndef ARRAY_H_
	#define ARRAY_H_

	// TODO2: challenge
	// how do we implement a generic data pointer?
	typedef struct {
		int size;
		int* data;
	} Array;
	
	Array* create_array(int);
	// TODO1: implement the methods below
	int length(Array*);
	void free_array(Array*);
#endif