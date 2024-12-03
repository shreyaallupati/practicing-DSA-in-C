//input a two digit number and display both digit in word


#include<stdio.h>
int main()
{
    int a,n;
    printf("enter a number n: ");
    scanf("%d",&n);
    int fd=n/10;
	int sd=n%10;
	int nn=(sd*10)+fd;
	for(int i=nn;i!=0;i/=10)
	{
    a=i%10;
    switch (a)
    {
        case 0: printf("zero "); break;
        case 1: printf("one ");break;
        case 2: printf("two ");break;
        case 3: printf("three ");break;
        case 4: printf("four ");break;
        case 5: printf("five ");break;
        case 6: printf("six ");break;
        case 7: printf("seven ");break;
        case 8: printf("eight ");break;
        case 9: printf("nine ");break;
        
    }
    }
return 0;
}

