#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct star{
	int x , y , b ;
	star(){
		x = 0 , y = 0 , b = 0 ;
	}
} ;

int32_t main(){
	int n , q , c ;
	cin >> n >> q >> c ;
	c++ ;
	star s[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> s[i].x >> s[i].y >> s[i].b ;
	}
	int dp[c][101][101] = {} ;
	for(int i = 0 ; i < c ; i++){
		for(int j = 0 ; j < n ; j++){
			dp[i][s[j].x][s[j].y] += (s[j].b + i) % c ;
		}
		for(int j = 1 ; j <= 100 ; j++){
			for(int k = 1 ; k <= 100 ; k++){
				dp[i][j][k] += dp[i][j-1][k] + dp[i][j][k-1] - dp[i][j-1][k-1] ;
			}
		}
	}
	vector<int> ans(q) ;
	for(int i = 0 ; i < q ; i++){
		int t , x1 , y1 , x2 , y2 ;
		cin >> t >> x1 >> y1 >> x2 >> y2 ;
		ans[i] = dp[t%c][x2][y2] -
				 dp[t%c][x1-1][y2] - dp[t%c][x2][y1-1] + 
				 dp[t%c][x1-1][y1-1] ;
	}
	for(auto i : ans) cout << i << '\n' ;
	return 0 ;
}

