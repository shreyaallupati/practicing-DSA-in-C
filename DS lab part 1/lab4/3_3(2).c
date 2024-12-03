#include<stdio.h>

// 3.3 1D polynomial addition

int main(){

	int m,n;
	int i;
	
	printf("Enter max degree of first polynomial\n");
	scanf("%d",&m);
	
	int a[m+1];
	for (i = 0; i<m+1 ; i++){
	    printf("coefficient of x^%d\n",i);
	    scanf("%d",&a[i]);
	}
	   
	printf("Enter max degree of second polynomial\n");
	scanf("%d",&n);
	
	int b[n+1];
	for (i = 0; i <n+1; i++){
	    printf("coefficient of x^%d\n",i);
	    scanf("%d",&b[i]);
	}
	    
    int n3= m>n?m:n;
    int c[n3+1];
    
    i=0;
    int j=0,k=0;

    while (i<(m>n?m:n)+1 && j<(m>n?n:m)+1)
    {
        c[k]=a[i]+b[j];
        i++;j++;k++;

    }
    while(i<m+1){
        c[k]=a[i];
        k++;i++;

    }
    while(j<n+1){
        c[k]=b[j];
        k++;j++;
	}

    
    printf("sum of above polynomials is \n");
    for (i = n3; i>=0; i--)
    {
		if(c[i]!=0){
        printf( "%dx^%d",c[i],i);
        	if(i>0){
            	printf(" + ");
        	}
        }
    }
    
    return 0;
}
