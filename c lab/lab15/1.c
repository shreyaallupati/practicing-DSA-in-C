#include<stdio.h>
int isprime (int*a)
{
	int c=0; 
	for (int i=1;i<=*a;i++) 
	if (*a%i==0)
	c++;
    if (c==2)
    return 1;
}
int isprime (int *a);
int main()
{
	int a,b,i;
	printf("Enter 2 Numbers.\n");
	int arr[1000], k=0;
	scanf("%d %d", &a, &b);
	printf("\n\n");
	  for (i=a;i<=b; i++)
	  if (isprime(&i)==1)
	  {
	    arr[k]=i;
	    k++;
	  }
	  printf("Prime numbers between %d and %d are : \n",a,b);
	for (i=0;i<k; i++)
	 printf("%d \n", arr[i]);
return 0;
}