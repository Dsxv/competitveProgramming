#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 5e3 + 10 ;
pair<int,int> dp[N][N] ;

pair<int,int> solve(int* a , int n , int i, int j){
	if(abs(i-j) <= 1){
		if(i == j) return {a[i],0} ;
		else return {max(a[i],a[j]) , min(a[i],a[j])} ;
	}
	if(~dp[i][j].first) return dp[i][j] ;
	auto ff = solve(a,n,i+1,j) ;
	auto bb = solve(a,n,i,j-1) ;
	if(ff.second + a[i] > bb.second + a[j]){
		return dp[i][j] = {ff.second + a[i] , ff.first} ;
	} else {
		return dp[i][j] = {bb.second + a[j] , bb.first} ;
	}
}



int32_t main(){
	memset(dp , -1 , sizeof(dp)) ;
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	cout << solve(a,n,0,n-1).first ;
	return 0 ;
}

