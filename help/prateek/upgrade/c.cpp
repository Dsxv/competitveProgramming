#include <bits/stdc++.h>
using namespace std ;

#define int long long

int dp[20][2] ;

int solve(int n , int k , int p){
	vector<int> v ;
	while(n){
		v.push_back(n % 10) ;
		n /= 10 ;
	}
	reverse(v.begin() , v.end()) ;
	
	

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int l , r , k , p ;
		cin >> l >> r >> k >> p ;
		cout << solve(r , k , p) - solve(l , k , p) << '\n' ;
	}
	return 0 ;
}

