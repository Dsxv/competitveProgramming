#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		int a[n][m + 1] = {} ;
		string s[n] ;
		for(int i = 0 ; i < n ; i++) cin >> s[i] ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 1 ; j <= m ; j++){
				a[i][j] += a[i][j - 1] ;
				if(s[i][j-1] == '*') a[i][j]++ ;
			}
		}
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 1 ; j <= m ; j++){
				for(int k = 1 ; k <= n ; k++){
					int id = i + k - 1 ;
					if(id >= n) break ;
					int l = j - k , r = j + k - 1 ;
					if(l < 0 || r > m) continue ;
					int cnt = a[id][r] - a[id][l] ;
					if(cnt != (r - l)){
						break ;
					}
					ans++ ;
				}
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

