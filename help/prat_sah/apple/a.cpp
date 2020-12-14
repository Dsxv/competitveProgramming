#include <bits/stdc++.h>
using namespace std ;

#define int long long

int nthTerm(int input1 , int input2 , int input3){
	return input1 + (input2 - input1) * (input3 - 2) ;
}

int32_t main(){
	int a , b , c ;
	cin >> a >> b >> c ;
	cout << nthTerm(a,b,c) ;
	return 0 ;
}

