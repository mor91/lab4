#include "util.h"

#define SYS_WRITE 4
#define STDOUT 1
#define SYS_READ 3
#define STDIN 0

int main (int argc , char* argv[], char* envp[])
{
  /*int i;
  char c;*/
  char * str="Hello world";
  /*str = itoa(argc);*/
  system_call(SYS_WRITE,STDOUT, str,strlen(str));
  system_call(SYS_WRITE,STDOUT, "\n", 1);
  /*system_call(SYS_WRITE,STDOUT," arguments \n", 12);
  system_call(SYS_READ, STDIN , c ,1);
  system_call(SYS_WRITE,STDOUT,c, 1);
  for (i = 0 ; i < argc ; i++)
    {
      system_call(SYS_WRITE,STDOUT,"argv[", 5);
	  str = itoa(i);
      system_call(SYS_WRITE,STDOUT,str,strlen(str));
      system_call(SYS_WRITE,STDOUT,"] = ",4);
      system_call(SYS_WRITE,STDOUT,argv[i],strlen(argv[i]));
      system_call(SYS_WRITE,STDOUT,"\n",1);
    }*/
  return 0;
}
