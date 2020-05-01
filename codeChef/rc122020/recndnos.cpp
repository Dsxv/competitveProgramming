#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		vector<pair<int,int>> v ;
		v.push_back({a[0],1}) ;
		for(int i = 1 ; i < n ; i++){
			if(v.back().first == a[i]){
				v.back().second++ ;
			} else {
				v.push_back({a[i],1}) ;
			}
		}
		map<int,int> mp ;
		for(auto i : v){
			mp[i.first] += (i.second + 1) / 2 ;
		}
		int mx = 0 ;
		int ans = -1 ;
		for(auto i : mp){
			if(i.second > mx){
				ans = i.first ;
				mx = i.second ;
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

