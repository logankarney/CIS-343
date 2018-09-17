#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

//https://www.tutorialspoint.com/cprogramming/c_file_io.htm

int read_file(char* filename, char** buffer){
	struct stat st;

	FILE* fileA = fopen(filename, "r");
	stat(filename, &st);
	int size = st.st_size;

	if(size == 0){
		fprintf(stderr, "Error reading file");
	}
	
	*buffer = malloc(size*sizeof(char));
	
	for(int i = 0; i < size; i++){
		//https://www.tutorialspoint.com/c_standard_library/c_function_fread.htm
		fread(*buffer, 1, size, fileA);	
	}

	fclose(fileA);

	return size;
}

int write_file(char* filename, char* buffer, int size){
	FILE* fileB = fopen(filename, "w");
	
	//https://www.tutorialgateway.org/fputc-in-c/
	for(int i = 1; i < size; i++){
		fputc(*(buffer + i), fileB);
	}
	
	fclose(fileB);
	return 0;	
}
