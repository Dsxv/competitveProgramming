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
		bool found = false ;
		for(int i = 0 ; i < n ; i++){
			int id = i ;
			for(int j = i+1 ; j < n ; j++){
				if(a[j] == a[i]) id = j ;
			}
			if(id - i > 1) found = true ;
		}
		if(found) cout << "YES\n" ;
		else cout << "NO\n" ;
	}
	return 0 ;
}

