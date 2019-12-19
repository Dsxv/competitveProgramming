#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 1e9 + 7 ;
int dp[105][105] ;

int solve(map<int,int>& mp , int n , int i = 0 , int j = 0){
	if(j < i - j || j > n) { //close brackets more at any pt
		return 0 ;
	} 
	if(i == 2*n){
		return j == n ;
	}
	if(dp[i][j] != -1) return dp[i][j] ;

	if(mp.count(i)) dp[i][j] = solve(mp,n,i+1,j+1) ;
	else dp[i][j] = ( solve(mp,n,i+1,j) + solve(mp,n,i+1,j+1) ) %mod ;
	return dp[i][j] ;
}



int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ; 
		cin >> n >> k ;
		map<int,int> mp ;
		for(int i = 0 ; i < k ; i++){
			int x ;
			cin >> x ; 
			mp[x-1] = 1 ;
		}
		for(int i = 0 ; i <= 2*n ; i++){
			for(int j = 0 ; j <= n ; j++) dp[i][j] = -1 ;
		}
		cout << solve(mp,n) << endl ;
	}
	return 0 ;
}

