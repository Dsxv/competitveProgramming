#include <bits/stdc++.h>
using namespace std ;

#define int long long

void rec(int n){
	int x = 0 ;
	x++ ;
	if(n == 0) { cout << x ; return ;}
	rec(n-1) ;
}

int32_t main(){
	rec(10) ;	
	return 0 ;
}

