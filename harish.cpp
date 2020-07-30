#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    struct node  *left;
    struct node *right; 
};

struct node *root;
struct node *getnewnode(int val){
    struct node *newnode = new node;
    newnode -> key  = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct  node *insert(struct node *root, int val)
{
     if (root == NULL){
         return getnewnode(val) ;
     }
     if (root ->key > val)
     {
         root ->left = insert(root->left,val);
     }
     else if(root->key < val)
     {
         root -> right = insert(root->right,val); 
     }
     return root;
};

void inorder(struct node *root){
    if (root == NULL){
        return ;
    }
    inorder(root->left);
    cout <<(root ->key) <<endl;
    inorder(root->right);
}
void search(struct node *root, int val){
    if (root == NULL){
        return ;
    }
    if (root -> key == val){
        cout<<"success";

    }
    else if(root -> key > val){
        search(root -> left , val);
    }
    else {
        search(root -> right , val);
    }
}

int getminnode(struct node *root){
    struct node* temp = root;
    while (temp->left != NULL)
    {
         temp  = temp -> left;
    }
    return temp->key;
    
}
 struct node *removenode(struct node *root , int val)
 {
     if(root == NULL){
         return NULL;
     }
    if(root -> key > val){
         root -> left = removenode(root->left, val);
     }
        else if(root -> key < val){
         root -> right = removenode(root->right, val);
     }
     else{
         if (root -> left == NULL  && root -> right == NULL){
             free(root);
             return NULL;
         }
         else if(root -> left == NULL)
         {
             struct node *temp = root -> right;
             free(root);
             return temp;
         }
        else if(root -> right == NULL)
         {
             struct node *temp = root -> left;
             free(root);
             return temp;
         }

         else {
             int rightmint = getminnode(root->right);
             root->key = rightmint;
             root->right = removenode(root->right,rightmint);
             

         }
            }
            return root;
 }


int main(){
    struct node *root = NULL;
    root = insert(root,100);
    root = insert(root,150);
    root = insert(root,50);
    root = insert(root,500);
    inorder(root);
    search(root,500);
    root  = removenode(root , 500);
    inorder(root);

 
    return 0;
}


