#include <bits/stdc++.h>
using namespace std ;

#define double long double

int32_t main(){
	int n; 
	cin >> n;
	double a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	sort(a,a+n) ;
	if(a[n-1] == 1){
		cout << fixed << setprecision(12) << (double)1 ;
		return 0 ;
	}
	double mx = 0 ; 
	for(int i = n - 1 ; i >= 0 ; i--){
		double prod = 1 , sum = 0 ;
		for(int j = n - 1 ; j >= i ; j--){
			prod *= (1 - a[j]) ;
			sum += a[j]/(1-a[j]) ;
			if(sum >= 1) break ;
		}
		 mx = max(prod*sum , mx) ;
	}
	cout << fixed << setprecision(18) << mx ;
	return 0 ;
}

