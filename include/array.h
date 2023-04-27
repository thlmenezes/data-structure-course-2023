#ifndef ARRAY_H_
	#define ARRAY_H_

	// TODO2: challenge
	// how do we implement a generic data pointer?
	typedef struct {
		int size;
		int* data;
	} Array;
	
	Array* array_create(int);
	int array_length(Array*);
	void array_free(Array*);
#endif
