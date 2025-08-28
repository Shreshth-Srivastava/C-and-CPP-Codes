#include<stdio.h>
#include<stdlib.h>

/*
• Constraints: No. of node --> [0,10^5]
Better Approach: Use recursion
My Approach: I need to apply BFS --> given left and right pointers --> Need a queue to hold struct TreeNode pointers
*/

// Using recursion

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int minDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    else {
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if ((leftDepth==0) ^ (rightDepth==0)) return (leftDepth>rightDepth?leftDepth:rightDepth)+1; //which returns max(left,right)+1
        // ^ is the Bitwise XOR operator
        if(leftDepth > rightDepth)
            return rightDepth + 1;
        else
            return leftDepth + 1;
    }
}

int main(void){

    return 0;
}

/*My Approach
// struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };

// void enqueue(struct TreeNode* queue[], int *top, struct TreeNode* ptr){
//     *top = *top + 1;
//     queue[*top] = ptr;
//     return;
// };

// struct TreeNode* dequeue(struct TreeNode* queue[], int *rear){
//     struct TreeNode* p =  queue[*rear];
//     *rear = *rear + 1;
//     return p;
// };

// int minDepth(struct TreeNode* root) {
//     if(root == NULL) return 0;
//     struct TreeNode* queue[1000]; //Update the range
//     int top = -1, rear = 0;
//     struct TreeNode* ptr;
//     if(root->left != NULL){
//         queue[0] = root->left;
//         top++;
//     }
//     if(root->right != NULL){
//         queue[1] = root->right;
//         top++;
//     }
//     int counter = 1;
//     ptr = dequeue(queue, &rear);
//     enqueue(queue, &top, ptr->left);
//     enqueue(queue, &top, ptr->right);
// }

// int main(void){

//     return 0;
// }
*/