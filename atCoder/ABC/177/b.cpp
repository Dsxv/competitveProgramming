#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string a , b ;
	cin >> a >> b ;
	int ans = INT_MAX ;
	for(int i = 0 ; i < a.size() ; i++){
		int cnt = 0 ;
		if(i + b.size() > a.size()) break ;
		for(int j = i ; j < i + (int)b.size() ; j++){
			cnt += a[j] != b[j - i] ;
		}
		ans = min(cnt , ans) ;
	}
	cout << ans ;
	return 0 ;
}

