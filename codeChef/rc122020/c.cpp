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
		map<int,vector<int>> mp ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
			mp[a[i]].push_back(i) ;
		}
		int start = -1 ;
		int count = 1 ;
		for(auto i : mp){
			vector<int> &v = i.second ;
			auto it = upper_bound(v.begin(),v.end(),start) ;
			if(it != v.end()){
				start = *it ;
			} else {
				count++ ;
				start = v[0] ;
			}
		}
		cout << count << '\n' ;
	}
	return 0 ;
}

