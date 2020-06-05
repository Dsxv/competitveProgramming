#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int a[26] ;
	for(int i = 0 ; i < 26 ; i++) cin >> a[i] ;
	string s ;
	cin >> s ;
	int n = s.size() ;
	map<int,int> mp[26] ;
	int pre[n] = {} ;
	for(int i = 0 ; i < n ; i++){
		if(i){
			pre[i] += pre[i-1] ;
		}
		pre[i] += a[s[i]-'a'] ;
	}
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(i){
			ans += mp[s[i] - 'a'][pre[i-1]] ;
		}
		mp[s[i] - 'a'][pre[i]]++ ;
	}
	cout << ans ;
	return 0 ;
}

