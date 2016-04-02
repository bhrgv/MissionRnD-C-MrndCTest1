/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int* findArthimetic(int* arr, int str, int len)
{
	int i;
	int* result = (int*)malloc(2 * sizeof(int));
	for (i = str; i < len-2; i++)
	{
		if (arr[i + 1] - arr[i] == arr[i + 2] - arr[i + 1])
			break;
	}
	int start = i;
	if (i == len)
	{
		result[0] = 0;
		result[1] = 0;
		return result;
	}
	int d = arr[i + 1] - arr[i];
	for (i = i + 1; i < len; i++)
	{
		if (arr[i] - arr[i - 1] != d)
			break;
	}
	if (i - start < 3)
		return findArthimetic(arr, i, len);
	result[0] = start;
	result[1] = i - 1;
	return result;
}
int* findGeometric(int* arr, int str,int len)
{
	int i;
	int* result = (int*)malloc(2 * sizeof(int));
	for (i = str; i < len - 2; i++)
	{
		float d1 = (arr[i + 1] / (1.0*arr[i]));
		float d2 = (arr[i + 2] / (1.0*arr[i + 1]));
		if (d1 == d2)
			break;
	}
	int start = i;
	if (i == len)
	{
		result[0] = 0;
		result[1] = 0;
		return result;
	}
	int d = arr[i + 1] / arr[i];
	for (i = i + 1; i < len; i++)
	{
		if (arr[i] / arr[i - 1] != d)
			break;
	}
	result[0] = start;
	result[1] = i - 1;
	return result;
}
int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr==NULL)
		return NULL;
	int* res1 = findArthimetic(arr, 0, len);
	int* res2 = findArthimetic(arr, res1[1], len);
	int* res3 = findGeometric(arr,0, len);
	int* res = (int*)malloc(6 * sizeof(int));
	res[0] = res1[0];
	res[1] = res1[1];
	res[2] = res2[0];
	res[3] = res2[1];
	res[4] = res3[0];
	res[5] = res3[1];
	return res;
}