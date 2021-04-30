//
// Created by Hunor on 30/04/2021.
//

#ifndef PROJEKT_2_STUDENT_H
#define PROJEKT_2_STUDENT_H


#include <stdio.h>
#include <stdlib.h>

struct node {
    int ID;
    char name[50];
    int telefon;
    int height;
    struct node *left;
    struct node *right;
};


void PrintMenu();

int errorMenu(char resp);

struct node *search(int ID, struct node *tree);

int is_empty(struct node *tree);

struct node *newNode(int ID, int phone, char *name);

struct node *insert_node(struct node *node, int Id, int phone);

void Preorder(struct node *tree);

void Inorder(struct node *tree);

void Postorder(struct node *tree);

#endif //PROJEKT_2_STUDENT_H
