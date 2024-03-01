#include <stdio.h>
void inputArray(int arr[], int size);
void linearSearch(int arr[], int size, int key);
void insertElement(int arr[], int *size, int element, int position);
void deleteElement(int arr[], int *size, int position);
void reverseArray(int arr[], int size);
void updateArray(int arr[], int size);
int main() {
    int arr[100];
    int size, choice, element, position, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    inputArray(arr, size);
    do {
        printf("\nMENU\n");
        printf("1.Linear Search\n");
        printf("2.Insert Element\n");
        printf("3.Delete Element\n");
        printf("4.Reverse Array\n");
        printf("5.Update Array\n");
        printf("6.Take Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                linearSearch(arr, size, key);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertElement(arr, &size, element, position);
                break;
            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            case 4:
                reverseArray(arr, size);
                printf("Array reversed successfully.\n");
                break;
            case 5:
                updateArray(arr, size);
                printf("Array updated successfully.\n");
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 to 6.\n");
        }
    } while (choice != 6);
    return 0;
}
void inputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}
void linearSearch(int arr[], int size, int key) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d.\n", i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Element not found in the array.\n");
    }
}
void insertElement(int arr[], int *size, int element, int position) {
    if (*size >= 100) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }
    if (position < 1 || position > *size + 1) {
        printf("Invalid position to insert.\n");
        return;
    }
    for (int i = *size; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}
void deleteElement(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }
    if (position < 1 || position > *size) {
        printf("Invalid position to delete.\n");
        return;
    }
    for (int i = position - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted successfully.\n");
}
void reverseArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
void updateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            arr[i] += 5;
        } else {
            arr[i] *= 2;
        }
    }
}