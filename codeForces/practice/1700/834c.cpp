#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int a, b ;
		cin >> a >> b ;
		int x = -1 ;
		int lo = 1 , hi = 1e6 ;
		while(lo <= hi){
			int mid = (lo + hi) / 2 ;
			if(mid*mid*mid == (a*b)){
				 x = mid ;
				 break ;
			}
			if(mid*mid*mid < (a*b)){
				lo = mid + 1 ;
			} else {
				hi = mid - 1 ;
			}
		}
		if(~x){
			cout << "Yes\n"  ;
		} else {
			cout << "No\n" ;
		}
	}
	return 0 ;
}

