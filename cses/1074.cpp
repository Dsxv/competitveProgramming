#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	sort(a,a+n) ;
	int x = a[n/2] ;
	int sum = 0 ;
	for(int i = 0 ; i < n ; i++){
		sum += abs(a[i] - x) ;
	}
	cout << sum ;
	return 0 ;
}

