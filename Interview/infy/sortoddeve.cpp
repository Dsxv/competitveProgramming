#include <bits/stdc++.h>
using namespace std ;

#define int long long

void sortOddEven(int * a , int n){
	int f = 0  ;
	for(int i = 0 ; i < n ; i++){
		if(a[i]%2){
			swap(a[i] , a[f]) ;
			f++ ;
		}
	}
}

int32_t main(){
	int n;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	sortOddEven(a , n) ;
	for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
	return 0 ;
}

