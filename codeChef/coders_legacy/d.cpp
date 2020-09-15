#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		string s[n] ;
		bool dp[n][m] = {} ;
		for(int i = 0 ; i < n ; i++) cin >> s[i] ;
		dp[n-1][m-1] = 1 ;
		for(int i = n - 1 , j = m - 2; j >= 0 ; j--){
			if(s[i][j] == '#') break ;
			dp[i][j] = 1 ;
		}
		for(int i = n - 2 , j = m - 1 ; i >= 0 ; i--){
			if(s[i][j] == '#') break ;
			dp[i][j] = 1 ;
		}
		for(int i = n - 2 ; i >= 0 ; i--){
			for(int j = m - 2 ; j >= 0 ; j--){
				if(s[i][j] == '#') continue ;
				dp[i][j] = dp[i+1][j] | dp[i][j+1] ;
			}
		}
		vector<pair<int,int>> v ;
		v.push_back({0,0}) ;
		string ans = "" ;
		ans += s[0][0] ;
		int visited[n][m] = {} ;
		while(true){
			if(v.back() == make_pair(n-1,m-1)) break ;
			vector<pair<int,int>> temp ;
			for(auto i : v){
				int x1 = i.first + 1 , y1 = i.second ;
				if(x1 < n && y1 < m && dp[x1][y1] && !visited[x1][y1]){
					visited[x1][y1] = 1 ;
					temp.push_back({x1 , y1}) ;
				}
				x1 = i.first , y1 = i.second + 1;
				if(x1 < n && y1 < m && dp[x1][y1] && !visited[x1][y1]){
					visited[x1][y1] = 1 ;
					temp.push_back({x1 , y1}) ;
				}
			}
			char mch = 'z' ;
			for(auto i : temp) mch = min(s[i.first][i.second] , mch) ;
			ans += mch ;
			v.clear() ;
			for(auto i : temp) if(s[i.first][i.second] == mch) v.push_back(i) ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}


