#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int INF = 1e15 ;

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		int sum = 0 ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
			if(i%2 == 0) {
				sum += a[i] ;
				a[i] *= -1 ;
			}
		}
		int mo = 0 , me = 0 , pre = 0;
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			pre += a[i] ;
			if(i&1){
				mo = min(mo , pre) ;
				ans = max(ans , pre - mo) ;
			} else {
				me = min(me , pre) ;
				ans = max(ans , pre - me) ;
			}
		}
		cout << sum + ans << '\n' ;
	}
	return 0 ;
}

