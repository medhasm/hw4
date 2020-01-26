#include "Node.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE 256
#define WORD 30
char* lowCase(char* c);
int main(int argc, char* argv[]) {
node* head=newNode(' ');
node** p=&head;
char wordCheak[1]; 
int i=0;
int ci=0;
int size=15;
char *hand1=(char*) calloc(1,size*sizeof(char));
while ((wordCheak[FALSE]=getchar())!=EOF){
if(wordCheak[0]!='\n' && wordCheak[0]!=' ' && wordCheak[0]!='\t'){
if(ci==size-1){
size=size+15;
hand1=(char*) realloc(hand1,size) ;
hand1[ci-1]=wordCheak[0];
}else{
hand1[ci-1]=wordCheak[0];
}
}else{
hand1[ci-1]=0;
char *c=lowCase(hand1);
if(c==NULL) {
printf("error malloc");
return -1;}
insert(p,c);
p=&head;
free(c);
ci=0;
}
}
if(argc==2 && **(argv+1)=='r'){
print(*p,argv[1]);
}else{
print(*p,argv[0]);
}
p=&head;
freeTrie(*p);
free(hand1);
fclose(stdin);
return 0;
}
char* lowCase(char* c){
int i;
for(i=0;i<strlen(c);i++){
if (c[i]>='A' && c[i]<='Z') { 
c[i]=c[i]+32;
}
}
int h=0;
char *hand=(char*) calloc(TRUE,(WORD/2)*sizeof(char));
for(i=0;i<strlen(c);i++){
if(c[i]>='a'&&c[i]<='z'){
hand[h]=c[i];
h++;
}
}
return hand;
}
