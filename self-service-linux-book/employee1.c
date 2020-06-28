#include "employee.h"
#include <string.h>
#include <stdlib.h>

int foo(struct employee_rec *pEmp)
{
	pEmp->manager_emp_no = 10;
	return 0;
}

int main(void)
{
	struct employee_rec *pEmployee;

	pEmployee =(struct employee_rec*)malloc(sizeof(struct employee_rec));
	
	/* Set the record up*/
	pEmployee->employee_no = 4416;
	pEmployee->is_ceo = 0;
	strcpy(pEmployee->first_name, "Ronald");
	strcpy(pEmployee->last_name, "Pina");
	pEmployee->manager_emp_no = 3278;
	pEmployee->department_no = 321;

	foo(pEmployee);

	return 0;
}

