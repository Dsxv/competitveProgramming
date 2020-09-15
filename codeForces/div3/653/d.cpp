#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t; 
	while(t--){
		int n , k ;
		cin >> n >> k;
		map<int,int> mp ;
		for(int i = 0 ; i < n ; i++){
			int x ;
			cin >> x ;
			mp[k - x%k]++ ;
		}
		int mx = 0 ;
		for(auto i : mp){
			if(i.first == 0 || i.first == k) continue ;
			mx = max( mx ,  (i.second - 1)*k + i.first) ;
		}
		if(mx) mx++ ;
		cout << mx << '\n' ;
	}
	return 0 ;
}

