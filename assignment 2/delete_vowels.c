//assignment 16

#include<stdio.h>

void Delete(char *arr,int *size,int pos)
{	
	int i;
	for(i=pos;i<*size-1;i++){
		arr[i]=arr[i+1];	
	}
	(*size)--;
	
}

int main(){
	int n,i;
	char a[n];
	printf("enter size of char array in small letters ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%c",&a[i]);
	}
	for(i=0;i<n;i++){
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
			Delete(a,n,i);	
		}
	}
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
	return 0;
}

