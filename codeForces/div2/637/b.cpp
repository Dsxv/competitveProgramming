#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		int a[n] ;
		bool isp[n] = {} ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		for(int i = 1 ; i < n - 1 ; i++){
			if(a[i] > a[i-1] && a[i] > a[i+1]) isp[i] = 1 ;
		}
		int total = 0 , best , l = 0;
		k -= 2 ;
		for(int i = 0 ; i < k ; i++){
			total += isp[i] ;
		}
		best = total ;
		for(int i = k ; i < n ; i++){
			total -= isp[i-k] ;
			total += isp[i] ;
			if(total > best){
				best = total ;
				l = i-k ;
			}
		}
		cout << best + 1 << " " << l+1 << endl ;
	}
	return 0 ;
}

