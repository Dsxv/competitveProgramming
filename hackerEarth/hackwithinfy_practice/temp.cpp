#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < (1<<n) ; i++){
		for(int j = 0 ; j < n ; j++){
			if(((1<<j)&i)) cout << a[j] <<" " ;
		}
		cout << endl ;
	}
	return 0 ;
}

