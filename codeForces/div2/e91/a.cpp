#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >> t; 
	while(t--){
		int n ;
		cin >> n;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		int mid[n] = {} ;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(i < n - 1) {
				if(a[mid[i+1]] > a[i]) mid[i] = i ;
				else mid[i] = mid[i+1] ;
			} else {
				mid[n-1] = n - 1 ;
			}
		}
		int mf = 0 ;
		bool found = false ;
		for(int i = 1 ; i < n - 1 ; i++){
			if(a[i] > a[mf] && a[i] > a[mid[i+1]]){
				cout << "YES\n" << mf + 1 << " " << i + 1 << " " << mid[i+1] + 1 << '\n' ;
				found = true ;
				break ;
			}
			if(a[i] < a[mf]) mf = i ;
		}
		if(!found) cout << "NO\n" ;
	}
	return 0 ;
}

