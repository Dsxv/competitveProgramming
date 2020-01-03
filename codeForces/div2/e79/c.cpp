#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		int a[n] , b[m] ;
		int pos[n] ;
		for(int i = 0 ; i < n ; i++) {
			cin >> a[i] ;
			pos[a[i]] = i ;
		}
		for(int i = 0 ; i < m ; i++) cin >> b[i] ;
		int mxl = -1 ;
		int ans = 0 ;
		for(int i = 0 ; i < m ; i++){
			if(pos[b[i]] > mxl)  {
				mxl = pos[b[i]] ;
				ans += 2*(pos[b[i]] - i) + 1 ;
			} else ans++ ;
		}
		cout << ans << endl ;
	}
	return 0 ;
}

