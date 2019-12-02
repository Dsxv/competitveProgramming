#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e3 + 10 ;

int dp[N][N][10] ;

int solve(vector<int>& a , vector<int>& b , int k , int i  = 0 , int j = 0){
	if(k < 0) return INT_MIN ;
	if(i == a.size() || j == b.size()) return 0 ;
if(dp[i][j][k] != -1) return dp[i][j][k] ;
	if(a[i] == b[j]) return dp[i][j][k] = solve(a,b,k,i+1,j+1) + 1 ;
	int x = solve(a,b,k,i,j+1) ;
	int y = solve(a,b,k,i+1,j) ;
	int z = solve(a,b,k-1,i+1,j+1) + 1 ;
	return dp[i][j][k] = max({x,y,z});
}
	

int32_t main(){
	int n , m , k ;
	cin >> n >> m >> k ;
	vector<int> a(n) , b(m) ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < m ; i++) cin >> b[i] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			for(int l = 0; l <= k ; l++) dp[i][j][l] = -1 ;
		}
	}
	cout << solve(a,b,k) ;
	return 0 ;
}

