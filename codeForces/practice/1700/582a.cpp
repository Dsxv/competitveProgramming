#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ; 
	cin >> n ;
	map<int,int,greater<int>> mp;
	for(int i = 0 ; i < n * n ; i++){
		int x ;
		cin >> x ;
		mp[x]++ ;
	}
	vector<int> ans ;
	while(ans.size() < n){
		int y = mp.begin()->first ;
		mp[y]-- ;
		if(mp[y] == 0) mp.erase(y) ;
		for(auto i : ans){
			int x = __gcd(i,y) ;
			assert(mp[x] >= 2) ;
			mp[x] -= 2 ;
			if(mp[x] == 0) mp.erase(x) ;
		}
		ans.push_back(y) ;
	}
	for(auto i : ans) cout << i << " ";
	return 0 ;
}

