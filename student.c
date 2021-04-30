//
// Created by Hunor on 30/04/2021.
//


#include "student.h"
#include <stdio.h>
#include <malloc.h>

#include "student.h"


struct node *newNode(int Id, int phone) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    if (node == NULL) {
        printf("ERROR.\n Could not create a new node.");
    } else {
        strcpy(node->name, name);
        node->ID = Id;
        node->telefon = phone;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return (node);
    }
}

struct node *search(int ID, struct node *tree) {
    if (is_empty(tree)) {
        return NULL;
    }
    if (ID < tree->ID) {
        return search(ID, tree->left);
    } else if (ID > tree->ID) {
        return search(ID, tree->right);
    } else {
        return tree;
    }
}


struct node *insert_node(struct node *node, int ID, int phone, char *name) {
    int difer_alturas;

    //We insert node looking if it is greater or less than the root
    if (is_empty(node)) {
        return (newNode(ID, phone, name));
    } else if (ID > node->ID) {
        node->right = insert_node(node->right, ID, phone, name);
    } else if (ID < node->ID) {
        node->left = insert_node(node->left, ID, phone, name);
    } else {
        return (node);
    }

}