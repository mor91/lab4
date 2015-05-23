#include "util.h"

#define SYS_GETDENTS 141
#define SYS_WRITE 4
#define STDOUT 1
#define STDIN 0
#define SYS_READ 3
#define OPEN 5
#define READ 0
#define WRITE 1
#define CLOSE 6
#define CREAT 64
#define READDIR 89

typedef struct ent{
	int inode;
 	int offset;
	short len;
	char buf[1];
}ent;


int main(int argc, char** argv){
	char buf[8192];
	int fd;
	ent *entp=buf;
	int count;
	
	fd=system_call(OPEN,".",0.0);
	/*if(fd<0)
		exit(85);*/
	count=system_call(141, fd, buf, 8192);	
	system_call(SYS_WRITE, STDOUT, itoa(count) ,2);
	system_call(SYS_WRITE, STDOUT, "\n", 1);
	
	/*int i=0;
	while(i<count){
		system_call(SYS_WRITE, STDOUT, entp->buf,strlen(entp->buf));
		system_call(SYS_WRITE, STDOUT, "\n", 1);
		i=i+entp->len;
		entp=entp+entp->len;
	}*/


	return 0;
} 
