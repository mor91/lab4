#include "util.h"
#define SYS_LSEEK 19
#define OPEN 5
#define SYS_WRITE 4

void patch(char* fileName, char* xName){
	int file=system_call(OPEN ,fileName ,0777 );
	system_call(SYS_LSEEK, file, 657, 1);
	system_call(SYS_WRITE, file, xName, strlen(xName));
}

int main (int argc , char* argv[], char* envp[]){
    patch("greeting","X_NAME");
    return 0;
} 
