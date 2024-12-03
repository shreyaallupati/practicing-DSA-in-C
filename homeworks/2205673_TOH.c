#include<stdio.h>

//tower of hanoi

void towerofhanoi(int n, char from_rod, char to_rod, char aux_rod){
	if(n==1){
		printf("\n disk %d moved from %c to %c",n,from_rod,to_rod);
		return;
	}
		towerofhanoi(n-1, from_rod, aux_rod, to_rod);
		printf("\n disk %d moved from %c to %c",n,from_rod,to_rod);
		towerofhanoi(n-1, aux_rod, to_rod, from_rod);
}

int main(){
	int n;
	printf("Enter number of disks \n");
	scanf("%d",&n);
	towerofhanoi(n, 'A', 'B', 'C');
	return 0;
}
