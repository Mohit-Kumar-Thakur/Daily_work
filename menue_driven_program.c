#include <stdio.h>

void linearSearch(int arr[], int size, int element) {
    
}

void insertElement(int arr[], int *size, int position, int element) {
}

void deleteElement(int arr[], int *size, int position) {

}

void reverseArray(int arr[], int size) {

}

void updateArray(int arr[], int size) {
}

int main() {
    int choice, element, position;
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];

    do {
        printf("\nMenu:\n1. Linear Search\n2. Insert Element\n3. Delete Element\n4. Reverse Array\n5. Update Array\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                linearSearch(arr, size, element);
                break;

            case 2:
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(arr, &size, position, element);
                break;

            case 3:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;

            case 4:
                reverseArray(arr, size);
                break;

            case 5:
                updateArray(arr, size);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(choice != 0);

    return 0;
}