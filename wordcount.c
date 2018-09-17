#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int wordCount(char* argv);

int main(int argc, char *argv[]){
	int i, pid;

	//for each File being passed, create a fork and call wordCount func
	for(i = 1; i < argc; i++)
	{
		pid = fork();
		if(pid < 0 ){ //if fork less than 0, error
				printf("Error");
				exit(1);
		} else if(pid == 0) { //if fork process is child, get wordCount
				//FILE *f = fopen(argv[i], "r");
				printf("Child process for %s: ", argv[i]); //print first part of msg
				wordCount(argv[i]);
				exit(0);
		} else{
				wait(NULL);
		}
	}
	printf("All %d files have been counted!\n", argc-1);
}

//recieves current name name, then counts words in the file based on # of spaces
int wordCount(char* argv){
		FILE *file_name;
		int count = 1;
		char c;
		file_name = fopen(argv, "r");
		if(file_name == NULL)
				printf("file not found\n");
		while((c = fgetc(file_name)) != EOF){ //read file until EOF
				if(c == ' ') //checking for spaces
						count++; //increment count when spaces found
		}
		printf("number of words is %d\n", count);
		return 0;
}
