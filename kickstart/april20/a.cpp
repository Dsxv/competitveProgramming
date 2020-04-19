#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(int t){
	int  n;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	int count = 0 ;
	for(int i = 1 ; i < n - 1 ; i++){
		if(a[i] > a[i-1] && a[i] > a[i+1]) count++ ;
	}
	cout << "Case #"<<t<<": "<< count << '\n' ;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		solve(i) ;
	}	
	return 0 ;
}


