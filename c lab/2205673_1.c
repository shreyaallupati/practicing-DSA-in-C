//1: Initialize an array with some floating point numbers
// and swap the highest and lowest elements with each other using the pointer.

#include<stdio.h>

void swap( float *s, float *b)
{
    float temp;
    printf("before swap b=%f s=%f \n",*b,*s);
    temp= *s;
    *s = *b;
    *b = temp;
    printf("after swap b= %f, s=%f \n",*b,*s);
}

int main()
{
    float arr[7];
    arr[7]={1.1,2.3,2.4,5.6,5,8.7,5.9};
    float b;
    for(int i=0; i<7;i++)
    {
      if(arr[i]>arr[i+1])  
      b=arr[i];
    }
    float s;
    for(int i=0; i<7;i++)
    {
      if(arr[i]>arr[i+1])  
      s=arr[i+1];
    }
    void swap(b,s);

}