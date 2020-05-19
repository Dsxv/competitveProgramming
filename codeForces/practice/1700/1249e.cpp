#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e5 + 10 ;
int dp[N][2] ;
int n , c ;
int a[N] , b[N] ;

int solve(int i , int j = 0){
	if(i == (n-1)){
		return 0 ;
	}
	if(~dp[i][j]) return dp[i][j] ;
	if(j == 0){
		return dp[i][j] = min(solve(i+1,0) + a[i] , solve(i+1,1) + b[i] + c) ;
	} else {
		return dp[i][j] = min(solve(i+1,0) + a[i] , solve(i+1,1) + b[i]) ;
	}
}

int32_t main(){
	memset(dp,-1,sizeof(dp)) ;
	cin >> n >> c ;
	for(int i = 1 ; i < n ; i++) cin >> a[i] ;	
	for(int i = 1 ; i < n ; i++) cin >> b[i] ;
	reverse(a,a+n) ;
	reverse(b,b+n) ;
	vector<int> ans ;
	for(int i = 0 ; i < n ; i++){
		ans.push_back(solve(i)) ;
	}
	reverse(ans.begin() , ans.end()) ;
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}

