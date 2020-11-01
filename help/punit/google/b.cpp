#include <bits/stdc++.h>
using namespace std ;

#define int long long

int sum(int l , int r){
	return r*(r+1) / 2 - l*(l-1) / 2 ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a ;
		cin >> a ;
		if(a == 1){
			cout << 0 << '\n' ;
			continue ;
		}
		unordered_set<int> s ;
		int l = a , r = a + 1 ;
		int prev = a + 2 ;
		int ans = sum(1 , a - 1) ;
		s.insert(l) ;
		s.insert(r) ;
		l += a ;
		r += a + 1 ;
		while(true){
			ans += sum(prev , l - 1) ;
			for(int i = l ; i <= r ; i++){
				if(s.count(i + a)) goto x ; 
				s.insert(i + a) ;
				if(s.count(i + a + 1)) goto x ;
				s.insert(i + a + 1) ;
			}
			prev = r + 1 ;
			l += a ;
			r += a + 1;
		}
		x : 
		cout << ans << '\n';
	}
	return 0 ;
}

