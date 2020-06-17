#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n;
	int cnt = 0 ;
	while(n){
		cnt += n/5 ;
		n /= 5 ;
	}
	cout << cnt ;
	return 0 ;
}

