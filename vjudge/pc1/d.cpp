#include <bits/stdc++.h>
using namespace std ;

const int N = 1e3 + 10 ;
int cnt[N][N]  , dp[N][N] ;
int n;

pair<int , string> solve(vector<vector<int>>& a , int ch){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			dp[i][j] = cnt[i][j] = 0 ;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			int x = a[i][j] ;
			if(!x) {
				cnt[i][j] = 1 ;
				continue ;
			}
			while(x%ch == 0){
				x /= ch ;
				cnt[i][j]++ ;
			}
		}
	}
	for(int i = 0 ; i < N ; i++) dp[n][i] = dp[i][n] = 1e5 + 10 ;
	dp[n-1][n-1] = cnt[n-1][n-1] ;
	for(int i = n - 1 ; i >= 0 ; i--){
		for(int j = n - 1 ; j >= 0 ; j--){
			if(i == n - 1 && j == n - 1) continue ;
			dp[i][j] = min(dp[i+1][j] , dp[i][j+1]) + cnt[i][j] ;
		}
	}
	int x = 0 , y = 0 ;
	string s = "" ;
	while(x < n || y < n){
		if(x == n - 1 && y == n - 1) break ;
		if(x == n - 1){
			s += 'R' ;
			y++ ; continue ;
		}
		if(y == n - 1){
			s += 'D' ;
			x++ ; continue ;
		}
		if(dp[x][y+1] < dp[x+1][y]){
			y++ ; s += 'R' ;
			continue ;
		} else {
			x++ ; s += 'D' ;
			continue ;
		}
	}
	return {dp[0][0] , s} ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	cin >> n ;
	vector<vector<int>> a(n , vector<int>(n))  ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++) cin >> a[i][j] ;
	}
	pair<int,int> p(-1,-1) ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(a[i][j] == 0){
				p = {i,j} ;
			}
		}
	}
	auto [v1 , s1] = solve(a , 2) ;
	auto [v2 , s2] = solve(a , 5) ;
	if(v1 > v2){
		swap(v1 , v2) ;
		swap(s1 , s2) ;
	}
	if(~p.first && v1 > 0){
		cout << 1 << '\n' ;
		cout << string(p.first , 'D') + string(n-1 , 'R') + string(n - p.first - 1 , 'D') ;
	} else {
		cout << v1 << '\n' << s1 ;
	}
	return 0 ;
}

