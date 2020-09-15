#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n; 
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	vector<int> ans ;
	sort(a,a+n) ;
	int x = 0 ;
	for(int i = 0 ; i < n ; i++){
		x ^= a[i] ;
		int b = 0 ;
		for(int j = 0 ; j < 32 ; j++){
			if((1LL<<j) & x) continue ;
			b |= (1LL<<j) ;
		}
		ans.push_back(b) ;
	}
	reverse(ans.begin() , ans.end()) ;
	for(auto i : ans) cout << i << '\n' ;
	return 0 ;
}

