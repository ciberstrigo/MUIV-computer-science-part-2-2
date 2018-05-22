#include <stdlib.h>
#include <stdio.h>
#include "ex3.h"



/* TRACE TREE */
node * trace(node * n)
{
    if(n == NULL)
    return NULL;

    printf("%d ", n->key);
    trace(n->left);
    trace(n->right);
}



main()
{
    /*TEST 1 CREATE TREE*/
    node * root = addnode(NULL, 7);
    node * root_l = addnode(root, 3);
    node * root_r = addnode(root, 12);
    node * root_l_l = addnode(root_l, 2);
    node * root_l_r = addnode(root_l, 4);
    node * root_r_r = addnode(root_r, 77);


    /* expected output 7 3 2 4 12 77*/
    printf("--TEST 1--\n");
    printf("expected output: 7 3 2 4 12 77\n");
    printf("actual output  : ");
    trace(root);
    printf("\n");


    /*TEST 2 DELETE (3) NODE*/
    printf("--TEST 2--\n");
    delnode(root, 3);
    printf("expected output: 7 4 2 12 77\n");
    printf("actual output  : ");
    trace(root);
    printf("\n");

    /*TEST 3 BALANCING CHECK*/
    printf("--TEST 3--\n");
    printf("expected output: tree is needeed to ballance\n");
    printf("actual output  : ");
    isblnode(root) ? printf("tree is needeed to ballance\n") : printf("tree is NOT needeed to ballance\n");

    /*TEST 4 SEACHING*/
    printf("--TEST 4--\n");
    printf("expected output: NULL\n");
    node * finded = srchnode(root, 99);
    printf("actual output  : ");
    (finded != NULL) ? printf("%d\n", finded->key) : printf("NULL\n");

    /*TEST 5 SEACHING*/
    printf("--TEST 5--\n");
    printf("expected output: 77\n");
    node * newfinded = srchnode(root, 77);
    printf("actual output  : ");
    (newfinded != NULL) ? printf("%d\n", newfinded->key) : printf("NULL\n");

    /*TEST 6 DELETE ROOT*/
    printf("--TEST 6--\n");
    delnode(root, root->key);
    printf("expected output: 12 4 2 77\n");
    printf("actual output  : ");
    trace(root);
    printf("\n");
}



/*gcc --std=c89 -o test test.c ./bst.so*/