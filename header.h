#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct ll{

int data;
struct ll*next_node;

}ll;


void addNode(ll**head,int new_data){

ll*newnode=(ll*)malloc(sizeof(ll));
newnode->data=new_data;
newnode->next_node=*head;
*head=newnode;
printf("Element:%d added to list\n",newnode->data);
}

bool listIsEmpty(ll*head){
	return head==NULL;
}

bool FileIsNull(FILE*fp){
return fp==NULL;
}

void printList(ll*head){

if(listIsEmpty(head)){
printf("List is empty.");
return;
}
while(head){
printf("%d->",head->data);
head=head->next_node;
}
}

void printListToFile(FILE *fp,ll*head){
if(FileIsNull(fp)||listIsEmpty(head)){
printf("Error: Null File pointer or Empty list\n");
return;
}
while(head){
fprintf(fp,"%d%s",head->data,"->");
head=head->next_node;
}
printf("List printed to file\n");
}


int UnsupportedSize(int *size){
return (*size==0) || (*size<0);
}

int UnsupportedFileName(char **fileName){

	return strcmp(*fileName,"")==0;
}
