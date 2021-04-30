//
// Created by Hunor on 30/04/2021.
//

#ifndef PROJEKT_2_STUDENT_H
#define PROJEKT_2_STUDENT_H
typedef struct node {
    int data;
    struct Student *student;
    struct node *right;
    struct node *left;
} node;
typedef struct Student {
    char name[50];
    int height;


} Student;

node *search(node *root, int x);

node *find_minimum(node *root);

node *new_node(int x);

node *insert(node *root, int x);

node *delete(node *root, int x);

void inorder(node *root);


int minValue(node* node);
int findMax(node *root);
int findMin(node* root);
void findStudent(Student *student);
void deleteStudent(Student *student);
#endif //PROJEKT_2_STUDENT_H
