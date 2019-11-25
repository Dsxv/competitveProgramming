#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 5e3 + 10 ;

int dp[N][N] ;

int solve(vector<int>& v , int i , int j){
	if(i == j) return 0 ;
	if(dp[i][j] != -1) return dp[i][j] ;
	if(v[i] == v[j]) {
		return dp[i][j] = 1 + solve(v,i+1,j-1) ;
	}else{
		return dp[i][j] = 1 + min(solve(v,i+1,j),solve(v,i,j-1)) ;
	}
}

int32_t main(){
	vector<int> v ;
	int n ;
	cin >> n ;
	int x ; cin >> x ;
	v.push_back(x) ;
	for(int i = 1 ; i < n ; i++){
		cin >> x ;
		if(v.back() == x) continue ;
		else v.push_back(x) ;
	}
	n = v.size() ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++) dp[i][j] = -1 ;
	}
	cout << solve(v,0,n-1) ;
}

