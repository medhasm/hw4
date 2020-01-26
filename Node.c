#include "Node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NUM_LETTERS ((int)26)
#define WORD 30

void insert(node **root, char* ltr){
int i=0;
i=strlen(ltr);
int v;
int chr=FALSE;;
for(v=0 ;v<i;v++){
chr=(int) (*(ltr+v)-('a'));

	if((*root)->children[chr]==NULL){
		(*root)->children[chr]=newNode(ltr[v]);
			strcpy((*root)->children[chr]->word,(*root)->word);
				(*root)->children[chr]->word[v]=(*root)->children[chr]->letter;

		}	

root=&((*root)->children[chr]);
}
(*root)->count++;


}
node* newNode(char data) {
node *p = (node*) calloc (1,sizeof(node));
if(p==NULL) {
printf("calloc returned null");
return NULL;
}
p->letter = data;
p->count=FALSE;
return p;
}
void print(node* head,char* c){
if(head==NULL) return;
if(head->count) printf(" %s \t %ld \n",head->word,head->count);
if(*c=='r'){
int i;
for(i=NUM_LETTERS-1 ;i>=0;i=i-1){
if(head->children[i]==NULL) continue;
if(head->count) printf(" %s \t %ld \n",head->word,head->count);
print(head->children[i],c);

}

}else{

//if(head->count) printf(" %s \t %ld \n",head->word,head->count);
int i;
for(i=0 ;i<NUM_LETTERS;i++){
if(head->children[i]==NULL) continue;
print(head->children[i],c);

}
}

}
void freeTrie(node* head){
if(head==NULL) return;
int i;
for(i=0;i<NUM_LETTERS;i++){
freeTrie(head->children[i]);
}
free(head);
}
