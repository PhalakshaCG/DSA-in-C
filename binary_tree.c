#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define PRE 1
#define POST 2
#define IN 3

typedef struct t{
    int val;
    struct t* parent;
    struct t* left;
    struct t* right;
}tree;

void insertL(tree* node, int val){
    node->left = (tree*)malloc(sizeof(tree));
    node->left->val = val;
    node->left->left = NULL;
    node->left->right = NULL;
    node->left->parent = node;
}

void insertRight(tree* node, int val){
    node->right = (tree*)malloc(sizeof(tree));
    node->right->val = val;
    node->right->left = NULL;
    node->right->right = NULL;
    node->right->parent = node;
}

tree* initNode(tree* node, int val){
    if(node == NULL){
        node = (tree*)malloc(sizeof(tree));
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
    }
    node->val = val;
    return node;
}

tree* insertAuto(tree* node, int val){
    if(node == NULL){
        node = initNode(node, val);
        return node;
    }
    if(val <=  node->val){
        if(node->left == NULL)
            insertL(node,val);
        else{
            insertAuto(node->left,val);
        }
    }
    else{
        if(node->right == NULL)
            insertRight(node, val);
        else{
            insertAuto(node->right,val);
        }
    }
    return node;
}

void post(tree* node){
    if(node->left)
        post(node->left);
    if(node->right)
        post(node->right);
    if(node){
        printf("%d ", node->val);
    }
}

void postOrder(tree* node){
    post(node);
    printf("\n");
}

void pre(tree* node){
    if(node){
        printf("%d ", node->val);
    }
    if(node->left)
        pre(node->left);
    if(node->right)
        pre(node->right);
}

void preOrder(tree* node){
    pre(node);
    printf("\n");
}

void in(tree* node){
    if(node->left)
        in(node->left);
    if(node){
        printf("%d ", node->val);
    }
    if(node->right)
        in(node->right);
}

void inOrder(tree* node){
    in(node);
    printf("\n");
}

tree* inputList(tree* start){
    char number[128];
    int value;
    do{
        scanf("%s",number);
        if(!isdigit(number[0]))
            break;
        value = atoi(number);
        start = insertAuto(start, value);
    }while(1);
    return start;
}

int main(){
    printf("Enter the contents of the tree(~ to exit)\n");
    tree *node = NULL, *lnode = NULL, *rnode = NULL;
    node = inputList(node);
    printf("Post order:\n");
    postOrder(node);
    printf("Pre order:\n");
    preOrder(node);
    printf("In order:\n");
    inOrder(node);
}