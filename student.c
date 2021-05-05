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
    int e, choice = 0, m, i, id, id2, phone;
    struct node *tree = NULL;
    char name[MAXNAME], enter_id[MAXID], elem2[MAXID], elem3[MAXPHONE], resp, n;


    printf("1......Insert students.\n");
    printf("2......Show the id num in Preorder sort\n");
    printf("3......Show the id num of students on Inorder sort.\n");
    printf("4......Show the id nums of students in Postorder sort\n");
    printf("5......Find a student by his ID.\n");


    while (choice != 8) {
        printf("Choose:");

        scanf("%s", &resp);


        e = errorMenu(resp);
        while (e == TRUE) {
            printf(ERRORNUM);
            scanf("%s", &resp);
            e = errorMenu(resp);
        }

        choice = atoi(&resp);

        switch (choice) {

            case 1:
                printf("Enter no. of students to add: ");
                scanf("%s", &n);
                while (checkNumberinit(n) == TRUE) {
                    printf("ERROR.\nPlease enter a valid number.\n");
                    scanf("%s", &n);
                }
                m = atoi(&n);
                for (i = 0; i < m; i++) {
                    printf("Enter name: ");
                    scanf("%s", &name);
                    while (checkName(name) == TRUE) {
                        printf(ERRORNAME);
                        scanf("%s", &name);
                    }
                    printf("Enter ID num: ");
                    scanf("%s", &elem2);
                    while (checkIDnum(elem2) == TRUE) {
                        printf(ERRORID2);
                        scanf("%s", &elem2);
                    }
                    id = atoi(elem2);
                    printf("Enter phone number: ");
                    scanf("%s", &elem3);
                    while (checkPhoneNum(elem3) == TRUE) {
                        printf(ERRORTEL2);
                        printf("\n");
                        scanf("%s", &elem3);
                    }
                    phone = atoi(elem3);
                    tree = insert_node(tree, id, phone, name);
                    printf("\n");
                }
                printf("\n\n");
                break;

            case 2:
                printf("Postorder sort: ");
                Postorder(tree);
                printf("\n\n");
                break;
            case 3:
                printf("Preorder sort: ");
                Preorder(tree);
                printf("\n\n");
                break;
            case 4:
                printf("Inorder sort: ");
                Inorder(tree);
                printf("\n\n");
                break;
            case 5:
                printf("Enter ID num: ");
                scanf("%s", &enter_id);

                while (checkIDnum(enter_id) == TRUE) {
                    printf(ERRORID2);
                    scanf("%s", &enter_id);
                }
                id2 = atoi(enter_id);
                struct node *search_node = search(id2, tree);
                if (search_node == NULL) {
                    printf(ERRORNODE);
                } else {
                    printf("ID %d and name: %s\n", search_node->ID, search_node->name);
                    printf("Name %s and phone number: %d\n\n", search_node->name, search_node->phone);
                }
                break;

            default:
                printf(ERRORNUM);
                printf("\n");
                break;
        }
    }

    free(tree);
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

int checkName(char *name) {
    int i = 0, error;
    while (name[i] != '\0') {
        if (((65 <= name[i]) && (name[i] < 91)) || ((97 <= name[i]) && (name[i] < 123))) {
            error = FALSE;
        } else {
            error = TRUE;
            break;
        }
        i++;
    }
    return error;
}


int checkIDnum(char *id) {
    int i = 0, error, cont = 0;
    while (id[i] != '\0') {
        if ((48 <= id[i]) && (id[i] < 58)) {
            error = FALSE;
            cont++;
        } else {
            error = TRUE;
            break;
        }
        i++;
    }

    if ((cont > 4) || (cont < 3)) {
        error = TRUE;
        printf(ERRORID);
    }

    return error;
}


int checkPhoneNum(char *phone) {
    int i = 0, error, cont = 0;
    while (phone[i] != '\0') {
        if ((48 <= phone[i]) && (phone[i] < 58)) {
            error = FALSE;
            cont++;
        } else {
            error = TRUE;
            break;
        }
        i++;
    }

    if ((cont > 10) || (cont < 10)) {
        error = TRUE;
        printf(ERRORTEL);
    }

    return error;
}


int checkNumberinit(char k) {
    int error;
    if ((48 <= k) && (k < 58)) {
        error = FALSE;
    } else {
        error = TRUE;
    }
    return error;
}

int errorMenu(char resp) {

    if ((48 <= resp) && (resp < 58)) {
        return FALSE;
    } else {
        return TRUE;
    }
}