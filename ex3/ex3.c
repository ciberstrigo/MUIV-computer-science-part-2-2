#include "ex3.h"
#include <stdlib.h>
#include <stdio.h>

/*typedef struct node 
{
	int key;
	struct node* left;
	struct node* right;
} node;*/

node * __findmin(node * parent)
{
	while(parent->left != NULL) parent = parent->left;
	return parent;
}

node * addnode(node * parent, int key)
{
	node * temp = (node*)malloc(sizeof(node));
	temp->left = temp->right = NULL;
	temp->key = key;

	if(parent == NULL) return temp;
	if(parent->key > temp->key) 
	parent->left = temp;
	else if(parent->key < temp->key)
	parent->right = temp;
	return temp;
}

node * srchnode(node * parent, int key)
{
	if(parent == NULL) return NULL;
	else if(parent->key == key) return parent;
	else if(key <= parent->key) return srchnode(parent->left, key);
	else return srchnode(parent->right, key);
}



node * delnode(node * n, int key)
{
	if(n == NULL) return n;
	else if(key < n->key) return delnode(n->left, key);
	else if(key > n->key) return delnode(n->right, key);
	else
	{
		/*no child*/
		if(n->left == NULL && n->right == NULL)
		{								
			free(n);
			n = NULL;
			return n;
		}
		/*one child*/
		else if(n->left == NULL)
		{
			node * temp = n;
			n = n->right;
			free(temp);
			return n;
		}
		else if(n->right == NULL)
		{
			node * temp = n;
			n = n->left;
			free(temp);
			return n;			
		}
		/*two childs*/
		else
		{
			node * temp = __findmin(n->right);
			n->key = temp->key;
			n->right = delnode(n->right, temp->key);
		}
	}
	return n;
}


void __ncntr(node * n, int *i)
{
	if(n != NULL)
	{
		*i = *i+1;
		__ncntr(n->left, i);
		__ncntr(n->right, i);
	}
}

void __pncntr(node * n, int *j)
{
	if(n != NULL)
	{
		if( (n->left == NULL && n->right == NULL) || (n->left != NULL && n->right != NULL) )
		*j = *j+1;
		__pncntr(n->left, j);
		__pncntr(n->right, j);
	}
}

int isblnode(node * n)
{
	int i=0, j=0;
	__pncntr(n, &j);
	__ncntr(n, &i);
	if(i>j+1) return TRUE;
	else return FALSE;
}




/*gcc -g -fPIC ex3.c -shared -o bst.so*/