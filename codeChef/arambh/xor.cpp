#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int n){
	if(n <=0) return 0 ;
	int x = n%4 ;
	if(x == 0) return n ;
	if(x == 1) return 1 ;
	if(x == 2) return n+1 ;
	if(x == 3) return 0 ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int l , r ;
		cin >> l >> r ;
		cout << (solve(r)^solve(l-1)) << endl ;
	}
	return 0 ;
}

