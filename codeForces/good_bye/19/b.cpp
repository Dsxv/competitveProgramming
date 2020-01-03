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
		int id = -1 ;
		for(int i = 0 ; i < n - 1 ; i++){
			if(abs(a[i]-a[i+1]) > 1) {
				id = i+1 ; break ;
			}
		}
		if(id == -1) cout << "no\n" ;
		else cout << "yes\n" << id << " " << id + 1 << endl ;
	}
	return 0 ;
}

