#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int p[n+1] ;
		int pos[n+1] ;
		for(int i =1 ; i <= n ; i++) {
			cin >> p[i] ;
			pos[p[i]] = i ;
		}
		int l = pos[1] , r = pos[1] ;
		int ans[n+1] = {0} ;
		ans[1] = 1 ;
		for(int i =2 ; i <= n ; i++) {
			if(pos[i] < l ) l = pos[i] ;
			else if(pos[i] > r ) r = pos[i] ;
			int len = r - l + 1 ;
			if(len == i) ans[i] = 1 ;
		} 
		for(int i = 1 ; i <= n ; i++) cout << ans[i] ;
		cout << endl ;
	}
	return 0 ;
}

