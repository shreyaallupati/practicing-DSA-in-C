#include<stdio.h>

//Write a program to create a structure to store the information of n number of Employees. 
//Employee’s information includes data members: Emp-id, Name, Designation, basic_salary, hra%, 
//da%. Display the information of employees with gross salary. Use array of structure.


struct employee{
	int emp_id;
	char name[50];
	char design[50];
	int basic_salary;
	int hra;
	int da;
};

int main(){
	int n;
	printf("\n enter no.of employees: ");
	scanf("%d",&n);
	struct employee emp[n];
	
	for(int i=1;i<=n;i++){
		printf("Enter employee %d information: \n",i);
		scanf("%s",&emp[i].name);
		scanf("%s",&emp[i].design);
		scanf("%d",&emp[i].basic_salary);
		scanf("%d",&emp[i].hra);
		scanf("%d",&emp[i].da);
	}
	
		
	printf("Employee information \n");
	for (int  i = 1; i <= n; i++)
    {

      printf("Employee information\n");
      printf("Name: %s\n",emp[i].name);
      printf("Designation: %s\n",emp[i].design);
      printf("Basic Salary: %d\n",emp[i].basic_salary);

      int hra= (emp[i].basic_salary*emp[i].hra)/100;
      printf("Hra: %d \n",hra);
      int da=(emp[i].basic_salary*emp[i].da)/100;
      printf("Da: %d \n",da);

      printf("Gross Salary: %d \n",emp[i].basic_salary+hra+da);
    }
	return 0;
}
