#include <bits/stdc++.h>
using namespace std ;


int32_t main(){	
	int t ;
	cin >> t ;
	while(t--){
	int a[3] ;
	cin >> a[0] >> a[1] >> a[2] ;
	sort(a,a+3) ;
	if(a[1] == a[2]){
		cout << 2*max(0,a[1]-a[0]-2) ;
	}
	else if(a[0] == a[1]) {
		cout << 2*max(0,a[2]-a[1]-2) ;
	}else{
		cout << max(0,a[1]-a[0]-1) + max(0,a[2]-a[1]-1)
			 + max(0,a[2]-a[0]-2) ;
	}
	cout << endl ;
	}
	return 0 ;
}

