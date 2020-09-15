#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
int a[N] ;
int c[N] ;
int dp[N] ;
int solve(set<int> s , int k , int bit = 30){
	if(bit == -1) return 0 ;
	for(int i = 0 ; i < N ; i++){
		c[i] = dp[i] = 0 ;
	}
	vector<int> v ;
	for(auto i : s){
		if((1LL<<bit)&a[i]){
			v.push_back(i) ;
			c[i] = 1 ;
		}
	}
	int n = v.size() ;
	dp[0] = c[0] , dp[1] = c[1] ;
	for(int i = 2 ; i < N ; i++){
		dp[i] = max(dp[i-1] , dp[i-2] + c[i]) ;
	}
	int ans = 0 ;
	set<int> tp(v.begin() , v.end()) ;
	if(*max_element(dp, dp + N) >= k){
		ans = 1LL << bit ;
	} else {
		tp = s ;
	}
	return ans + solve(tp , k , bit - 1) ;
}


int32_t main(){
	int n , k ;
	cin >> n >> k ;
	set<int> s ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		s.insert(i) ;
	}
	cout << solve(s,k) ;
	return 0 ;
}

