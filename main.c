#include "header.h"
int main(int argc,char *argv[]){

FILE *fp;
ll *head=NULL;
int data,size,choice,count=0;
char *fileName
while(1){
printf("Menu");
printf("Insert data to list\nPrint list to screen\nPrint list to a text file\nExit\nChoose:");
scanf("%d",&choice);
switch(choice){

	case 0:
	printf("Give the value:");
	scanf("%d",&data);
		addNode(&head,data);
		break;
	case 1:
	       printList(head);
		break;
	case 2:

printf("Give the size of file\'s name:");
scanf("%d",&size);
getchar();
while(UnsupportedSize(&size)){
printf("Wrong size. Give again:");
scanf("%d",&size);
getchar();
}

fileName= (char*)malloc(sizeof(char)*size);
printf("Give the name of the file:");
scanf("%s",fileName);
while(UnsupportedFileName(&fileName)){
	printf("The name of the file cannot be empty");
	scanf("%s",fileName);
}

fp = fopen(strcat(fileName,".txt"),"w+");
if(fp==NULL){
printf("Error during file opening");
printf("Exiting");
while((++count)<=5){
putchar(count);
}
exit(1);
}
else{
printListToFile(fp,head);

}
break;
case 3:
exit(0);
break;
default:
printf("Wrong choice.Give again");
continue;
break;
}
printf("Continue (1/0)?");
scanf("%d",&choice);
if(choice==0)break;
else continue;

}
return 0;
free(head);
free(fileName);

}


