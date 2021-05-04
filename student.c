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

struct node *rotation_right(struct node *n2) {
    struct node *n1 = NULL;
    n1 = n2->left;
    n2->left = n1->right;
    n1->right = n2;
    n2->height = maxi(getHeight(n2->left), getHeight(n2->right)) + 1;
    n1->height = maxi(getHeight(n1->right), getHeight(n1->left)) + 1;
    return (n1);
}


struct node *rotation_left(struct node *n2) {
    struct node *n1 = NULL;
    n1 = n2->right;
    n2->right = n1->left;
    n1->left = n2;
    n2->height = maxi(getHeight(n2->left), getHeight(n2->right)) + 1;
    n1->height = maxi(getHeight(n1->right), getHeight(n1->left)) + 1;
    return (n1);
}


struct node *rotation_double_right(struct node *n2) {
    n2->right = rotation_right(n2->right);
    n2 = rotation_left(n2);
    return (n2);
}


struct node *rotation_double_left(struct node *n2) {
    n2->left = rotation_left(n2->left);
    n2 = rotation_right(n2);
    return (n2);
}

struct node *insert_node(struct node *node, int ID, int phone, char *name) {
    int dif_height;
    if (is_empty(node)) {
        return (newNode(ID, phone, name));
    } else if (ID > node->ID) {
        node->right = insert_node(node->right, ID, phone, name);
    } else if (ID < node->ID) {
        node->left = insert_node(node->left, ID, phone, name);
    } else {
        return (node);
    }
    node->height = 1 + maxi(getHeight(node->right), getHeight(node->left));
    dif_height = height_diff(node);
    if ((dif_height > 1) && (ID < node->left->ID)) {
        return (rotation_right(node));
    }
    if ((dif_height > 1) && (ID > node->left->ID)) {
        return (rotation_double_left(node));
    }
    if ((dif_height < -1) && (ID > node->right->ID)) {
        return (rotation_left(node));
    }
    if ((dif_height < -1) && (ID < node->right->ID)) {
        return (rotation_double_right(node));
    }
    return (node);
}

int is_empty(struct node *tree) {
    if (tree != NULL) {

        return FALSE;
    } else {
        return TRUE;
    }
}

int getHeight(struct node *tree) {
    if (is_empty(tree)) {
        return 0;
    } else {
        return (tree->height);
    }
}


int height_diff(struct node *tree) {
    if (is_empty(tree)) {
        return 0;
    } else {
        return ((getHeight(tree->left)) - (getHeight(tree->right)));
    }
}

int maxi(int num1, int num2) {
    int result;
    if (num1 > num2)
        result = num1;
    else
        result = num2;
    return result;
}