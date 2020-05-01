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
		bool found = true ;
		for(int i = 0 ; i < n - 1 ; i++){
			if(a[i] < a[i+1]){
				found &= (a[i] == (a[i+1] - 1)) ;
			}
		}
		cout << (found?"Yes\n":"No\n") ;
	}
	return 0 ;
}

