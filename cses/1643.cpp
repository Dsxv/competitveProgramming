#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n; 
	int a[n] ;
	int mx = INT_MIN ;
	int sum = 0 , cursum = 0 ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		mx = max(mx , x) ;
		cursum += x ;
		if(cursum < 0) cursum = 0 ;
		sum = max(cursum , sum) ;
	}
	if(mx < 0) sum = mx ;
	 cout << sum ;
	return 0 ;
}

