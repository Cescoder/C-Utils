#include "utils.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Prints an array of integers of size `size`
void printArray(int *array, int size){
    printf("\n[");
    for(int i = 0; i < size; i++){
        printf("%d", array[i]);
        if(i < size - 1)
            printf(",\t");
    }
    printf("]\n");
}

// Fills an array with random numbers between `min` and `max`
void randomArray(int *array, int size, int min, int max){
    for(int i = 0; i < size; i++)
        array[i] = randomNumber(min, max);
}

// Sorts an array of integers using Bubble Sort
void bubbleSort(int *array, int size) {
    for(int i = 0; i < size - 1; i++)
        for(int j = 0; j < size - i - 1; j++)
            if(array[j] > array[j + 1])
                swapInt(&array[j], &array[j + 1]); 
}

// Finds the index of the maximum element in the array
int findMax(int *array, int size){
    int max = 0;
    for(int i = 0; i < size; i++)
        if(array[i] > array[max])
            max = i;
    return max;
}

// Finds the index of the minimum element in the array
int findMin(int *array, int size){
    int min = 0;
    for(int i = 0; i < size; i++)
        if(array[i] < array[min])
            min = i;
    return min;
}

// Writes the contents of an array to a file
void writeArrayToFile(const char *filename, int *array, int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "[");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d", array[i]);
        if(i < size - 1)
            fprintf(file, ",\t");
    }
    fprintf(file, "]\n");
    fclose(file);
}

// Reverses the order of an array
void reverseArray(int *array, int size){
    for(int i = 0; i < size / 2; i++)
        swapInt(&array[i], &array[size - i - 1]);
}

// Returns the sum of the elements in an array
int getSumOfArray(int *array, int size){
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += array[i];
    return sum;
}

// Returns the average of the elements in an array
double getAvarageOfArray(int *array, int size){
    return (double)getSumOfArray(array, size) / size;
}

// Finds the distinct elements in an array
int *getDistinctArray(int *array, int size);

// Checks if an element exists in the array
int arrayContains(int *array, int size, int num){
    for(int i = 0; i < size; i++)
        if(array[i] == num)
            return 1;
    return 0;
}

// Replaces `val1` with `val2` in the array
void arrayReplace(int *array, int size, int val1, int val2){
    for(int i = 0; i < size; i++)
        if(array[i] == val1)
            array[i] = val2;
}

// Dynamically allocates a matrix with dimensions `rows` x `columns`
int **allocateMatrix(int rows, int columns) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(columns * sizeof(int));
    return matrix;
}

// Fills a matrix with random numbers between `min` and `max`
void randomMatrix(int **matrix, int rows, int columns, int min, int max) {
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < columns; j++) 
            matrix[i][j] = randomNumber(min, max);
}

