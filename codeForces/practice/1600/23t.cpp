#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	vector<pair<int,int>> edges ;
	for(int i = 0 ; i < n-1 ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		edges.push_back({f,s}) ;
	}
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int count = 0 ;
	int ans = 0 ;
	map<int,int> mp ;
	for(auto i : edges){
		int x = i.first , y = i.second ;
		if(a[x] != a[y]){
			mp[x]++ ;
			mp[y]++ ;
			ans = -1 ;
			count++ ;
		}
	}
	for(auto i : mp){
		if(i.second == (count)){
			ans = i.first ;
		}
	}
	if(ans == -1){
		cout << "NO" ;
	} else {
		cout << "YES\n" ;
		cout << ans+1 ;
	}
	return 0 ;
}

