#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		map<int , vector<int>> mp ;
		for(int i = 0 ; i < n ; i++){
			int x ; cin >> x ;
			mp[x].push_back(i) ;
		}
		int ans = INT_MAX ;
		for(auto i : mp){
			auto &v = i.second ;
			if(v.size() < 2) continue ;
			int l = v.size() ;
			int x = v[0] + v[1] - 1 ;
			int y = (n + 1 - v[l - 1]) + (n - v[l - 2]) ;
			int z = n - v[l - 1] + (v[0] == 0 ? 1 : v[0] - 1) ;
			ans = min({ans , x , y , z}) ;
		}
		cout << (ans == INT_MAX ? -1 : ans) << '\n' ;
	}
	return 0 ;
}

