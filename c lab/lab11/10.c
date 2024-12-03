#include<stdio.h>
int main(){
   int i, num, count;
   
   printf("The prime numbers in between the range 1 to 100");
   for(num = 1;num<=100;num++){
      count = 0;
      for(i=2;i<=num/2;i++){
         if(num%i==0){
            count++;
         break;
      }
   }
   if(count==0 && num!= 1)
      printf("%d ",num);
   }
}