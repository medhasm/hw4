#ifndef _NODE_H_
#define _NODE_H_
#define NUM_LETTERS ((int)26)
#define WORD 30
typedef enum {FALSE=0, TRUE=1} boolean;
typedef struct node {
char letter;
char word[WORD];
long unsigned int count;
struct node* children[NUM_LETTERS];
} node;
void insert(node** root, char* ltr);
node* newNode(char data);
void print(node* head,char* c);
void freeTrie(node* head);
#endif
