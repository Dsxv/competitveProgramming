#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >> t; 
	while(t--){
		int n , k ;
		cin >> n >> k ;
		int mni = 0 ;
		int a[k] ;
		for(int i = 0 ; i < k ; i++) cin >> a[i] ;
		for(int i = 1 ; i < k ; i++){
			if(n%a[i] < n%a[mni]){
				mni = i ;
			}
		}
		cout << mni + 1 << " " << n/a[mni] << '\n' ;
	}
	return 0 ;
}

