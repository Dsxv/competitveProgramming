#include<iostream>
#include<cmath>
using namespace std;

int minCount(int n){
    if(n<0){
        return 0;
    }

    if(n<3 && n>=0){
        return n;
    }
    int ans=(int)(pow(n,0.5));
    return 1+minCount(n-(ans*ans));

}

int main(){
    int n;
    cin>>n;
    cout<<minCount(n)<<endl;
}

