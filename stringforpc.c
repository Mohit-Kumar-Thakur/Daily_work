#include <stdio.h>


int stringLength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}


void stringReverse(char str[]) {
    int length = stringLength(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        
        start++;
        end--;
    }
}
int stringCompare(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;  /
        }
        i++;
    }

    
    if (str1[i] != '\0' || str2[i] != '\0') {
        return 0; 
    }

    return 1;  
}


void stringConcatenate(char result[], const char str1[], const char str2[]) {
    int i = 0, j = 0;

    
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    
    while (str2[j] != '\0') {
        result[i + j] = str2[j];
        j++;
    }

    
    result[i + j] = '\0';
}

void stringCopy(char destination[], const char source[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    
    destination[i] = '\0';
}

int main() {
    char str1[100], str2[100], result[200];


    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    
    int i = 0;
    while (str1[i] != '\0' && str1[i] != '\n') {
        i++;
    }
    if (str1[i] == '\n') {
        str1[i] = '\0';
    }

    i = 0;
    while (str2[i] != '\0' && str2[i] != '\n') {
        i++;
    }
    if (str2[i] == '\n') {
        str2[i] = '\0';
    }


    printf("\nString Length:\n");
    printf("Length of the first string: %d\n", stringLength(str1));
    printf("Length of the second string: %d\n", stringLength(str2));

    
    printf("\nString Reversal:\n");
    stringReverse(str1);
    stringReverse(str2);
    printf("Reversed first string: %s\n", str1);
    printf("Reversed second string: %s\n", str2);


    printf("\nString Compare:\n");
    if (stringCompare(str1, str2)) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    
    printf("\nString Concatenate:\n");
    stringConcatenate(result, str1, str2);
    printf("Concatenated string: %s\n", result);

    
    printf("\nString Copy:\n");
    char copiedString[100];
    stringCopy(copiedString, str1);
    printf("Copied string: %s\n", copiedString);

    return 0;
}