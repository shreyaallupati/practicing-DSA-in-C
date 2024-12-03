#include<stdio.h>
int main(){
 
for(int i=100;i<=1000;i++)
{
 int sum=0,m=i;
 do
 {
 sum=sum+((m%10)*(m%10)*(m%10));
 m=m/10;
 }while(m!=0);
 
 if(sum==i)
 {
 printf("%d \n",i);
 }
 }
return 0;
}
