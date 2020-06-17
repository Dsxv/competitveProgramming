#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string a , b ;
	cin >> a >> b ;
	int ca = 0 , cb = 0 ;
	for(int i = 0 ; i < b.size() ; i++){
		ca += a[i] - '0' ;
		cb += b[i] - '0' ;
	}
	int ans = (ca%2 == cb%2) ;
	for(int i = b.size() ; i < a.size() ; i++){
		ca -= a[i-b.size()] - '0' ;
		ca += a[i] - '0' ;
		ans += (ca % 2 == cb % 2) ;
	}
	cout << ans ;
	return 0 ;
}

