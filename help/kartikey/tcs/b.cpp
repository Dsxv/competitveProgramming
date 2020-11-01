#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n ;
	if(n <= 0 || n > 1e5) {
		cout << "Wrong Input" ;
		return 0 ;
	}
	vector<int> v ;
	int x ;
	while(cin >> x){
		v.push_back(x) ;
		if(x <= 0 || x > 1e5){
			cout << "Wrong Input" ;
			return 0 ;
		}
	}
	if(v.size() != n){
		cout << "Wrong Input" ;
		return 0 ;
	}

	set<int> s ;
	for(int i = 1 ; i < (2e5 + 20) ; i++) s.insert(i) ;
	int ans = 0 ;
	sort(v.begin() , v.end()) ;
	for(int i = 0 ; i < n ; i++){
		auto it = s.lower_bound(v[i]) ;
		ans += *it ;
		s.erase(it) ;
	}
	cout << ans ;
	return 0 ;
}

