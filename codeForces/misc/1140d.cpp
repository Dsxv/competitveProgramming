#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int sum = 0 ;
	for(int i = 2 ; i < n ; i++){
		sum += i*(i+1) ;
	}
	cout << sum ;
	return 0 ;
}

