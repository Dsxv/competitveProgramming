#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	sort(a,a+n) ;
	int sf = accumulate(a,a+n-1,0LL) ;
	if(sf < a[n-1]){
		cout << 2*a[n-1] ; // sum(1..n) + (a[n] - sum(1..n-1)) 
	} else {
		cout << sf + a[n-1] ;
	}
	return 0 ;
}

