#include <stdio.h>
#include "student.h"

int main() {

    struct node *root;
    root = new_node(20);
    printf("\n ");
    insert(root, 12);
    insert(root, 5);
    insert(root, 2);
    insert(root, 9);
    insert(root, 18);
    insert(root, 15);
    insert(root, 13);
    insert(root, 17);
    insert(root, 19);
    inorder(root);
    root = delete(root, 12);
    printf("\n ");
    inorder(root);
    printf("\n ");



    return 0;
}

