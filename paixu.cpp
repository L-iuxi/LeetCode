#include<stdio.h>
#include<stdlib.h>
typedef struct BinaryTreeNode
{
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
    char data;
}BtNode;

void Prevorder(BtNode* root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%c",root->data);
    Prevorder(root->left);
    Prevorder(root->right);
}
int main()
{
    BtNode* A = (BtNode*)malloc(sizeof(BtNode));
    A->data = 'A';
    A->left = NULL;
    A->right = NULL;

    BtNode* B = (BtNode*)malloc(sizeof(BtNode));
    B->data = 'B';
    B->left = NULL;
    B->right = NULL;
    
    BtNode* C = (BtNode*)malloc(sizeof(BtNode));
    C->data = 'C';
    C->left = NULL;
    C->right = NULL;
    
    BtNode* D = (BtNode*)malloc(sizeof(BtNode));
    D->data = 'D';
    D->left = NULL;
    D->right = NULL;
    
    BtNode* E = (BtNode*)malloc(sizeof(BtNode));
    E->data = 'E';
    E->left = NULL;
    E->right = NULL;

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;

    Prevorder(A);
    
}