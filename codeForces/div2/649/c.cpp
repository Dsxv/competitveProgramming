#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n;
	int a[n] = {}; 
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	set<int> s ;
	for(int i = 0 ; i < 2*n + 1 ; i++) s.insert(i) ;
	int ans[n] ;
	for(int i = 0 ; i < n ; i++) s.erase(a[i]) ;
	ans[0] = *s.begin() ;
	s.erase(ans[0]) ;
	for(int i = 1 ; i < n ; i++){
		if(a[i] != a[i-1]){
			s.insert(a[i-1]) ;
		}
		ans[i] = *s.begin() ;
		s.erase(ans[i]) ;
	}
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}

