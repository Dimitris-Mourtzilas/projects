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

void copyList(ll*head,ll**shead){
if(head==NULL)return;
while(head){
ll*newnode=(ll*)malloc(sizeof(ll));
newnode->data=head->data;
newnode->next_node=*shead;
*shead=newnode;
head=head->next;
}
}

void sortList(ll **head){
if(*head==NULL)return;
ll*temp=*head;
int temp_data;
while((*head)->next_node){
temp=temp->next_node;
}
while(*head<temp){
if((*head)->data>temp->data){
temp_data=(*head)->data;
(*head)->data=temp->data;
temp->data=temp_data;
}
*head=(*head)->next_node;
}
}

bool findElement(ll*head,int key){
if(listIsEmpty(head))return false;
while(head){
if(head->data==key)return true;
head=head->next_node;
}
return false;
}

void deleteList(ll*head){
if(listIsEmpty(head))return;
ll*temp;
while(head){
temp=head;
head=head->next_node;
free(temp);
}

printf("List deleted");
}


