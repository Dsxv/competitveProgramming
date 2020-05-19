#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n; 
	cin >> n; 
	int a[n] ;
	map<int,int> mp ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	sort(a,a+n) ;
	if(n == 1){
		cout << -1 ;
		return 0 ;
	}
	if(count(a,a+n,a[0]) == n) {
		cout << 1 << endl << a[0] ;
		return 0 ;
	}
	int d = a[1] - a[0] ;
	set<int> ans ;
	if(n == 2){
		if(d%2 == 0) {
			cout <<3 << endl <<  a[0] - d << " " << a[0] + d/2 << " " << a[1] + d ;
		} else {
			cout << 2 << endl << a[0] - d << " " << a[1] + d ;
		}
		return 0 ;
	}
	for(int i = 0 ; i < n - 1 ; i++){
		mp[a[i+1] - a[i]]++ ;
	}
	if(mp[d] == (n-1)) {
		cout << 2 << endl << a[0] - d << " " << a[n-1] + d ;
		return 0 ;
	}
	if(mp.size() > 2){
		cout << 0;
		return 0;
	}
	int x = mp.begin()->first^mp.rbegin()->first ;
	for(int i = 1 ; i < n ; i++){
		int d = a[i] - a[i-1] ;
		if(a[i] == a[i-1]){
			cout << 0 ;
			return 0 ;
		}
		int y = a[i-1] + (d^x) ;
		mp[d^x]++ ;
		mp[a[i]-y]++ ;
		if(mp[d^x] == n) ans.insert(y) ;
	}
	cout << ans.size() << '\n' ;
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}

