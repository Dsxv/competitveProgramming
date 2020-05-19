#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n; 
		int count = 0 ;
		while(n >= 2){
			int lo = 0 , hi = 1e9 ;
			int ans = 0 ;
			while(lo <= hi){
				int mid = (lo + hi) / 2 ;
				if(n >= mid*(3*mid + 1)/2){
					lo = mid + 1 ;
					ans = mid ;
				} else {
					hi = mid - 1 ;
				}
			}
			count++ ;
			n -= (ans*(3*ans + 1)/2) ;
		}
		cout << count << '\n' ;
	}

	return 0 ;
}

