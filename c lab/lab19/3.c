#include<stdio.h>
#include<string.h>
struct details
{
    char name[50];
    int roll;
    char branch[100];
    char section[10];
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;
    int total;
    float avg;
    char grade;
}std1;
void printdetails(struct details std1);

int main()
{
    int x;
    struct details std1;
    printf("student name: \n");
    gets(std1.name);
    printf("roll no: \n");
    scanf("%d",&std1.roll);
    printf("branch: \n");
    scanf("%s",&std1.branch);
    printf("section:\n");
    scanf("%s",&std1.section);
    printf("enter marks of 5 subjects \n");
    scanf("%d%d%d%d%d",&std1.m1,&std1.m2,&std1.m3,&std1.m4,&std1.m5);

    std1.total=std1.m1+std1.m2+std1.m3+std1.m4+std1.m5;
    std1.avg=std1.total/5;
    x=std1.avg/10;
    switch (x)
    {
        case 1:
        case 2:
        case 3:
        std1.grade='F';
        break;
        case 4:
        std1.grade='D';
        break;
        case 5:
        std1.grade='C';
        break;
        case 6:
        std1.grade='B';
        break;
        case 7:
        std1.grade='A';
        break;
        case 8:
        std1.grade='E';
        break;
        case 9:
        case 10:
        std1.grade='O';
        break;
        }
    printdetails(std1);
    return 0;
}
void printdetails(struct details std1)
{
    printf("name: %s \n",std1.name);
    printf("roll number: %d \n",std1.roll);
    printf("branch: %s \n",std1.branch);
    printf("section: %s \n",std1.section);
    printf("marks of 5 subjects: %d %d %d %d %d \n",std1.m1,std1.m2,std1.m3,std1.m4,std1.m5);
    printf("total: %d \n",std1.total);
    printf("avg: %f \n",std1.avg);
    printf("grade: %c \n",std1.grade);
}