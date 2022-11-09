#include <stdio.h>
#include <stdlib.h>

int main() {
	int *arr1;
	int *arr2;
	int *arr3;
	int len1; //length of first array
	int len2; //length of second array
	int i, j, k; //i for getting first and second array, j and k for creating third array
	
	printf("Enter length of first array: ");
	scanf("%d", &len1);
	arr1 = malloc(len1 * sizeof(int));
	
	printf("Enter numbers: "); //getting first array
	for(i=0; i<len1; ++i) {
		scanf("%d", arr1+i);
	}	
	
	printf("Enter length of second array: ");
	scanf("%d", &len2);
	arr2 = malloc(len2 * sizeof(int));
	
	printf("Enter numbers: "); //getting second array
	for(i=0; i<len2; ++i) {
		scanf("%d", arr2+i);
	}
	
	arr3 = malloc((len1+len2) * sizeof(int));
	
	j=0;
	k=0;
	for(i=0; i<len1+len2; ++i) {	
		if((arr1[j] < arr2[k] && j != len1) || (k==len2 && j!=len1)) { 
			arr3[i]= arr1[j];
			++j;
		}	
		else if(k!=len2) {
			arr3[i] = arr2[k];
			++k;
		}
	}
		
	for(i=0; i<len2+len1; ++i) {
		printf("%d ", arr3[i]);
	}
				
	free(arr1);
	free(arr2);
	free(arr3);	
}



