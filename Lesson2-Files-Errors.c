#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    float salary;
} Employee;

int main() {
    FILE* fp;
    Employee emp;

    fp = fopen("employees.txt", "r");

    while (!feof(fp)) {
        fscanf(fp, "%d %s %f", &emp.id, emp.name, &emp.salary);
        printf("ID: %d | Name: %s | Salary: %.2f\n", emp.id, emp.name, emp.salary);
    }

    fclose(fp);
    return 0;
}
