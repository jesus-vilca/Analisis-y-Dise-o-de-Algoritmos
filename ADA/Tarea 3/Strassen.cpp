#include <iostream>
#include <ctime>
using namespace std;

int** matriz(int fil,int col){
    int **A = new int* [fil];
    for (int i = 0; i < fil; i++) {
        A[i] = new int[col];
    }
 
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            A[i][j] = rand()%10 - 5;
            cout<< A[i][j] << " ";
        }
        cout<<endl;
    }
    return A;
}

void del_mat(int** A,int a){
    for (int i = 0; i < a; i++) {
        delete[] A[i];
    }
    delete[] A;
}

int** mult(int** A,int** B, int n){
    int** C = new int* [n];
    for (int i = 0; i < n; i++) {
        C[i] = new int[n];
    }
    if(n==1){
        C[0][0] = A[0][0]*B[0][0];
        return C;
    }else{
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] = 0;
                for (int k = 0; k < n; k++)
                    C[i][j] += A[i][k]*B[k][j];
            }
        }
        return C;
    }
}

int** sum(int** A,int** B, int n){
    int** C = new int* [n];
    for (int i = 0; i < n; i++) {
        C[i] = new int[n];
    }
    if(n==1){
        C[0][0] = A[0][0]+B[0][0];
        return C;
    }else{
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                C[i][j] = A[i][j]+B[i][j];
            }
        }
        return C;
    }
}

int** rest(int** A,int** B, int n){
    int** C = new int* [n];
    for (int i = 0; i < n; i++) {
        C[i] = new int[n];
    }
    if(n==1){
        C[0][0] = A[0][0]-B[0][0];
        return C;
    }else{
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                C[i][j] = A[i][j]-B[i][j];
            }
        }
        return C;
    }
}

int** sum_esp(int** A,int** B, int a1, int a2, int b1, int b2){
    int fil,col;
    if(a1>b1) fil = a1;
    else fil=b1;
    if(a2>b2) col = a2;
    else col=b2;
    int** C = new int* [fil];
    for (int i = 0; i < fil; i++) {
        C[i] = new int[col];
    }
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < a2; j++){
            C[i][j] = A[i][j];
        }
    }

    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            C[i][j] += B[i][j];
        }
    }
    return C;
}

int** rest_esp(int** A,int** B, int a1, int a2, int b1, int b2){
    int fil,col;
    if(a1>b1) fil = a1;
    else fil=b1;
    if(a2>b2) col = a2;
    else col=b2;
    int** C = new int* [fil];
    for (int i = 0; i < fil; i++) {
        C[i] = new int[col];
    }
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < a2; j++){
            C[i][j] = A[i][j];
        }
    }

    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            C[i][j] -= B[i][j];
        }
    }
    return C;
}

int** resize(int** A, int a1, int a2, int fil, int col){
    int** C = new int* [fil];
    for (int i = 0; i < fil; i++) {
        C[i] = new int[col];
    }
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < a1; i++) {
        for (int j = 0; j < a2; j++) {
            C[i][j] = A[i][j];
        }
    }
    return C;
}

