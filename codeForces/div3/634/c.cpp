#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t;
	while(t--){
		int n ;
		cin >> n ;
		map<int,int> mp ;
		for(int i = 0 ; i < n ; i++){
			int x ;
			cin >> x ;
			mp[x]++ ;
		}
		int l = mp.size() ;
		int ans = 0 ;
		for(auto i : mp){
			for(int j = 1 ; j <= i.second - 1 ; j++){
				ans = max(min(j,l),ans) ;
			}
			ans = max(min(i.second,l-1),ans) ;
		}
		cout << ans << endl ;
	}
	return 0 ;
}

