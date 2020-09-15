#include <bits/stdc++.h>
using namespace std ;

#define int long long

void gogogo(){
	int n;
	cin >> n;
	int a[n+2] = {} ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i+1] ;
	}
	int mx = 0 , cnt = 0;
	for(int i = 1 ; i <= n ; i++){
		if(a[i] > mx && a[i] > a[i+1]){
			cnt++ ;
		}
		mx = max(a[i] , mx) ;
	}
	cout << cnt << '\n' ;
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


