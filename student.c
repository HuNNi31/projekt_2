//
// Created by Hunor on 30/04/2021.
//


#include "student.h"
#include <stdio.h>
#include <malloc.h>


void Inorder(struct node *tree) {
    if (!(is_empty(tree))) {
        Inorder(tree->left);
        printf("%d ", tree->ID);
        Inorder(tree->right);
    }
}

void Preorder(struct node *tree) {
    if (!(is_empty(tree))) {
        printf("%d ", tree->ID);
        Preorder(tree->left);
        Preorder(tree->right);
    }
}

void Postorder(struct node *tree) {
    if (!(is_empty(tree))) {
        Preorder(tree->left);
        Preorder(tree->right);
        printf("%d ", tree->ID);
    }
}

void PrintMenu() {
    int choice = 0, m, i, id, phone;
    struct node *tree = NULL;
    char name[MAXNAME], elem2[MAXID], elem3[MAXPHONE], n;


    printf("1......Insert students.\n");
    printf("2......Show the id num in Preorder sort\n");
    printf("3......Show the id num of students on Inorder sort.\n");
    printf("4......Show the id nums of students in Postorder sort\n");


    while (1) {
        printf("Choose:");

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter no. of students to add: ");
                scanf("%s", &n);

                m = atoi(&n);
                for (i = 0; i < m; i++) {
                    printf("Enter name: ");
                    scanf("%s", &name);

                    printf("Enter ID num: ");
                    scanf("%s", &elem2);


                    id = atoi(elem2);
                    printf("Enter phone number: ");
                    scanf("%s", &elem3);


                    phone = atoi(elem3);
                    tree = insert_node(tree, id, phone, name);
                    printf("\n");
                }
                printf("\n");
                break;


            case 2:
                //PreOrder
                Preorder(tree);
                printf("\n");
                break;
            case 3:
                //InOrder.
                Inorder(tree);
                printf("\n");
                break;
            case 4:
                //PostOrder.
                Postorder(tree);
                printf("\n");
                break;

        }
    }
}

struct node *newNode(int Id, int phone, char *name) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    if (node == NULL) {
        printf("ERROR.\n Could not create a new node.");
    } else {
        strcpy(node->name, name);
        node->ID = Id;
        node->phone = phone;
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

int is_empty(struct node *tree) {
    if (tree != NULL) {

        return FALSE;
    } else {
        return TRUE;
    }
}
