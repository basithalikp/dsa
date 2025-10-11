#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 10
#define MEANING_SIZE 100

struct node {
    char word[WORD_SIZE];
    char meaning[MEANING_SIZE];
    struct node *lc, *rc;
} *root = NULL;

struct node *createNode(char word[], char meaning[]){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->lc = newNode->rc = NULL;
    return newNode;
}

struct node* insert(char word[], char meaning[], struct node *chroot) {
    if (chroot == NULL) {
        return createNode(word, meaning);
    }
    if (strcmp(word, chroot->word) < 0)
    {
        chroot->lc = insert(word, meaning, chroot->lc);
    }
    else if (strcmp(word, chroot->word) > 0)
    {
        chroot->rc = insert(word, meaning, chroot->rc);
    }
    else
    {
        printf("Word already exists!\n");
    }
    return chroot;
}

void search(char word[], struct node *chroot) {
    if (chroot == NULL) {
        printf("No word found in dictionary!\n");
        return;
    }
    if (strcmp(word, chroot->word) < 0)
    {
        search(word, chroot->lc);
    }
    else if (strcmp(word, chroot->word) > 0)
    {
        search(word, chroot->rc);
    }
    else
    {
        printf("Meaning of %s:\n%s\n", chroot->word, chroot->meaning);
    }
}

struct node* inorderSuccessor(struct node *p) {
    struct node *ptr1 = p->rc;
    while (ptr1 != NULL && ptr1->lc != NULL) {
        ptr1 = ptr1->lc;
    }
    return ptr1;
}

struct node* deleteNode(struct node *rootNode, char word[WORD_SIZE]) {
    if (rootNode == NULL) return NULL;

    if (strcmp(word, rootNode->word) < 0) {
        rootNode->lc = deleteNode(rootNode->lc, word);
    } else if (strcmp(word, rootNode->word) > 0) {
        rootNode->rc = deleteNode(rootNode->rc, word);
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
        strcpy(rootNode->word, temp->word);
        strcpy(rootNode->meaning, temp->meaning);
        rootNode->rc = deleteNode(rootNode->rc, temp->word);
    }
    return rootNode;
}

void inOrder(struct node *p) {
    if (p != NULL) {
        inOrder(p->lc);
        printf("Word: %s\nMeaning: %s\n\n", p->word, p->meaning);
        inOrder(p->rc);
    }
}

int main() {
    int choice;
    char word[WORD_SIZE], meaning[MEANING_SIZE];
    printf("This is a menu driven program for Dictionary using Binary Search Tree!\n");
    while (1) {
        printf("What would you like to do today?\n");
        printf("1 - Insertion\n2 - Deletion\n3 - Display\n4 - Search\n5 - Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the word to insert: ");
                scanf("%s", word);
                printf("Enter the meaning of that word: ");
                scanf("%s",meaning);
                root = insert(word, meaning, root);
                break;
            case 2:
                printf("Enter the word to delete: ");
                scanf("%s", word);
                root = deleteNode(root, word);
                break;
            case 3:
                if (root == NULL) {
                    printf("Dictionary is empty!\n");
                } else {
                    inOrder(root);
                }
                break;
            case 4:
                printf("Enter the word to know meaning: ");
                scanf("%s", word);
                search(word, root);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}