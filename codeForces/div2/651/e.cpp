#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ; cin >> n ;
	string s , t ;
	cin >> s >> t ;
	set<int> a , b ;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == t[i]) continue ;
		if(s[i] == '0') a.insert(i) ;
		else b.insert(i) ;
	}
	if(a.size() != b.size()){
		cout << -1 ;
		return 0 ;
	}
	if(a.size() == 0){
		cout << 0 ;
		return 0 ;
	}
	int ans = 0 ;
	while(a.size() && b.size()){
		if(*a.begin() > *b.begin()) swap(a,b) ;
		int mn = 0 ;
		while(true){
			auto tp = a.lower_bound(mn) ;
			if(tp == a.end()) break ;
			int x = *tp ;
			auto it = b.lower_bound(x) ;
			if(it == b.end()){
				break ;
			} else {
				mn = *it ;
				a.erase(x) ;
				b.erase(it) ;
			}
		}
		ans++ ;
	}
	cout << ans ;
	return 0 ;
}

