#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	// logic is : if you have n elements that provide you max ans
	// you would need at least n - 2 elements that have that bit set
	// which means why would you even care to add that, it's just increasing the size 
	// unless , the req size remains same!
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = i ; j < n ; j++){
			for(int k = j ; k < n ; k++){
				ans = max(ans , a[i]|a[j]|a[k]) ;
			}
		}
	}
	cout << ans ;
	return 0 ;
}

