#include "util.h"

#define SYS_WRITE 4
#define STDOUT 1
#define STDIN 0
#define SYS_READ 3
#define OPEN 5
#define READ 0
#define WRITE 1
#define CLOSE 6

int nextFile(int current, int outputs){
	if(current==outputs-1){
		return 0;
	}
	else return current+1;
}
void line_spliter(int digitSplit, int specialMarkSplit, int fileSplit, int file, char specialMark, int outputs, char** filesnames);
int main(int argc, char** argv){
  int digitSplit=0, specialMarkSplit=0, fileSplit=0, outputs=0;
  char specialMark;
  int file;
  char *fileName;
  int isEnd=0;
  char c;
  int i;
  for(i=0; i<argc; i++){
    c=argv[i][1];
    switch(c){
      case 'd': digitSplit=1;
	      break;
      case 's': specialMarkSplit=1;
		  i=i+1;
		  specialMark=argv[i][0];
	      break;
      case 'i': fileSplit=1;
		i=i+1;
		fileName=argv[i];
	      break;
       case 'o':i=i+1; 
		outputs=argv[i][0]-'0';
		system_call(SYS_WRITE,STDOUT,"number of output files: ",24);
		system_call(SYS_WRITE,STDOUT, outputs ,1);
		system_call(SYS_WRITE,STDOUT,"\n",1);
		/*printf("number of output files:%d\n",outputs);*/
                
    }
    
  
  }
  
  char *filesnames[5];
  if(outputs){
    int j;
    for(j=0; j<outputs; j++){
        char filenamei[10];
	system_call(SYS_WRITE,STDOUT,"Enter output file: ",19);
	system_call(SYS_WRITE,STDOUT,j+1,1);
	system_call(SYS_WRITE,STDOUT,"\n",1);
	/*printf("Enter output file %d:\n", j+1);*/
	/*fgets(filenamei, sizeof(char)*10, stdin);*/
	system_call(SYS_READ,STDIN,filenamei,10);
    	filesnames[j]=filenamei;
    }
  }
  if(fileSplit){
    file=system_call(OPEN, fileName, READ);
  }
  else if(!fileSplit)
    system_call(SYS_WRITE,STDOUT,"Enter your text\n",16);
    /*printf("Enter your text\n");*/
  line_spliter(digitSplit,specialMarkSplit,fileSplit, file,specialMark, outputs, filesnames);
  return 0;
}
void line_spliter(int digitSplit, int specialMarkSplit, int fileSplit, int file, char specialMark, int outputs, char** filesnames){
 int files[5]; 
 int i;
        int file1;
        int file2;
        int file3;
        int file4;
        int file5;
	for(i=0; i<outputs;i++){
	    switch (i){
		case 0:
			/*file1=fopen(filesnames[0], "w+");*/
			file1=system_call(OPEN, filesnames[0], WRITE);
			files[0]=file1;
			break;
		case 1:
			
			/*file2=fopen(filesnames[1], "w+");*/
			file2=system_call(OPEN, filesnames[1], WRITE);
			files[1]=file2;
			break;
		case 2:
			
			/*file3=fopen(filesnames[2], "w+");*/
			file3=system_call(OPEN, filesnames[2], WRITE);
			files[2]=file3;
			break;
		case 3:
			
			/*file4=fopen(filesnames[3], "w+");*/
			file4=system_call(OPEN, filesnames[3], WRITE);
			files[3]=file4;
			break;
		case 4:
			
			/*file5=fopen(filesnames[4], "w+");*/
			file5=system_call(OPEN, filesnames[4], WRITE);
			files[4]=file5;
			break;
 	    }	
	}
  char c='\0';
  int isFirst=1;
  int line=1;
  if(fileSplit){
    system_call(SYS_READ,file,c,1);
  }
  else system_call(SYS_READ,STDIN,c,1);
  
  int currentFile;
  
  int fileNum=0;

  if(outputs){
	currentFile=file1;
  }
    while(c>0){
    switch(c){
      case '@':
	if(isFirst){
	  if(outputs){
		system_call(SYS_WRITE,currentFile,"1:",2);
		/*fprintf(currentFile,"1:" );*/
	  }
	  else /*printf("1:");*/
		system_call(SYS_WRITE,STDOUT,"1:",2);
        }
	if(outputs){
		system_call(SYS_WRITE,currentFile,"@",1);
		/*fprintf(currentFile,"@" );*/
	  }
	else /*printf("@");*/
		system_call(SYS_WRITE,STDOUT,"@",1);
	line++;
        if(outputs){
		system_call(SYS_WRITE,currentFile,"\n",1);
                /*fprintf(currentFile, "\n");*/
		fileNum=nextFile(fileNum,outputs);
		currentFile=files[fileNum];
		system_call(SYS_WRITE,currentFile,line,1);
		/*fprintf(currentFile, "%d:", line);*/
        }
	       	else {/*printf("\n%d:", line);*/
			system_call(SYS_WRITE,currentFile,"\n",1);
			system_call(SYS_WRITE,currentFile,line,1);
		}
	isFirst=0;
	break;
      case '*':
	if(isFirst){
	  if(outputs){
		system_call(SYS_WRITE,currentFile,"1:",2);
		/*fprintf(currentFile,"1:" );*/
	  }
	  else /*printf("1:");*/
		system_call(SYS_WRITE,STDOUT,"1:",2);
        }
	if(outputs){
		system_call(SYS_WRITE,currentFile,"*",1);
		/*fprintf(currentFile,"*" );*/
	  }
	else /*printf("*");*/
		system_call(SYS_WRITE,STDOUT,"*",1);
	line++;
	if(outputs){
		system_call(SYS_WRITE,currentFile,"\n",1);
                /*fprintf(currentFile, "\n");*/
		fileNum=nextFile(fileNum,outputs);
		currentFile=files[fileNum];
		system_call(SYS_WRITE,currentFile,line,1);
		/*fprintf(currentFile, "%d:", line);*/
        }
	       	else {/*printf("\n%d:", line);*/
			system_call(SYS_WRITE,currentFile,"\n",1);
			system_call(SYS_WRITE,currentFile,line,1);
		}
	isFirst=0;
	break;
      default: 
	if(isFirst){
	  if(outputs){
		system_call(SYS_WRITE,currentFile,"1:",2);
		/*fprintf(currentFile,"1:" );*/
	  }
	  else /*printf("1:");*/
		system_call(SYS_WRITE,STDOUT,"1:",2);
        }
	if(digitSplit && c<57 && c>48){
	  if(outputs){
		system_call(SYS_WRITE,currentFile,c,1);
		/*fprintf(currentFile,"%c", c );*/
	  }
	  else /*printf("%c", c);*/
		system_call(SYS_WRITE,STDOUT,"\n",1);
	  line++;
	  if(outputs){
		system_call(SYS_WRITE,currentFile,"\n",1);
                /*fprintf(currentFile, "\n");*/
		fileNum=nextFile(fileNum,outputs);
		currentFile=files[fileNum];
		system_call(SYS_WRITE,currentFile,line,1);
		/*fprintf(currentFile, "%d:", line);*/
        }
	       	else {/*printf("\n%d:", line);*/
			system_call(SYS_WRITE,currentFile,"\n",1);
			system_call(SYS_WRITE,currentFile,line,1);
		}
	isFirst=0;
	}
	else if( specialMarkSplit && c==specialMark){
	  if(outputs){
		/*fprintf(currentFile,"%c",specialMark );*/
		system_call(SYS_WRITE,currentFile,specialMark,1);
	  }
	  else /*printf("%c",specialMark);*/
		system_call(SYS_WRITE,STDOUT,specialMark,1);
	  line++;
	  if(outputs){
		system_call(SYS_WRITE,currentFile,"\n",1);
                /*fprintf(currentFile, "\n");*/
		fileNum=nextFile(fileNum,outputs);
		currentFile=files[fileNum];
		system_call(SYS_WRITE,currentFile,line,1);
		/*fprintf(currentFile, "%d:", line);*/
        }
	       	else {/*printf("\n%d:", line);*/
			system_call(SYS_WRITE,currentFile,"\n",1);
			system_call(SYS_WRITE,currentFile,line,1);
		}
	isFirst=0;
	}
	else {
	  if(outputs){
		system_call(SYS_WRITE,currentFile,c,1);
		/*fprintf(currentFile,"%c", c );*/
	  }
	  else {/*printf("%c", c);
		printf("fvdfbv");*/
		system_call(SYS_WRITE,STDOUT,c,1);}
	  isFirst=0;
	}
	break;
    }
    if(fileSplit){
      system_call(SYS_READ,file,c,1);
    }
    else {system_call(SYS_READ,STDIN,c,1);
	system_call(SYS_WRITE,STDOUT,c,1);}
    if(c=='\n')
        break;
  }
  int k;
  for(k=0;k<outputs;k++){
      /*close(files[k]);*/
	system_call(CLOSE,files[k]);
  }
}

