#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX 20

void bubble_asc(int arr[], int n)
{
int i,j,temp;
for (i=0 ; i<n ; i++)
	{
	for (j=0 ; j<n-i-1 ; j++)
		{
		if (arr[j]>arr[j+1])
			{
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
			}
		}
	}
}

void bubble_desc(int arr[], int n)
{
int i,j,temp;
for (i=0 ; i<n ; i++)
	{
	for (j=0 ; j<n-i-1 ; j++)
		{
		if (arr[j]<arr[j+1])
			{
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
			}
		}
	}
}

void print (int arr[], int n){
int i;
	for (i=0 ; i<n ; i++)
	{
		printf("\t %d", arr[i]);
	}
	printf("\n \n");
}

int main(){
int i , n, arr[MAX],f, pid;
printf("\n How many Numbers do you want in the array");
scanf("%d",&n);
printf("\n Enter those numbers");
for (i=0 ; i<n ; i++)
	{
	scanf("%d",&arr[i]);
	}
 
pid = fork();

if (pid==0)
	{
	printf("\n\t\t*************ORPHAN STATE*************\n");
	sleep(5);
	printf("\n\t CHILD PROCESS PID : %d ", getpid());
	printf("\n\t Get Parent Process Id : %d", getppid());
	system("ps -el | grep init");
	
	printf("\n\t Array In ascending order :");
	bubble_asc(arr, n);
	print(arr,n);
	}
 
else if (pid > 0)
	{
	printf("\n\t\t*************Zombie State**************\n");
	system("ps -el | grep Z");
	f=wait(0);
	printf("\n\tTERMINATED CHILD PID : %d",f);
        printf("\n\tPARENT PID (MAIN) : %d",getpid());
        printf("\n\tPARENTS PARENT PPID (BASH) : %d ",getppid());
    	printf("\n\nARRAY IN DESCENDING ORDER : ");
        bubble_desc(arr,n);
        print(arr,n);
	}
else 
	printf("\n Error In Fork");
	
	return 0;
}

