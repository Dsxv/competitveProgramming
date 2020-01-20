#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 105 ;
int dp[N][N][N] ;
char ch[N][N] ;
int solve(int n , int m , int x1 = 0 , int y1 = 0 , int x2 = 0){
	if(x1 >= n || x2 >= n ) return 0 ;
	if(y1 >= m) return 0 ;
	if(x1 == n-1 && y1 == m-1){
	}
	if(dp[x1][y1][x2] != -1) return dp[x1][y1][x2] ;
	int y2 = x1+y1-x2 ;
	if(y2 < 0 || y2 >= m) return 0 ;
	if(ch[x1][y1] == '#'|| ch[x2][y2] == '#') return 0 ;
	int a = 0 ;
	if((x1==x2) && (y1 == y2)) a = (ch[x1][y1] == '*') ;
	else a = ((ch[x1][y1] == '*') + (ch[x2][y2] == '*')) ; 
	int p = solve(n,m,x1+1,y1,x2+1) , q = solve(n,m,x1,y1+1,x2+1) ;
	int r = solve(n,m,x1+1,y1,x2) , s = solve(n,m,x1,y1+1,x2) ;
	return dp[x1][y1][x2] = a + max({p,q,r,s}) ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> m >> n ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cin >> ch[i][j] ;
			}
		}
		for(int i = 0 ; i <= n ; i++){
			for(int j = 0 ; j <= m ; j++){
				for(int k = 0 ; k <= n ; k++){
					dp[i][j][k] = -1 ;
				}
			}
		}
		cout << solve(n,m) << '\n' ;
		//cout << dp[0][1][0] << " " << dp[0][1][1] << " " << dp[1][0][1] << " " << dp[1][0][0] ;
	}
	return 0 ;
}

