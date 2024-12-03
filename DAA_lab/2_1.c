/*
2.1 Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain
some duplicate values and store them into an array. Perform the following operations on the
array.

a) Find out the total number of duplicate elements.
b) Find out the most repeating element in the array.

Input:
Enter how many numbers you want to read from file: 15
Output:
The content of the array: 10 40 35 47 68 22 40 10 98 10 50 35 68 40 10
Total number of duplicate values = 4
The most repeating element in the array = 10
*/

#include<stdio.h>
#include<stdlib.h>

int find_most_repeating(int arr[], int n);
int count_duplicates(int arr[], int n);

int main()
{	

	int n;
	printf("enter size of array");
	scanf("%d",&n);
	
	
	FILE *input_file, *output_file;
	
	input_file = fopen("input1","w");
	
	if(input_file==NULL){
		printf("file not opened");
		exit(0);
	}
	else{
		printf("opened");
	}
	
	int i;
	int arr[n];
	for(i=0;i<n;i++){
		arr[i] = 0 + rand()%(20-0+1);
	}
	
	for(i=0;i<n;i++){
		fprintf(input_file," %d", arr[i]);
	}
	
	fclose(input_file);
	output_file= fopen("output1","w");
	
	if(output_file==NULL){
		printf("file not opened");
		exit(0);
	}
	else{
		printf("opened");
	}
	
	int duplicates = count_duplicates(arr,n);
	fprintf(output_file, "no of duplicates = %d \n", duplicates);
	int most_repeating = find_most_repeating(arr, n);
	fprintf(output_file, "most repeating = %d \n", most_repeating);
	
	return 0;
}


int count_duplicates(int arr[], int n) {
    int duplicates = 0;
    
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                duplicates++;
                break;
            }
        }
    }
    
    return duplicates;
}


int find_most_repeating(int arr[], int n) {
    int max_count = 0;
    int most_repeating = 0;
    
    int i,j;
    for (i = 0; i < n; i++) {
        int count = 0;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            most_repeating = arr[i];
        }
    }
    
    return most_repeating;
}
