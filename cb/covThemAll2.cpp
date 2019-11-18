#include <bits/stdc++.h>
using namespace std ;

const int mod = 1e9 + 7 ;

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		pair<int,int> a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i].first ;
		for(int i = 0 ; i < n ; i++) cin >> a[i].second ;
		int sum = 0 ;
		for(int i = 0 ; i < n ; i++){
			for(int j = i ; j < n ; j++){
				int x = abs(a[i].first-a[j].first)*max(a[i].second,a[j].second) ;
				sum = (sum + x)%mod ;
			}
		}
		cout << sum << endl ;
	}
	return 0 ;
}

