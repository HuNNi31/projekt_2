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

#define ERRORNUM "ERROR.\nPlease enter a number within the range.\n"
#define ERRORNAME "ERROR.\nPlease enter a name without numbers or special characters.\n"
#define ERRORID "ERROR.\nID number has to be 3-4nums.\n"
#define ERRORID2 "ERROR.\nThe ID must not contain any special characters or letters\n"
#define ERRORTEL "ERROR.\nPhone number has to be 10 numbers\n"
#define ERRORTEL2 "ERROR.\nThe phone number must not contain any special characters or letters.\n"
#define ERRORNODE "ERROR.\nRequested student is not in the database.\n"

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

int getHeight(struct node *tree);

int maxi(int num1, int num2);

struct node *newNode(int ID, int phone, char *name);

struct node *rotation_right(struct node *n2);

struct node *rotation_left(struct node *n2);

struct node *rotation_double_right(struct node *n2);

struct node *rotation_double_left(struct node *n2);

int height_diff(struct node *tree);


int maxi(int num1, int num2);

struct node *insert_node(struct node *node, int Id, int phone, char *name);

void Preorder(struct node *tree);

void Inorder(struct node *tree);

void Postorder(struct node *tree);


int checkNumberinit(char k);

int checkName(char *name);

int checkIDnum(char *id);

int checkPhoneNum(char *telf);

int errorMenu(char resp);

struct node *minValueNode(struct node *node);

struct node *deleteNode(struct node *tree, int ID);

#endif //PROJEKT_2_STUDENT_H
