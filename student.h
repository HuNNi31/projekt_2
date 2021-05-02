//
// Created by Hunor on 30/04/2021.
//

#ifndef PROJEKT_2_STUDENT_H
#define PROJEKT_2_STUDENT_H
#define MAXNAME       50
#define MAXID        1000
#define MAXPHONE      10
#define TRUE         1
#define FALSE        0
#include <stdio.h>
#include <stdlib.h>
#include "string.h"


struct node {
    int ID;
    char name[MAXNAME];
    int phone;
    int height;
    struct node *left;
    struct node *right;
};


void PrintMenu();


struct node *search(int ID, struct node *tree);

int is_empty(struct node *tree);

struct node *newNode(int ID, int phone, char *name);

struct node *insert_node(struct node *node, int Id, int phone, char *name);

void Preorder(struct node *tree);

void Inorder(struct node *tree);

void Postorder(struct node *tree);

#endif //PROJEKT_2_STUDENT_H
