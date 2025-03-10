#include <stdio.h>
void print_message(char *message){
	int i;
	for(i = 0; i < 10; i++){
	//printf("%c", message[i]);
	printf("%c", *(message+i));
	}
}
int main(){
	char msg[] = "cmpe230ps4";
	print_message(msg);
	return 0;
}