#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lc, *rc;
} *root = NULL;

void insert(int data) {
    struct node *p = root, *parentOfP = NULL;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->lc = newNode->rc = NULL;
    if (root == NULL) {
        root = newNode;
        return;
    }
    while (p != NULL) {
        parentOfP = p;
        if (data < p->data) {
            p = p->lc;
        } else if (data > p->data) {
            p = p->rc;
        } else {
            printf("Node already exists!\n");
            free(newNode);
            return;
        }
    }
    if (data < parentOfP->data) {
        parentOfP->lc = newNode;
    } else {
        parentOfP->rc = newNode;
    }
}

struct node* inorderSuccessor(struct node *p) {
    struct node *ptr1 = p->rc;
    while (ptr1 != NULL && ptr1->lc != NULL) {
        ptr1 = ptr1->lc;
    }
    return ptr1;
}

struct node* deleteNode(struct node *rootNode, int data) {
    if (rootNode == NULL) return NULL;

    if (data < rootNode->data) {
        rootNode->lc = deleteNode(rootNode->lc, data);
    } else if (data > rootNode->data) {
        rootNode->rc = deleteNode(rootNode->rc, data);
    } else {
        if (rootNode->lc == NULL) {
            struct node *temp = rootNode->rc;
            free(rootNode);
            return temp;
        } else if (rootNode->rc == NULL) {
            struct node *temp = rootNode->lc;
            free(rootNode);
            return temp;
        }
        struct node *temp = inorderSuccessor(rootNode);
        rootNode->data = temp->data;
        rootNode->rc = deleteNode(rootNode->rc, temp->data);
    }
    return rootNode;
}

void inOrder(struct node *p) {
    if (p != NULL) {
        inOrder(p->lc);
        printf("%d ", p->data);
        inOrder(p->rc);
    }
}

void preOrder(struct node *p) {
    if (p != NULL) {
        printf("%d ", p->data);
        preOrder(p->lc);
        preOrder(p->rc);
    }
}

void postOrder(struct node *p) {
    if (p != NULL) {
        postOrder(p->lc);
        postOrder(p->rc);
        printf("%d ", p->data);
    }
}

int main() {
    int choice, element, traversal;
    printf("This is a menu driven program for Binary Search Tree!\n");
    while (1) {
        printf("What would you like to do today?\n");
        printf("1 - Insertion\n2 - Deletion\n3 - Traversal\n4 - Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert : ");
                scanf("%d", &element);
                insert(element);
                break;
            case 2:
                printf("Enter the element to delete : ");
                scanf("%d", &element);
                root = deleteNode(root, element);
                break;
            case 3:
                printf("Which traversal?\n1 - Inorder\n2 - Preorder\n3 - Postorder\nEnter your choice : ");
                scanf("%d", &traversal);
                if (traversal == 1) {
                    inOrder(root);
                } else if (traversal == 2) {
                    preOrder(root);
                } else {
                    postOrder(root);
                }
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid symbol!\n");
                break;
        }
    }
}
