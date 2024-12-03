#include<stdio.h>

int main(){
	
	int m,n;
	int i,j,k;
	
	//sparse matrix 1
	int a[m][3];
	printf("enter no of non zero elements in A: ");
	scanf("%d",&m);
	printf("enter sparse matrix 1: ");
	for(i=0;i<m+1;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	//sparse matrix 2
	int b[n][3];
	printf("enter no of non zero elements in B: ");
	scanf("%d",&n);
	printf("enter sparse matrix 2: ");
	for(i=0;i<n+1;i++){
		for(j=0;j<3;j++){
			scanf("%d",&b[i][j]);
		}
	}
	

	//addition
	int count1=m+n;
	int sum[count1][3];
	int count=0;
	if(a[0][0]==b[0][0] && a[0][1]==b[0][1]){
		printf("addition is possible \n");
		
		sum[0][0] = a[0][0];
		sum[0][1] = a[0][1];
		
	/*	i=1;j=1;k=1;
		while(k!=m+n){
			if(a[i][0]==b[j][0]){
				if(a[i][1]==b[j][1]){
					sum[k][0] = a[i][0];
					sum[k][1] = a[i][1];
					sum[k][2] = a[i][2] + b[j][2];
					i++;j++;k++;
					count++;
				}
				else if(a[i][1]>b[j][1]){
					sum[k][0] = b[j][0];
					sum[k][1] = b[j][1];
					sum[k][2] = b[j][2];
					j++;k++;
					count++;
				}
				else{
					sum[k][0] = a[i][0];
					sum[k][1] = a[i][1];
					sum[k][2] = a[i][2];
					i++;k++;
					count++;
				}
			}
		} */
	}
	else printf("addition not possible \n");
		
	return 0;	
}
