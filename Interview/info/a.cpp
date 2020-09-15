#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n; 
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n ; i++){
		int id = i ;
		for(int j = i + 1 ; j < n ; j++){
			if(a[j] < a[id]) id = j ;
		}
		swap(a[i] , a[id]) ;
	}
	for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
	return 0 ;
}

