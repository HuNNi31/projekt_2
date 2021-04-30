//
// Created by Hunor on 30/04/2021.
//


#include "student.h"
#include <stdio.h>
#include <malloc.h>

struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x)
        return root;
    else if(x>root->data)
        return search(root->right, x);
    else
        return search(root->left,x);
}

struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL)
        return find_minimum(root->left);
    return root;
}


struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{

    if(root==NULL)
        return new_node(x);
    else if(x>root->data)
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left,x);
    return root;
}
// funnction to delete a node
struct node* delete(struct node *root, int x)
{

    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right = delete(root->right, x);
    else if(x<root->data)
        root->left = delete(root->left, x);
    else
    {

        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }


        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}

int findMax(struct node *root)
{
    // Base case
    if (root == NULL)
        return 0;

    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}

int findMin(struct node* root)
{
    // Base case
    if (root == NULL)
        return 0;

    // Return minimum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = findMin(root->left);
    int rres = findMin(root->right);
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}