#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	int n; 
	int a[2*n + 1];
	for(int i = 0 ; i < n ; i++){
		int x ; cin >> x ;
		a[i] = a[n+i] = x ;
	}	
	a[2*n] = INT_MAX ;
	
	return 0 ;
}

