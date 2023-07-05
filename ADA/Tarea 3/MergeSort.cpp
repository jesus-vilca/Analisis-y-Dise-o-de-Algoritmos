#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void merge(int*, int, int, int);
void mergeSort(int*, int);
void printArray(int*, int);
int min(int x, int y) {return (x<y)? x:y; }

int main(){
	srand(time(NULL));
    int arr[1000];
    for(int i=0;i<1000;i++)
        arr[i]=rand()%50;
    printArray(arr,1000);
    mergeSort(arr,1000);
    printArray(arr,1000);
    return 0;
}

void mergeSort(int arr[], int n){
    int p,s;
    for (s=1; s<=n-1; s = 2*s){
        for (p=0; p<n-1; p += 2*s)	{
            int q = min(p + s - 1, n-1);
            int r = min(p + 2*s - 1, n-1);
            merge(arr, p, q, r);
        }
    }
}

void merge(int arr[], int p, int q, int r){
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[q + 1+ j];

	i = 0;
	j = 0;
	k = p;
	while (i < n1 && j < n2){
		if (L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}

void printArray(int arr[], int n){
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
