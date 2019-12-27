#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , s ;
		cin >> n >> s ;
		int pre[n+1] = {0} , mx[n+1] = {0} , ps[n+1] = {0} ;
		for(int i = 1 ; i <= n ; i++){
			int x ; 
			cin >> x ;
			pre[i] = pre[i-1] + x ;
			if(mx[i-1] < x) {
				ps[i] = i ;
			} else ps[i] = ps[i-1] ;
			mx[i] = max(mx[i-1],x) ;
		}
		int ans = 0 ;
		if(pre[n] > s) {
			for(int i = n ; i >= 1 ; i--){
				if(pre[i] - mx[i] <= s) {
					ans = ps[i] ;
					break ;
				}
			}
		}
		cout << ans << endl ;
	}
	return 0 ;
}