// Prints a matrix
void printMatrix(int **matrix, int rows, int columns) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) 
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Frees the memory allocated for a matrix
void freeMatrix(int **matrix, int rows){
    for(int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

// Converts a string to uppercase
void toUpperCase(char *string) {
    if (string == NULL) return;
    int size = strlen(string);
    for(int i = 0; i < size; i++)
        string[i] = toupper((unsigned char) string[i]);
}

// Converts a string to lowercase
void toLowerCase(char *string) {
    if (string == NULL) return;
    int size = strlen(string);
    for(int i = 0; i < size; i++)
        string[i] = tolower((unsigned char) string[i]);
}

// Counts the occurrences of a character in a string
int countOccurrences(char *string, char c){
    int count = 0;
    int size = strlen(string);
    for(int i = 0; i < size; i++) 
        if(string[i] == c) 
        count++;
    return count;
}

// Returns the length of a string
int stringLenght(char *string){
    return strlen(string);
}

// Replaces `c1` with `c2` in a string
void stringReplace(char *string, char c1, char c2){
    if (string == NULL) return;
    int size = strlen(string);
    for(int i = 0; i < size; i++)
        if(string[i] == c1)
            string[i] = c2;
}

// Checks if a character exists in a string
int stringContains(char *string, char c){
    if (string == NULL) return 0;
    int size = strlen(string);
    for(int i = 0; i < size; i++)
        if(string[i] == c)
            return 1;
    return 0;
}

// Checks if a string starts with another string
int stringStartsWith(char *string, char *startString){
    int startStringSize = strlen(startString);
    int stringSize = strlen(string);
    if(startStringSize > stringSize)
        return 0;
    for(int i = 0; i < startStringSize; i++)
        if(string[i] != startString[i])
            return 0;
    return 1;
}

// Checks if a string ends with another string
int stringEndsWith(char *string, char *endString){
    int endStringSize = strlen(endString);
    int stringSize = strlen(string);
    if(endStringSize > stringSize)
        return 0;
    for(int i = stringSize - endStringSize; i < stringSize; i++)
        if(string[i] != endString[i])
            return 0;
    return 1;
}

// Removes leading and trailing spaces from a string
char *stringTrim(char *string){
    char *end;
    while(isspace((unsigned char)*string)) string++;
    if(*string == 0)  
        return string;
    end = string + strlen(string) - 1;
    while(end > string && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    return string;
}

// Capitalizes the first letter of a string and lowercases the others
void capitalize(char *string) {
    if (string == NULL || *string == '\0') 
        return;
    if (islower(string[0])) 
        string[0] = toupper(string[0]);
    for (int i = 1; string[i] != '\0'; i++)
        if (isupper(string[i])) 
            string[i] = tolower(string[i]);
}

// Reverses a string
void reverseString(char *string){
    int start = 0;
    int end = strlen(string) - 1;
    while (start < end) {
        swapChar(&string[start], &string[end]);
        start++;
        end--;
    }
}

// Checks if a string is empty
int isStringEmpty(char *string){
    return (string == NULL || string[0] == '\0');
}

// Checks if a string is a palindrome
int isStringPalindrome(char *string){
    int size = strlen(string);
    for(int i = 0; i < size / 2; i++)
        if(string[i] != string[size - i - 1])
            return 0;
    return 1;
}

// Swaps two integers
void swapInt(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

// Swaps two characters
void swapChar(char *c1, char *c2) {
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

// Generates a random number between `min` and `max`
int randomNumber(int min, int max){
    return min + rand() % (max - min + 1);
}

// Swap double function
void swapDouble(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Swap float function
void swapFloat(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}


// create a new node for a linked list
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// print a linked list
void printList(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// insert a node at the beginning of the list
void insertAtBeginning(Node **head, int data){
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// insert a node at the end of the list
void insertAtEnd(Node **head, int data){
    Node *newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node *current = *head;
    while(current->next != NULL)
        current = current->next;
    current->next = newNode;
}

// insert a node at a certain position
void insertAtPosition(Node **head, int data, int position){
    if(position < 0){
        printf("Invalid position\n");
        return;
    }
    if(position == 0){
        insertAtBeginning(head, data);
        return;
    }
    Node *newNode = createNode(data);
    Node *current = *head;
    for(int i = 0; i < position - 1; i++){
        if(current == NULL){
            printf("Invalid position\n");
            return;
        }
        current = current->next;
    }
    if(current == NULL){
        printf("Invalid position\n");
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// delete a node with a certain value
void deleteNode(Node **head, int data){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    Node *current = *head;
    if(current->data == data){
        *head = current->next;
        free(current);
        return;
    }
    while(current->next != NULL && current->next->data != data)
        current = current->next;
    if(current->next == NULL){
        printf("Element not found\n");
        return;
    }
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

// delete a node at a certain position
void deleteAtPosition(Node **head, int position){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    if(position == 0){
        Node *temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }
    Node *current = *head;
    for(int i = 0; i < position - 1; i++){
        if(current == NULL){
            printf("Invalid position\n");
            return;
        }
        current = current->next;
    }
    if(current == NULL || current->next == NULL){
        printf("Invalid position\n");
        return;
    }
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

// check if a linked list contains a certain value
int listContains(Node *head, int data){
    Node *current = head;
    while(current != NULL){
        if(current->data == data)
            return 1;
        current = current->next;
    }
    return 0;
}

// return the lenght of a linked list
int listLenght(Node *head){
    int count = 0;
    Node *current = head;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

// reverse a linked list
void reverseList(Node **head){
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// free a linked list
void freeList(Node **head){
    Node *current = *head;
    Node *next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

// create a new node for a binary tree
TreeNode *createTreeNode(int data){
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// insert a new node in a binary tree
void insertTreeNode(TreeNode **root, int data){
    if(*root == NULL){
        *root = createTreeNode(data);
        return;
    }
    if(data < (*root)->data)
        insertTreeNode(&(*root)->left, data);
    else
        insertTreeNode(&(*root)->right, data);
}

// print a binary tree in order
void printTreeInOrder(TreeNode *root){
    if(root == NULL)
        return;
    printTreeInOrder(root->left);
    printf("%d ", root->data);
    printTreeInOrder(root->right);
}

// print a binary tree in pre order
void printTreePreOrder(TreeNode *root){
    if(root == NULL)
        return;
    printf("%d ", root->data);
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}

// print a binary tree in post order
void printTreePostOrder(TreeNode *root){
    if(root == NULL)
        return;
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);
    printf("%d ", root->data);
}

// free a binary tree
void freeTree(TreeNode **root){
    if(*root == NULL)
        return;
    freeTree(&(*root)->left);
    freeTree(&(*root)->right);
    free(*root);
    *root = NULL;
}

// check if a binary tree contains a certain value
int treeContains(TreeNode *root, int data){
    if(root == NULL)
        return 0;
    if(root->data == data)
        return 1;
    if(data < root->data)
        return treeContains(root->left, data);
    return treeContains(root->right, data);
}

// return the height of a binary tree
int treeHeight(TreeNode *root){
    if(root == NULL)
        return -1;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// return the number of leaves in a binary tree
int treeLeaves(TreeNode *root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return treeLeaves(root->left) + treeLeaves(root->right);
}

// find the number of nodes in a binary tree
int treeNodes(TreeNode *root){
    if(root == NULL)
        return 0;
    return 1 + treeNodes(root->left) + treeNodes(root->right);
}

// return the sum of all the elements in a binary tree
int treeSum(TreeNode *root){
    if(root == NULL)
        return 0;
    return root->data + treeSum(root->left) + treeSum(root->right);
}

// find the maximum value in a binary tree
int treeMax(TreeNode *root){
    if(root == NULL)
        return -1;
    if(root->right == NULL)
        return root->data;
    return treeMax(root->right);
}

// find the minimum value in a binary tree
int treeMin(TreeNode *root){
    if(root == NULL)
        return -1;
    if(root->left == NULL)
        return root->data;
    return treeMin(root->left);
}

// Write a string to a file
void writeStringToFile(const char *filename, char *string){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "%s\n", string);
    fclose(file);
}

// Write an integer to a file
void writeIntToFile(const char *filename, int num){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "%d\n", num);
    fclose(file);
}

// Write a double to a file
void writeDoubleToFile(const char *filename, double num){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "%lf\n", num);
    fclose(file);
}

// Write a character to a file
void writeCharToFile(const char *filename, char c){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "%c\n", c);
    fclose(file);
}

// Write an integer array to a file
void writeIntArrayToFile(const char *filename, int *array, int size){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "[");
    for(int i = 0; i < size; i++){
        fprintf(file, "%d", array[i]);
        if(i < size - 1)
            fprintf(file, ",\t");
    }
    fprintf(file, "]\n");
    fclose(file);
}

// Write a double array to a file
void writeMatrixToFile(const char *filename, int **matrix, int rows, int columns){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening file %s\n", filename);
        return;
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++)
            fprintf(file, "%d,\t", matrix[i][j]);
        fprintf(file, "\n");
    }
    fclose(file);
}

// Write a linked list to a file
void writeListToFile(const char *filename, Node *head){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening file %s\n", filename);
        return;
    }
    Node *current = head;
    while(current != NULL){
        fprintf(file, "%d -> ", current->data);
        current = current->next;
    }
    fprintf(file, "NULL\n");
    fclose(file);
}

// Write a binary tree to a file
void writeTreeToFile(const char *filename, TreeNode *root){
    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening file %s\n", filename);
        return;
    }
    printTreeInOrder(root);
    fclose(file);
}










