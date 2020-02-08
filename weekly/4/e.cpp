#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;	
	int sum = 0 ;
	for(int i = 1 ; i  <= n ; i++){
		sum += (1LL<<(i)) ;
	}
	cout << sum ;
	return 0 ;
}

