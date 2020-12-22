#include <bits/stdc++.h>
using namespace std ;

#define int long long

double expo(double a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	double x = expo(a , n / 2) ;
	x *= x ;
	if(n & 1) x *= a ;
	return x ;
}

double nthTerm(int input1 , int input2 , int input3){
	double r = input2 / input1 ;
	double a = input1 / r ;
	return a * expo(r , input3 - 1) ;
}

int32_t main(){
	int input1 , input2 , input3 ;
	cin >> input1 >> input2 >> input3 ;
	cout << nthTerm(input1 , input2 , input3) ;
	return 0 ;
}

