#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , ans = 0 ;
	cin >> n ;
	map<pair<int,int>, int> mp ;
	while(n--){
		int x , y , z ;
		cin >> x >> y >> z ;
		int tp = x*x + y*y ;
		z *= z ;
		int temp = tp / __gcd(tp , z) ;
		int den = z / __gcd(tp , z) ;
		mp[{temp,den}]++ ;
	}
	for(auto i : mp){
		ans += i.second * (i.second - 1) / 2 ;
	}
	cout << ans << '\n' ;
	return 0 ;
}

