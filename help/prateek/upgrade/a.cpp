#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int n){
	int ans = 0 ;
	while(n){
		ans += n % 2 ;
		ans *= 2 ;
		n /= 2 ;
	}
	return ans ;
}

int32_t main(){
	const int N = 1 << 17 ;
	set<int> s ;
	for(int i = 1 ; i < N ; i += 2){
		int rev = solve(i) ;
		int bits = ceil(log2(i)) ;
		s.insert((rev << bits) + i) ;
		s.insert((rev << (bits + 1)) + (1LL << (bits + 1)) + i) ;
		s.insert((rev << (bits + 1)) + i) ;
	}
	int t ;
	cin >> t ;
	while(t--){
		int x ; cin >> x ;
		auto it = s.lower_bound(x) ;
		int ans = INT_MAX ;
		if(it != s.begin()) {
			auto it2 = it ;
			it2-- ;
			ans = min(ans , x - *it2) ;
		}
		if(it != s.end()){
			ans = min(ans , *it - x) ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

