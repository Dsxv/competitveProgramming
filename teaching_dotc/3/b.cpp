#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	while(1){
		int n;  cin >> n; 
		if(!n) break ;
		int ans = 0 ;
		double l = floor(sqrt((double)n)) ;
		bool ok = true ;
		if(abs(n - l*l) <= 1e-9) ok = false ;
		cout << (!ok ? "yes\n" : "no\n")  ;
	}
	return 0 ;
}

