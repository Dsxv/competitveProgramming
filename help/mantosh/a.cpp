#include <bits/stdc++.h>
using namespace std ;

#define int long long

int f(int x = 10 , int y = 7){
	if(x < y) return f(y,x) ;
	else if(y) {
		int z = f(x,y-1) ;
		z += x ;
		return z ;
	} else return 0 ;
}

int32_t main(){
	cout << f() ;
	return 0 ;
}

