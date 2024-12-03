#include<stdio.h>
int removerepeated(int size,int a[]);
void sort(int size,int a[]);
int main(){
    int i,j,k;
   int uni[10];
   int a[5]={3,4,2,7,8};
   int b[5]={4,9,3,1,7};
  
   //union start
   for(i=0;i<5;i++){
      uni[j]=a[i];
      j++;
   }
   for(i=0;i<5;i++){
      uni[j]=b[i];
      j++;
   }
   //Sorting
   sort(10,uni);
   //Remove repeated elements
   int size;
   size=removerepeated(10,uni);
   printf("Array after Union ");
   for(i=0;i<size;i++){
      printf("%d",uni[i]);
   }
   //Sorting
}
int removerepeated(int size,int a[]){
   int i,j,k;
   for(i=0;i<size;i++){
      for(j=i+1;j<size;){
         if(a[i]==a[j]){
            for(k=j;k<size;k++){
               a[k]=a[k+1];
            }
            size--;
         }else{
            j++;
         }
      }
   }
   return(size);
}
void sort(int size,int a[]){
   int i,j,temp;
   for(i=0;i<size;i++){
      for(j=i+1;j<size;j++){
         if(a[i]>a[j]){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }
   }
}
