#include <iostream>
using namespace std;

float count=0;

void F1(int n){
    for(int i=0;i<n;++count,i++){
        if(i%2==0){
            count+=2;
            cout<<i<<" ";
        }else count++;
    }
    cout<<"\n"<<count;
}

void F2(int n){
    for(int i=0;i<n;++count,i++){
        for(int j=i;j<n;++count,j++){
            count++;
            //cout<<i<<", "<<j<<endl;
        }
    }
    cout<<"\n"<<count;
}

void F3(int A,int B){
    for(int i=0;i<A;++count,i++){
        for(int j=0;j<B;++count,j++){
            count++;
            //cout<<i<<", "<<j<<endl;
        }
    }
    cout<<count<<endl;
}

void F4(int n){
    for(int i=0;i<n;++count,i++){
        int j=1;
        count+=2;
        while(j<n){
            count+=2;
            //cout<<j<<endl;
            j*=2;
        }
    }
    cout<<count<<endl;
}

void F5(int n){
    for(int i=0;i<n;++count,i++){
        if(i%2==0){
            count+=2;
            //cout<<i<<" ";
        }else count++;
    }
    for(int j=0;j<n;++count,j++){
        if(j%2!=0){
            count+=2;
            //cout<<j<<" ";
        }else count++;
    }
    cout<<count<<endl;
}

void F6(int n){
    int i=1;
    count+=2;
    while(i<n){
        count+=2;
        //cout<<i<<endl;
        i*=2;
    }
    cout<<count<<endl;
}

void F7(){
    int N=1000;
    count++;
    if(N%2==0){
        count+=2;
        //cout<<"par"<<endl;
    }else{
        count+=2;
        //cout<<"impar"<<endl;
    }
    cout<<count<<endl;
}

int main(){
    count=0;
    F1(1);
    F2(1);
    F3(1,1);
    F4(1);
    F5(1);
    F6(1);
    F7();
}