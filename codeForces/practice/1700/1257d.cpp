#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int m ;
		cin >> m ;
		int c[n+1] = {} ;
		for(int i = 0 ; i < m ; i++) {
			int f , s ;
			cin >> f >> s ;
			c[s] = max(c[s] , f) ;
		}
		int mx = 0 ;
		for(int i = n; i >= 1 ; i--){
			mx = max(mx , c[i]) ;
			c[i] = mx ;
		}
		int cnt = 0 ;
		for(int i = 0 ; i < n ;){
			cnt++ ;
			int j = i ;
			int mx = a[i] ;
			for(; j < n && c[j-i+1] >= a[j] && c[j-i+1] >= mx ; j++){
				mx = max(mx , a[j]) ;
			}
			if(j == i){
				cnt = -1 ;
				break ;
			}
			i = j ;
		}
		cout << cnt << '\n' ;
	}
		return 0 ;
}

