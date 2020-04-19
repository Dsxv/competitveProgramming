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
		int b[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		for(int i = 0 ; i < n ; i++){
			cin >> b[i] ;
		}
		pair<bool,bool> ok[n] ;
		ok[0] = {false,false} ;
		for(int i = 1 ; i < n ; i++){
			ok[i] = ok[i-1] ;
			if(a[i-1] < 0) ok[i].first = true ;
			if(a[i-1] > 0) ok[i].second = true ;
		}
		bool found = true ;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(b[i] - a[i] < 0){
				if(!ok[i].first) found = false ;
			}
			if(b[i] - a[i] > 0){
				if(!ok[i].second) found = false ;
			}
		}
		if(!found) cout << "NO\n" ;
		else cout << "YES\n" ;
	}
	return 0 ;
}

