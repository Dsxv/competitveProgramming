#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e4 + 5 ;

pair<int,int> dp[N][N] ;

pair<int,int> solve(int* a , int i , int j){
	if(j-i == 1){
			return {max(a[i],a[j]),min(a[i],a[j])} ;
	}
	if(dp[i][j].first != -1) return dp[i][j] ;
	
	auto fr = solve(a,i+1,j) ;
	auto bk = solve(a,i,j-1) ;
	if(fr.second + a[i] > bk.second + a[j]){
		return dp[i][j] = {fr.second + a[i] , fr.first} ;
	} else {
		return dp[i][j] = {bk.second + a[j] , bk.first} ;
	}
}

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= n ; j++) dp[i][j] = {-1,-1} ;
	}
	cout << solve(a,0,n-1).first;
	return 0 ;
}

