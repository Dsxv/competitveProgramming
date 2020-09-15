#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 205 ;
const int INF = 1e15 ;
int dp[N][N][N] ;
int n , m , K ;

int solve(string&s , string& t , int i = 0 , int j = 0 , int k = 0){
	if(k == K){
		return 0 ;
	}
	if(i == n || j == m){
		return INF ;
	}
	if(~dp[i][j][k]) return dp[i][j][k] ;
	int x = solve(s , t , i + 1 , j + 1 , k + 1) ;
	int y = solve(s , t , i + 1 , j , k) ;
	int z = solve(s , t , i , j + 1 , k) ;
	return dp[i][j][k] = min({x + abs(s[i]-t[j]) , y , z}) ;
}


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		cin >> n >> m >> K ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				for(int l = 0 ; l < K ; l++) dp[i][j][l] = -1 ;
			}
		}
		string a , b ; cin >> a >> b ;
		cout << solve(a , b) << '\n' ;
	}
	return 0 ;
}

