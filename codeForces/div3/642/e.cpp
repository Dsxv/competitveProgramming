#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e6 + 10 ;
int dp[N][2] ;
int pre[N] ;

int sum(int l , int r , int n){
	r = min(n-1,r) ;
	if(r < l) return 0 ;
	//cout <<r << " " << l << " " <<  pre[r] - pre[l-1] << ":\n" ;
	return pre[r] - pre[l-1] ;
}

int solve(int* a , int n , int k , int i = 0 , int j = 0){
	if(i >= n) return 0 ;
	if(~dp[i][j]) return dp[i][j] ;
	if(j == 0){
		if(a[i] == 1){
			int x = solve(a,n,k,i+k,1) + sum(i+1,i+k-1,n) ;
			int y = solve(a,n,k,i+1,0) + 1 ;
			return dp[i][j] = min(x,y) ;
		} else {
			return dp[i][j] = solve(a,n,k,i+1,0) ;
		}
	} else {
		if(a[i] == 1){
			return dp[i][j] = solve(a,n,k,i+k,1) + sum(i+1,i+k-1,n) ;
		} else {
			int x = solve(a,n,k,i+k,1) + sum(i+1,i+k-1,n) + 1;
			int y = sum(i+1,n-1,n) ;
			return dp[i][j] = min(x,y) ;
		}
	}
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		for(int i = 0 ; i < n + 2 ; i++){
			for(int j = 0 ; j < 2 ; j++) dp[i][j] = -1 ;
			pre[i] = 0 ;
		}
		string s ; cin >> s ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			a[i] = s[i] - '0' ;
			pre[i] = a[i] ;
			if(i) pre[i] += pre[i-1] ;
		}
		cout << solve(a,n,k) << '\n';
	}
	return 0 ;
}

