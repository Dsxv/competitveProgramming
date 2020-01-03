#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , s ;
		cin >> n >> s ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) {
			cin >> a[i] ;
		}
		int ind = -1 ;
		int sum = 0 ;
		for(int i = 0 ; i < n ; i++) {
			sum += a[i] ;
			if(sum > s) {
				ind = i ;
				break ;
			}
		}
		if(ind == -1){
			cout << 0 << endl ; continue ;
		}
		int mx = max_element(a,a+ind+1) - a ;
		sum -= a[mx] ;
		for(int i = ind + 1; i < n ; i++){
			if(mx == i) continue ;
			sum += a[i] ;
			if(sum > s){
				if(i-1 > ind) {
					cout << mx+1 << endl ;
				}else{
					cout << 0 << endl ;
				}
				break ;
			}
		}
		if(sum <= s) cout << mx+1 << endl ;
	}
	return 0 ;
}

