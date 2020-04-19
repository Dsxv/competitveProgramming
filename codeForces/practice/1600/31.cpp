#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n;
	double a[n] ;
	int x[n] ;
	bool ok[n] = {} ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		if(a[i] < 0){
			x[i] = (int)a[i] - 1 ;
		}
		if(a[i] > 0){
			x[i] = (int)a[i] ;
		}
		if(abs(a[i] - (int)a[i]) < 1e-9){
			x[i] = a[i] ;
			ok[i] = 1 ;
		}
	}
	int sum = accumulate(x,x+n,0LL) ;
	for(int i = 0 ; i < n ; i++){
		if(sum < 0 && !ok[i]) sum++ , x[i]++ ;
	}
	assert(!sum) ;
	for(auto i : x) cout << i << endl ;
	return 0 ;
}

