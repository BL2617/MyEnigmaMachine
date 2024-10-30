#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define LENGTH_ALPHABET 26

bool is_valid_rotors(char ** rotors, int rotor_number);

char ** read_rotors(char * file_name, int * rotor_number){
	FILE * file = fopen(file_name, "rb");
	if(file == NULL){
		perror("Rotors do not exist.");
		fclose(file);
		return NULL;
	}
	fseek(file, 0, SEEK_END);
	int file_length = ftell(file);
	rewind(file);
	(*rotor_number) = file_length / LENGTH_ALPHABET;
	printf("There are %d rotors. \n", *rotor_number);
	//initialize 2d array.
	char ** rotors = (char **)malloc(sizeof(char *) * (*rotor_number));
	if(rotors == NULL){
		perror("Memory allocate failed.");
		free(rotors);
		fclose(file);
		return NULL;
	}
	for(int i = 0;i < (*rotor_number);i++){
		rotors[i] = (char *)malloc(sizeof(char) * LENGTH_ALPHABET);
		if(rotors[i] == NULL){
			perror("Memory allocate failed.");
			fclose(file);
			while(i >= 0){
				free(rotors[i--]);
			}
			return NULL;
		}
	}
	//store file information into arrays.
	for(int i = 0;i < (*rotor_number);i++){
		char c = '\0';
		for(int j = 0;j < LENGTH_ALPHABET;j++){
			rotors[i][j] = fgetc(file);
		}
		
		while((!(c >= 'A' && c <= 'Z')) && (!(c >= 'a' && c <= 'z'))){
			c = fgetc(file);
			if(c == EOF) break;
		}
		fseek(file, -1, SEEK_CUR);
	}
	if(!is_valid_rotors(rotors, *rotor_number)){
		perror("Is not valid rotors !");
		fclose(file);
		for(int i = 0;i < *rotor_number;i++){
			free(rotors[i]);
		}
		free(rotors);
		return NULL;
	}
	fclose(file);
	return rotors;
}

void show_rotors(char ** rotors, int rotor_number){
	for(int i = 0;i < rotor_number;i++){
		for(int j = 0;j < LENGTH_ALPHABET;j++){
			printf("%c",rotors[i][j]);
		}
		printf("\n");
	}
}

bool is_valid_rotors(char ** rotors, int rotor_number){
	int count[LENGTH_ALPHABET];
	for(int i = 0;i < LENGTH_ALPHABET;i++){
		count[i] = 0;
	}
	for(int i = 0;i < rotor_number;i++){
		for(int j = 0;j < LENGTH_ALPHABET;j++){
			if(rotors[i][j] - 'A' >= 26){
				return false;
			}
			count[rotors[i][j] - 'A'] += 1;
		}
		for(int j = 0;j < LENGTH_ALPHABET - 1;j++){
			if(count[j] != count[j + 1]){
				return false;
			}
		}
	}
	return true;
};