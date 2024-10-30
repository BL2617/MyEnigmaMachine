#include"rotors.h"
#define BALANCE_FREQUENCY 13
void increase(char * offset, int length);

int main(){
	char  rotors_file_name[20] = "rotors.txt", message_file_name[20], cipher_file_name[20];
	int rotor_number, result;
	char ** rotors = read_rotors(rotors_file_name, &rotor_number);
	if(rotors == NULL){
		return 1;
	}
	//convert first (rotor_number - 1) rotors to offset
	for(int i = 0;i < rotor_number - 1;i++){
		for(int j = 0;j < LENGTH_ALPHABET;j++){
			rotors[i][j] -= 'A';
		}
	}
	//Message :
	printf("Enter file name of message : ");
	scanf("%s",message_file_name);
	FILE * message_file = fopen(message_file_name, "rb");
	if(message_file == NULL){
		perror("No found this file .\n");
		free(rotors);
		return 0;
	}
	for(int i = 0;;i++){
		if(message_file_name[i] == '.'){
			cipher_file_name[i++] = '.';
			cipher_file_name[i++] = 'e';
			cipher_file_name[i++] = 'n';
			cipher_file_name[i++] = 'i';
			cipher_file_name[i++] = '\0';
			break;
		} else {
			cipher_file_name[i] = message_file_name[i];
		}
	}
	FILE * cipher_file = fopen(cipher_file_name, "wb");
	//Key :
	char * key = (char *)malloc(sizeof(char) * (1 + rotor_number));
	printf("Enter key : ");
	scanf("%s", key);
	for(int i = 0;i < rotor_number;i++){//convert key to offset :
		key[i] = (key[i] - 'A');
	}
	//encrypt
	result = fseek(message_file, 0, SEEK_END);
	long long message_length = ftell(message_file);
	rewind(message_file);
	long long * alphabet_frequency = (long long *)malloc(sizeof(long long) * LENGTH_ALPHABET);
	for(int i = 0;i < LENGTH_ALPHABET;i++){
		alphabet_frequency[i] = 0;
	}
	int count = BALANCE_FREQUENCY; //when count equals 0, insert a alpha whose frequency is the least into cipher_file.
	char character = fgetc(message_file);
	while(character != EOF){
		//check it is alphabetical character
		if((!(character >= 'a' && character <= 'z')) && (!((character >= 'A' && character <= 'Z')))){
			fputc(character, cipher_file);
			character = fgetc(message_file);
			continue;
		}
		if(count-- == 0){
			count = BALANCE_FREQUENCY;
			int min_fre_index = 0;
			for(int i = 1;i < LENGTH_ALPHABET;i++){
				if(alphabet_frequency[i] <= alphabet_frequency[min_fre_index]){
					min_fre_index = i;
				}				
			}
			fputc(('a' + min_fre_index), cipher_file);
		}
		char base = (character - 'A' > 26) ? ('a' - 'A') : 0; //judge it is uppercase or lowercase.
		character = (character & 0b11011111) - 'A'; // convert character to offset based on uppercase 'A'.
		for(int i = 0;i < rotor_number;i++){
			character = rotors[i][(key[i] + character) % LENGTH_ALPHABET];
		}
		fputc(character + base, cipher_file);
		character = fgetc(message_file);
		//increase the offset of key
		increase(key, rotor_number); 
	}
	fclose(message_file);
	fclose(cipher_file);
	free(alphabet_frequency);
	free(rotors);
	free(key);
	return 0;
}

void increase(char * offset, int length){
	for(int i = 0;i < length;i++){
		offset[i]++;
		if(offset[i] == LENGTH_ALPHABET){
			offset[i] = 0;
		} else {
			break;
		}
	}
	return;
}