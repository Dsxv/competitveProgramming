#include <bits/stdc++.h>
using namespace std ;

#define int long long

int longestVowelSubsequence(string s){
	map<char , char> cp ;
	cp['e'] = 'a' ;
	cp['i'] = 'e' ;
	cp['o'] = 'i' ;
	cp['u'] = 'o' ;
	map<char , int> mp ;
	int ans = 0 ;
	for(auto i : s){
		char prev = cp[i] ;
		if(i == 'a'){
			mp[i]++ ;
			continue ;
		}
		if(mp.count(i)) mp[i] = 1 + mp[i] ;
		if(mp.count(prev)) mp[i] = max(mp[i] , mp[prev] + 1) ;
		if(i == 'u' && mp.count(i)){
			ans = max(ans , mp[i]) ;
		}
	}
	return ans ;
}
	


int32_t main(){
	string s ;
	cin >> s ;
	cout << longestVowelSubsequence(s)  ;
	return 0 ;
}