int** strassen(int** A, int** B,int n){
    int** C = new int* [n];
    for (int i = 0; i < n; i++) {
        C[i] = new int[n];
    }

    if(n==1){
        C[0][0] = A[0][0]*B[0][0];
        return C;
    }

    //A
    int** A_11 = new int* [n/2];
    for (int i = 0; i < n/2; i++)
        A_11[i] = new int[n/2];
    for (int i = 0; i < n/2; i++)
        for (int j = 0; j < n/2; j++)
            A_11[i][j] = A[i][j];

    int** A_12 = new int* [n/2];
    for (int i = 0; i < n/2; i++)
        A_12[i] = new int[n/2];
    for (int i = 0; i < n/2; i++)
        for (int j = n/2; j < n; j++)
            A_12[i][j-n/2] = A[i][j];
    
    int** A_21 = new int* [n/2];
    for (int i = 0; i < n/2; i++)
        A_21[i] = new int[n/2];
    for (int i = n/2; i < n; i++)
        for (int j = 0; j < n/2; j++)
            A_21[i-n/2][j] = A[i][j];
    
    int** A_22 = new int* [n/2];
    for (int i = 0; i < n/2; i++)
        A_22[i] = new int[n/2];
    for (int i = n/2; i < n; i++)
        for (int j = n/2; j < n; j++)
            A_22[i-n/2][j-n/2] = A[i][j];

    //B
    int** B_11 = new int* [n/2];
    for (int i = 0; i < n/2; i++)
        B_11[i] = new int[n/2];
    for (int i = 0; i < n/2; i++)
        for (int j = 0; j < n/2; j++)
            B_11[i][j] = B[i][j];

    int** B_12 = new int* [n/2];
    for (int i = 0; i < n/2; i++)
        B_12[i] = new int[n/2];
    for (int i = 0; i < n/2; i++)
        for (int j = n/2; j < n; j++)
            B_12[i][j-n/2] = B[i][j];
    
    int** B_21 = new int* [n/2];
    for (int i = 0; i < n/2; i++)
        B_21[i] = new int[n/2];
    for (int i = n/2; i < n; i++)
        for (int j = 0; j < n/2; j++)
            B_21[i-n/2][j] = B[i][j];
    
    int** B_22 = new int* [n/2];
    for (int i = 0; i < n/2; i++)
        B_22[i] = new int[n/2];
    for (int i = n/2; i < n; i++)
        for (int j = n/2; j < n; j++)
            B_22[i-n/2][j-n/2] = B[i][j];

    //P
    int** P_1 = new int* [n/2];
    for (int i = 0; i < n/2; i++)
        P_1[i] = new int[n/2];
    P_1 = strassen(sum(A_11,A_22,n/2),sum(B_11,B_22,n/2),n/2);

    int** P_2 = new int* [n/2];
    for (int i = 0; i < n/2; i++)
        P_2[i] = new int[n/2];
    P_2 = strassen(sum(A_21,A_22,n/2),B_11,n/2);

    int** P_3 = new int* [n/2];
    for (int i = 0; i < n/2; i++)
        P_3[i] = new int[n/2];
    P_3 = strassen(A_11,rest(B_12,B_22,n/2),n/2);

    int** P_4 = new int* [n/2];
    for (int i = 0; i < n/2; i++)
        P_4[i] = new int[n/2];
    P_4 = strassen(A_22,rest(B_21,B_11,n/2),n/2);

    int** P_5 = new int* [n/2];
    for (int i = 0; i < n/2; i++)
        P_5[i] = new int[n/2];
    P_5 = strassen(sum(A_11,A_12,n/2),B_22,n/2);

    int** P_6 = new int* [n/2];
    for (int i = 0; i < n/2; i++) {
        P_6[i] = new int[n/2];
    }
    P_6 = strassen(rest(A_21,A_11,n/2),sum(B_11,B_12,n/2),n/2);

    int** P_7 = new int* [n/2];
    for (int i = 0; i < n/2; i++) {
        P_7[i] = new int[n/2];
    }
    P_7 = strassen(rest(A_12,A_22,n/2),sum(B_21,B_22,n/2),n/2);

    //C_11
    for (int i = 0; i < n/2; i++)
        for (int j = 0; j < n/2; j++)
            C[i][j] = P_1[i][j]+P_4[i][j]-P_5[i][j]+P_7[i][j];

    //C_12
    for (int i = 0; i < n/2; i++)
        for (int j = n/2; j < n; j++)
            C[i][j] = P_3[i][j-n/2]+P_5[i][j-n/2];

    //C_21
    for (int i = n/2; i < n; i++)
        for (int j = 0; j < n/2; j++)
            C[i][j] = P_2[i-n/2][j]+P_4[i-n/2][j];

    //C_22
    for (int i = n/2; i < n; i++)
        for (int j = n/2; j < n; j++)
            C[i][j] = P_1[i-n/2][j-n/2]+P_3[i-n/2][j-n/2]-P_2[i-n/2][j-n/2]+P_6[i-n/2][j-n/2];

    //Deletes
    del_mat(A_11,n/2);
    del_mat(A_21,n/2);
    del_mat(A_12,n/2);
    del_mat(A_22,n/2);
    del_mat(B_11,n/2);
    del_mat(B_21,n/2);
    del_mat(B_12,n/2);
    del_mat(B_22,n/2);
    del_mat(P_1,n/2);
    del_mat(P_2,n/2);
    del_mat(P_3,n/2);
    del_mat(P_4,n/2);
    del_mat(P_5,n/2);
    del_mat(P_6,n/2);
    del_mat(P_7,n/2);

    return C;
}

