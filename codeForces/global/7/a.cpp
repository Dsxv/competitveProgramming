#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		if(n == 1) {cout << -1 << endl ; continue ;}
		int arr[2] = {2,4} ;
		cout << 2 ;
		for(int i = 0 ; i < n-2; i++) cout << arr[i%2] ;
		cout << 3 << endl; 
	}
	return 0 ;
}

