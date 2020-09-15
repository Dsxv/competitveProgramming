#include <bits/stdc++.h>
using namespace std ;

#define int long long

int basis[30] , sz ;

void insert(int x){
	for(int i = 0 ; i < 30 ; i++){
		if((x & 1 << i) == 0) continue  ;
		if(basis[i] == 0){
			sz++ ;
			basis[i] = x ;
			return ;
		}
		x ^= basis[i] ;
	}
}

int32_t main(){
	int n ;
	cin >> n ;
	int xr = 0 ;
	for(int i = 0 ; i < n ; i++) {
		int x ; cin >> x ;
		xr ^= x ;
		insert(xr) ;
	}
	if(xr == 0){
		cout << -1 ;
	} else {
		cout << sz ;
	}
	return 0 ;
}