int** strassen_esp(int** A, int** B,int n){ 
    int** C = new int* [n];
    for (int i = 0; i < n; i++)
        C[i] = new int[n];

    if(n==1){
        C[0][0] = A[0][0]*B[0][0];
        return C;
    }

    //dimensions
    int a = n/2;
    int b = n-a;

    //A
    int** A_11 = new int* [a];
    for (int i = 0; i < a; i++)
        A_11[i] = new int[a];
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            A_11[i][j] = A[i][j];

    int** A_12 = new int* [a];
    for (int i = 0; i < a; i++)
        A_12[i] = new int[b];
    for (int i = 0; i < a; i++)
        for (int j = a; j < n; j++)
            A_12[i][j-a] = A[i][j];
    
    int** A_21 = new int* [b];
    for (int i = 0; i < b; i++)
        A_21[i] = new int[a];
    for (int i = a; i < n; i++)
        for (int j = 0; j < a; j++)
            A_21[i-a][j] = A[i][j];

    int** A_22 = new int* [b];
    for (int i = 0; i < b; i++)
        A_22[i] = new int[b];
    for (int i = a; i < n; i++)
        for (int j = a; j < n; j++)
            A_22[i-a][j-a] = A[i][j];

    //B
    int** B_11 = new int* [a];
    for (int i = 0; i < a; i++)
        B_11[i] = new int[a];
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            B_11[i][j] = B[i][j];

    int** B_12 = new int* [a];
    for (int i = 0; i < a; i++)
        B_12[i] = new int[b];
    for (int i = 0; i < a; i++)
        for (int j = a; j < n; j++)
            B_12[i][j-a] = B[i][j];
    
    int** B_21 = new int* [b];
    for (int i = 0; i < b; i++)
        B_21[i] = new int[a];
    for (int i = a; i < n; i++)
        for (int j = 0; j < a; j++)
            B_21[i-a][j] = B[i][j];
    
    int** B_22 = new int* [b];
    for (int i = 0; i < b; i++)
        B_22[i] = new int[b];
    for (int i = a; i < n; i++)
        for (int j = a; j < n; j++)
            B_22[i-a][j-a] = B[i][j];
    
    //P
    int** P_1 = new int* [b];
    for (int i = 0; i < b; i++)
        P_1[i] = new int[b];
    P_1 = strassen_esp(sum_esp(A_11,A_22,a,a,b,b),sum_esp(B_11,B_22,a,a,b,b),b);
    
    int** P_2 = new int* [b];
    for (int i = 0; i < b; i++)
        P_2[i] = new int[b];
    P_2 = strassen_esp(sum_esp(A_21,A_22,b,a,b,b),resize(B_11,a,a,b,b),b);
    
    
    int** P_3 = new int* [b];
    for (int i = 0; i < b; i++)
        P_3[i] = new int[b];
    P_3 = strassen_esp(resize(A_11,a,a,b,b),rest_esp(B_12,B_22,a,b,b,b),b);

    int** P_4 = new int* [b];
    for (int i = 0; i < b; i++)
        P_4[i] = new int[b];
    P_4 = strassen_esp(A_22,rest(resize(B_21,b,a,b,b),resize(B_11,a,a,b,b),b),b);
    
    int** P_5 = new int* [b];
    for (int i = 0; i < b; i++)
        P_5[i] = new int[b];
    P_5 = strassen_esp(sum(resize(A_11,a,a,b,b),resize(A_12,a,b,b,b),b),B_22,b);

    int** P_6 = new int* [b];
    for (int i = 0; i < b; i++)
        P_6[i] = new int[b];
    P_6 = strassen_esp(rest(resize(A_21,b,a,b,b),resize(A_11,a,a,b,b),b),sum(resize(B_11,a,a,b,b),resize(B_12,a,b,b,b),b),b);
    
    int** P_7 = new int* [b];
    for (int i = 0; i < b; i++)
        P_7[i] = new int[b];
    P_7 = strassen_esp(rest_esp(A_12,A_22,a,b,b,b),sum_esp(B_21,B_22,b,a,b,b),b);
    
    //C_11
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            C[i][j] = P_1[i][j]+P_4[i][j]-P_5[i][j]+P_7[i][j];


    //C_12
    for (int i = 0; i < a; i++)
        for (int j = a; j < n; j++)
            C[i][j] = P_3[i][j-a]+P_5[i][j-a];

    //C_21
    for (int i = a; i < n; i++)
        for (int j = 0; j < a; j++)
            C[i][j] = P_2[i-a][j]+P_4[i-a][j];

    //C_22
    for (int i = a; i < n; i++)
        for (int j = a; j < n; j++)
            C[i][j] = P_1[i-a][j-a]+P_3[i-a][j-a]-P_2[i-a][j-a]+P_6[i-a][j-a];
    
    //Deletes
    del_mat(A_11,a);
    del_mat(resize(A_21,b,a,b,b),b);
    del_mat(resize(A_12,a,b,b,b),b);
    del_mat(A_22,b);
    del_mat(B_11,a);
    del_mat(resize(B_21,b,a,b,b),b);
    del_mat(resize(B_12,a,b,b,b),b);
    del_mat(B_22,b);
    del_mat(P_1,b);
    del_mat(P_2,b);
    del_mat(P_3,b);
    del_mat(P_4,b);
    del_mat(P_5,b);
    del_mat(P_6,b);
    del_mat(P_7,b);
    return C;
}

int main(){
    srand((unsigned)time(NULL));
   
    int n=7;
    int** A = matriz(n,n);
    cout<<endl;
    int** B = matriz(n,n);
    cout<<endl;
    int** C = mult(A,B,n);
    int** D = strassen_esp(A,B,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<D[i][j]<<" ";
        cout<<endl;
    }

    del_mat(A,n);
    del_mat(B,n);
    del_mat(C,n);
    del_mat(D,n);
    return 0;
}