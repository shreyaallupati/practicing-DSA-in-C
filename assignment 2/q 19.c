//assignment 19

#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int leftmin[n],rightmax[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	leftmin[0]=arr[0];
	int min=0;
	for(i=0;i<n;i++){
		int j;
		for(j=0;j<n;j++){
			if(arr[j]<arr[j+1]){
				min = arr[j];
			}
		}
		leftmin[i]=min;
	}
	rightmax[n-1]=arr[n-1];
	int max;
	for(i=n-2;i>=0;i--){
		int j;
		for(j=0;j<n;j++){
			if(arr[j]>arr[j+1]){
				max = arr[j];
			}
		}
		rightmax[i]=max;
	}
	
	i=0;
	int j=0;
	int maxdiff=-1;
	while(i<n&&j<n){
		if(leftmin[i]<rightmax[j]){
			maxdiff=maxdiff>j-i?maxdiff:j-i;
			j++;
		}
		else i++;
	}
	printf("\n\n%d",maxdiff);
	return 0;
}

