#define TRUE    1
#define FALSE   0

typedef struct node 
{
	int key;
	struct node* left;
	struct node* right;
} node;

node * addnode(node * parent, int key);
node * srchnode(node * parent, int key);
node * delnode(node * parent, int key);
int isblnode(node * n);