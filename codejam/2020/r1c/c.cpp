#include <bits/stdc++.h>
using namespace std ;

#define int long long

void gogogo(){
	int n , d ;
	cin >> n >> d ;
	map<int,int> mp ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		mp[a[i]]++ ;
	}
	int ans = 0 ;
	if(d == 2){
		bool ok = false ;
		for(auto i : mp){
			if(i.second > 1) ok = true ;
		}
		if(!ok) ans = 1 ;
		else ans = 0 ;
	} else if(d == 3){
		bool ok = false ;
		for(auto i : mp){
			if(i.second > 2) ok = true ;
		}
		if(!ok) {
			bool check = false ;
			for(auto i : mp){
				if(i.first == 2 && i.first != mp.rbegin()->first){
					check = true ;
					break ;
				} else if(mp.count(2*i.first)) {
					check = true ;
					break ;
				}
			}
			if(check) ans = 1 ;
			else ans = 2 ;
		} else {
			ans = 2 ;
		}
	} else {
		ans = 0 ;
	}
	cout << ans << '\n' ;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		cout << "Case #" << i << ": ";
		gogogo() ;
	}	
	return 0 ;
}


