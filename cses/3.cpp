#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ;
	cin >> s ;
	int ans = 1 ;
	int cur = 1 ;
	for(int i = 1 ; i < s.size() ; i++){
		if(s[i] == s[i-1]) cur++ ;
		else cur = 1 ;
		ans = max(cur , ans) ;
	}
	cout << ans ;
	return 0 ;
}

