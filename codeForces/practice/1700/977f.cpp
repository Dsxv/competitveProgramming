#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	map<int,int> mp ;
	int ans[n] = {} ;
	for(int i = n - 1 ; i >= 0 ; i--){
		ans[i] = mp[a[i]] = mp[a[i] + 1] + 1 ;
	}
	int mx = 1 ;
	for(auto i : mp){
		mx = max(mx , i.second) ;
	}
	vector<int> v ;
	for(int i = 0 ; i < n ; i++){
		if(v.size()){
			if(ans[i] == mx && a[i] == a[v.back()] + 1){
				v.push_back(i) ;
				mx-- ;
			}
		} else {
			if(ans[i] == mx){
				v.push_back(i) ;
				mx-- ;
			}
		}
	}
	cout << v.size() << '\n' ;
	for(auto i : v) cout << i + 1 << " " ;
	return 0 ;
}

