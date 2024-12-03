#include<stdio.h>

// 3.3 1D polynomial addition

int* add(int a[], int b[],int x){
	int i;
	int c[x];
	for(i=0;i<x;i++){
		c[i]=a[i]+b[i];
	}
	return c;
}


int  main()
{
	int m,n;
	int a[m],b[n];
	printf("Enter maximum degree: ");
	scanf("%d",&m);
	printf("Enter polynomial from lowest degree to highest degree: ");
	int i;
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter maximum degree: ");
	scanf("%d",&n);
	printf("Enter polynomial from lowest degree to highest degree: ");
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	if(m>n){
		int x=m;
	}
	else x=n;
	add(a,b,x);
	return 0;
}
