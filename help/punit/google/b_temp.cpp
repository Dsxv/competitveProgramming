#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int l , int r){
	return r*(r+1) / 2 - l*(l-1) / 2 ;
}

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int sum = 0 ;
		const int mod = 1e9 + 7 ;
		int cur = 1 ;
		for(int i = 1 ; i < n ; i++){
			sum = ( sum + solve(cur , cur + (n - i - 1) )  ) % mod ;
			cur = cur + (n - i) + (i + 1) ;
		}
		cout << sum << '\n' ;
	}
	return 0 ;
}

