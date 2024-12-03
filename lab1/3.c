//wap to declare an employee structure with required member variable to store and display the employee details in c language


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Employee{
    int employeeId;
    char name[40];
    float salary;
}

int main() {

    struct Employee emp1;

    printf("Enter employee name: ");
    fgets(emp1.name, sizeof(emp1.name), stdin);
    emp1.name[strcspn(emp1.name, "\n")] = '\0';

    printf("Enter employee ID: ");
    scanf("%d", &emp1.employeeId);

    printf("Enter employee salary: ");
    scanf("%f", &emp1.salary);

    printf("\nEmployee Details:\n");
    printf("Name: %s\n", emp1.name);
    printf("Employee ID: %d\n", emp1.employeeId);
    printf("Salary: %f\n", emp1.salary);

    return 0;
}