//assignment 1


#include<stdio.h>

int main()
{
	int m,n;
	int a[m],b[n];
	
	printf("enter number of elements of array 1: ");
	scanf("%d", &m);
    printf("enter the array elements of first array: \n");
	for(int i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	printf("enter number of elements of array 2: ");
	scanf("%d", &n);
    printf("enter the array elements of 2nd array: \n");
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	int c[m+n];
	
	int i = 0;
    int j = 0;
    int k = 0;
    while (m+n)
    {
        if ((a[i] < b[j]) && i<m && j<n)
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else if( (a[i]>b[j]) && i<m && j<n )
        {
            c[k] = b[j];
            j++;
            k++;
        }

        else
		{
			if(i<m)
			{
				c[k]=a[i];
				k++;i++;
			}
			else
			{
				c[k]=b[j];
				k++;j++;
			}
		}
    }
	
	printf("the new merged and sorted array is: ");
	for(int i=0;i<(m+n);i++){
		printf("%d  ",c[i]);
	}
	
	return 0;
	
}
