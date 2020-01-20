#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , s , k ;
		cin >> n >> s >> k ;
		map<int,int> mp ;
		for(int i = 0 ; i < k ; i++) {
			int x ; cin >> x ;
			mp[x] = 1 ;
		}
		int l = INT_MAX , r = INT_MAX ;
		for(int i = s ; i >= 1 ; i--){
			if(!mp.count(i)) {l = (s-i) ; break ;}
		}
		for(int i = s ; i <= min(n,s + 1005) ; i++) {
			if(!mp.count(i)) { r = (i-s) ; break ;}
		}
		cout << min(l,r) << endl ;
	}
	return 0 ;
}

