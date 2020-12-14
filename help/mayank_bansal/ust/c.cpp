#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s , t ;
	cin >> s >> t ;
	int a[26] = {} , b[26] = {} ;
	for(auto i : s) a[i - 'a']++ ;
	for(auto i : t) b[i - 'a']++ ;
	int ans = 0 ;
	for(int i = 0 ; i < 26 ; i++){
		ans += a[i] * b[i] ;
	}
	cout << ans ;
	return 0 ;
}

