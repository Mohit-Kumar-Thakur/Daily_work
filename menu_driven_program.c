#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n)
{
    printf("The array elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linear_search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void insert(int arr[], int *n, int pos, int val)
{
    if (*n == 100) 
    {
        printf("Array is full, cannot insert.\n");
        return;
    }
    if (pos < 0 || pos > *n)
    {
        printf("Invalid position, cannot insert.\n");
        return;
    }
   
    for (int i = *n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
   
    arr[pos] = val;

    (*n)++;
}


void delete (int arr[], int *n, int pos)
{
    if (*n == 0)
    {
        printf("Array is empty, cannot delete.\n");
        return;
    }
    if (pos < 0 || pos >= *n)
    {
        printf("Invalid position, cannot delete.\n");
        return;
    }
    
    for (int i = pos; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    
    (*n)--;
}

void reverse(int arr[], int n)
{

    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void update(int arr[], int n)
{

    for (int i = 1; i < n; i += 2)
    {
        arr[i] *= 2;
    }
   
    for (int i = 0; i < n; i += 2)
    {
        arr[i] += 5;
    }
}


int main()
{
    int arr[100]; 
    int n;        
    int choice;  
    int key, pos, val; 

    printf("Enter the size of the array: ");
    scanf("%d", &n); 

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); 
    }

    do
    {
      
        printf("\nMenu\n");
        printf("1. Linear search for an element\n");
        printf("2. Inserting an element at specified position\n");
        printf("3. Deleting an element from the specified position\n");
        printf("4. Reversing the array\n");
        printf("5. Updating the array\n");
        printf("6. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice); 

        switch (choice)
        {
        case 1:
            printf("Enter the element to search: ");
            scanf("%d", &key); 
            pos = linear_search(arr, n, key); 
            if (pos == -1) 
            {
                printf("Element not found.\n");
            }
            else
            {
                printf("Element found at index %d.\n", pos);
            }
            break;
        case 2:
            printf("Enter the element to insert: ");
            scanf("%d", &val);
            printf("Enter the position to insert: ");
            scanf("%d", &pos);
            insert(arr, &n, pos, val);
            printf("Element inserted.\n");
            display(arr, n); 
            break;
        case 3:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            val = arr[pos];
            delete (arr, &n, pos);
            printf("Element %d deleted.\n", val);
            display(arr, n);
            break;
        case 4:
            reverse(arr, n);
            printf("Array reversed.\n");
            display(arr, n);
            break;
        case 5:
            update(arr, n);
            printf("Array updated.\n");
            display(arr, n);
            break;
        case 6:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    } while (choice != 6);

    return 0;
}