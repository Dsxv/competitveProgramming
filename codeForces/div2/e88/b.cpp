#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m , x , y ;
		cin >> n >> m >> x >> y ;
		string s[n] ;
		for(int i = 0 ; i < n ; i++) cin >> s[i] ;
		if(x*2 <= y){
			int cnt = 0 ;
			for(int i = 0 ; i < n ; i++){
				cnt += count(s[i].begin() , s[i].end() , '.') ;
			}
			cout << cnt*x << '\n' ;
			continue ;
		}
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			int cnt = 0 ;
			for(int j = 0 ; j < m ; j++){
				if(s[i][j] == '*'){
					ans += (cnt/2)*y ;
					ans += (cnt%2)*x ;
					cnt = 0 ;
				} else cnt++ ;
			}
			ans += (cnt/2)*y ;
			ans += (cnt%2)*x ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

