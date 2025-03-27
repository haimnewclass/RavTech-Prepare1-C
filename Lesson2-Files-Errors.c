#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    float salary;
} Employee;

int main1() {
    FILE* fp;
    Employee emp;
    errno_t err;

    err = fopen_s(&fp, "employees.txt", "r");
    if (err != 0) {
        printf("Failed to open file\n");
        return 1;
    }

    while (fscanf_s(fp, "%d %19s %f", &emp.id, emp.name, (unsigned)_countof(emp.name), &emp.salary) == 3) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", emp.id, emp.name, emp.salary);
    }

    fclose(fp);
    return 0;
}