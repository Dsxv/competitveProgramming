#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int cnt = 0 ;
	for(int i = 1 ; i <= n ; i++){
		int x ;
		cin >> x ;
		if(i%2 == 0) continue ;
		cnt += (x%2) ;
	}
	cout << cnt ;
	return 0 ;
}

