#include <iostream>
#include <ctime>
using namespace std; 

unsigned t0, t1;

bool verificarSort(int A[],int n){
	for(int i=0;i<n-1;i++)
		if(A[i]>A[i+1])return false; 
	return true;
}

int partition(int A[],int p,int r) { 
	int pivot=A[r];
	int i=p-1;
	for (int j=p;j<=r-1;j++) { 
		if (A[j]<pivot) { 
			i+=1; 
			swap<int>(A[i],A[j]); 
		} 
	} 
	swap<int>(A[i+1],A[r]); 
	return i+1; 
} 

void quicksort(int A[],int p,int r){ 
	if (p<r){ 
		int q=partition(A,p,r); 
		quicksort(A,p,q-1); 
		quicksort(A,q+1,r); 
	} 
}

void new_quicksort(int A[],int p,int r){
	int n=p+r+1;
	if(verificarSort(A,n)){
		cout<<"Ya esta ordenado"<<endl;
	}else quicksort(A,0,n-1);
}

void imprimir(int A[],int n) {
	for (int i=0;i<n;i++) 
		cout<<A[i]<<", "; 
	cout<<endl; 
} 

int main(){
    srand(time(NULL));
    int n=10;
    int A[n];
    for(int i=0;i<n;i++)
        A[i]=1+rand()%99;

	imprimir(A,n);
    new_quicksort(A,0,n-1);
	imprimir(A,n);
    return 0;
} 