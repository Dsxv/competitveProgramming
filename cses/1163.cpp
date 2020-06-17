#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , x ;
	cin >> n >> x ;
	multiset<int> s ;
	multiset<int> d ;
	s.insert(0) ;
	s.insert(n) ;
	d.insert(n) ;
	for(int i = 0 ; i < x ; i++){
		int p ;
		cin >> p ;
		s.insert(p) ;
		auto it = s.lower_bound(p) ;
		auto it2 = it ;
		it-- , it2++ ;
		int dx = *it2 - *it ;
		d.erase(d.find(dx)) ;
		d.insert(*it2 - p) ;
		d.insert(p - *it) ;
		cout << (*d.rbegin()) << " "  ;
	}

	return 0 ;
}

