/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

struct info {
    char name[50];
    int roll_no;
};

int main() {
    int n, a = 0, b, z = 1;
    
    printf("Enter Number Of Total Students: ");
    scanf("%d", &n);
    
    struct info std[n + 1]; // Allocating an extra space for insertion

    printf("Enter Details Of Students\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d\n", i + 1);
        printf("Enter Name: ");
        scanf("%s", std[i].name);
        printf("Enter Roll No: ");
        scanf("%d", &std[i].roll_no);
    }

    // Display student information
    printf("\nStudent Information\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", std[i].name);
        printf("Roll No: %d\n", std[i].roll_no);
    }

    // Insert new student
    printf("\nDo You Want To Insert Information Again? If Yes, Enter 1: ");
    scanf("%d", &a);
    if (a == 1) {
        printf("At what position (1 to %d)?: ", n);
        scanf("%d", &b);
        b--; // Convert to zero-based index

        if (b >= 0 && b <= n) {
            for (int i = n; i > b; i--) {
                std[i] = std[i - 1];
            }

            printf("Enter Name: ");
            scanf("%s", std[b].name);
            printf("Enter Roll No: ");
            scanf("%d", &std[b].roll_no);

            n++; // Increase the number of students

            printf("\nUpdated Student Information\n");
            for (int i = 0; i < n; i++) {
                printf("Student %d\n", i + 1);
                printf("Name: %s\n", std[i].name);
                printf("Roll No: %d\n", std[i].roll_no);
            }
        } else {
            printf("Invalid position!\n");
        }
    }

    // Delete a student
    printf("\nDo You Want To Delete Information Of Any Student? If Yes, Enter 1: ");
    scanf("%d", &z);
    if (z == 1) {
        printf("Enter Index Number (1 to %d): ", n);
        scanf("%d", &b);
        b--; // Convert to zero-based index

        if (b >= 0 && b < n) {
            for (int i = b; i < n - 1; i++) {
                std[i] = std[i + 1];
            }
            n--; // Decrease the number of students

            printf("\nNewly Updated Student Information\n");
            for (int i = 0; i < n; i++) {
                printf("Student %d\n", i + 1);
                printf("Name: %s\n", std[i].name);
                printf("Roll No: %d\n", std[i].roll_no);
            }
        } else {
            printf("Invalid index!\n");
        }
    }

    return 0;
}