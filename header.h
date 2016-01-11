#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define MASTER 0 // Master node has rank 0.

struct timeval tm1, tm2;

/* Function Declaration (Function List Implemented.) */
char *functionPalindrome (char *a,int count);
char *functionFactorial (char *a,int count);
char *functionReverseString (char *a,int count);
char *functionStringLength (char *a,int count);
char *functionArmstrong (char *a,int count);
char *functionPower (char *a,int count);
char *functionCompareString (char *a,int count){return "compareString, Something might went wrong.";}
char *functionFindMaximum (char *a,int count);
char *functionLinearSearch (char *a,int count);
char *functionBubbleSort (char *a,int count);
char *functionMergeSort (char *a,int count);
void mergeSort_Partition(float arr[],int lowValue,int highValue);
void mergeSort_MergeSort(float arr[],int lowValue,int midValue,int highValue);
char *functionMatrixMult (char *a,int count);
char *functionComputation ();
char *functionDFS (){return "DFS NOT IMPLEMENTED.";}
char *functionBFS (){return "BFS NOT IMPLEMENTED.";}


/* Function to start timer. */
void start()
{
	gettimeofday(&tm1, NULL);
}

/* Function to stop timer. */
void stop(){
	gettimeofday(&tm2, NULL);
	unsigned long long t = ((tm2.tv_sec - tm1.tv_sec) * 1000000)
	+ (tm2.tv_usec - tm1.tv_usec);
	printf("\nExecution Time : %llu microseconds\n",t);
}
