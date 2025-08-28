///TO-DO

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left_child;
    struct node* right_child;
};

struct node* newNode(int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left_child = NULL;
    temp->right_child = NULL;
    return temp;
}
struct node* insert(struct node* root,int x){
    if(root == NULL) newNode(x);
    else{
        if(x < root->data) root->left_child = insert(root->left_child,x);
        else root->right_child = insert(root->right_child,x);
        return root;
    }
}
void traversal(struct node* root){
    if(root == NULL) return;
    else{
        traversal(root->left_child);
        printf("%d\t",root->data);
        traversal(root->right_child);
    }
}
struct node* min(struct node* root){
    if(root->left_child != NULL) min(root->left_child);
    else return root;
}
struct node* search(struct node* root, int x);
void delete(struct node* root,int data);


int main(void){
    struct node* root = newNode(5);
    insert(root,1);
    insert(root,15);
    traversal(root);
    return 0;
}