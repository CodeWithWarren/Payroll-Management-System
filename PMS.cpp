// Group 20 Final Project: Payroll Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[50];
    int age;
    char address[100];
    char phoneNumber[15];
    int idNumber;
    float salaryRatePerDay;
};

void calculateSalary();
void addEmployee();
void updateEmployee();
void searchEmployee();
void deleteEmployee();
void printPayslip();
void displayMenu();

void writeEmployeeToFile(struct Employee emp);
void readEmployeeFromFile(int id, char* lastName, struct Employee* emp);

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculateSalary();
                break;
            case 2:
                addEmployee();
                break;
            case 3:
                updateEmployee();
                break;
            case 4:
                searchEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                printPayslip();
                break;
            case 7:
                printf("Exiting the Payroll Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }

    } while (choice != 7);

    return 0;
}

void displayMenu() {
    printf("\nPayroll Management System Menu:\n");
    printf("1. Calculate Monthly Salary\n");
    printf("2. Add New Employee\n");
    printf("3. Update Employee Information\n");
    printf("4. Search for Employee\n");
    printf("5. Delete Employee\n");
    printf("6. Print/Display Payslip\n");
    printf("7. Exit\n");
}

void calculateSalary() {
    printf("Calculating Monthly Salary...\n");
}

void addEmployee() {
    struct Employee newEmployee;

    printf("Enter Employee Information:\n");
    printf("Name: ");
    scanf("%s", newEmployee.name);

    printf("Enter Employee ID: ");
    scanf("%d", &newEmployee.idNumber);

    writeEmployeeToFile(newEmployee);
}

void updateEmployee() {
    int id;
    char lastName[50];

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    printf("Enter Employee Lastname: ");
    scanf("%s", lastName);

    struct Employee emp;
    readEmployeeFromFile(id, lastName, &emp);

    printf("Update Employee Information:\n");
    printf("Name (%s): ", emp.name);
    scanf("%s", emp.name);

    writeEmployeeToFile(emp);
}

void searchEmployee() {
    int id;
    char lastName[50];

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    printf("Enter Employee Lastname: ");
    scanf("%s", lastName);

    struct Employee emp;
    readEmployeeFromFile(id, lastName, &emp);

    if (emp.idNumber == -1) {
        printf("Employee not yet registered.\n");
    } else {
        printf("Employee Information:\n");
        printf("Name: %s\n", emp.name);
        printf("Age: %d\n", emp.age);
        printf("Address: %s\n", emp.address);
        printf("Phone Number: %s\n", emp.phoneNumber);
        printf("ID Number: %d\n", emp.idNumber);
        printf("Salary Rate per Day: %.2f\n", emp.salaryRatePerDay);
    }
}

void deleteEmployee() {
    printf("Deleting Employee...\n");
}

void printPayslip() {
    printf("Displaying Payslip...\n");
}

void writeEmployeeToFile(struct Employee emp) {
    FILE* file = fopen("employee_data.txt", "a");

    if (file != NULL) {
        fprintf(file, "%s %d %s %s %d %.2f\n", emp.name, emp.age, emp.address, emp.phoneNumber, emp.idNumber, emp.salaryRatePerDay);
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
    }
}

void readEmployeeFromFile(int id, char* lastName, struct Employee* emp) {
    FILE* file = fopen("employee_data.txt", "r");

    if (file != NULL) {
        while (fscanf(file, "%s %d %s %s %d %f", emp->name, &emp->age, emp->address, emp->phoneNumber, &emp->idNumber, &emp->salaryRatePerDay) != EOF) {
            if (emp->idNumber == id && strcmp(emp->name, lastName) == 0) {
                fclose(file);
                return;
            }
        }
        fclose(file);
    } else {
        printf("Error opening file for reading.\n");
    }

    emp->idNumber = -1;
}
