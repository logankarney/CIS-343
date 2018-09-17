#include <stdio.h>
#include <sys/stat.h>
#include "file_utils.h"

int main(int argc, char** argv){
	if(argc != 3){
		fprintf(stderr, "Invalid argument number");
		return 1;
	}

	char* file1 = argv[1];
	char* file2 = argv[2];
	char* buffer;
	int file_size;

	file_size = read_file(file1, &buffer);

	char arry[file_size];

	for(int i = 0; i < file_size; i++){
		arry[i] = *(buffer + file_size - 1 - i);	
	}

	buffer = arry;

	write_file(file2, buffer, file_size);

	return 0;
}
