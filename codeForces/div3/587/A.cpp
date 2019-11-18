#include <bits/stdc++.h>
using namespace std ;

using pii = pair<int,int> ;
using pll = pair<long,long> ;
using umpii = unordered_map<int,int> ;
using mpii = map<int,int> ;

#define f first
#define s second

int32_t main(){
	int n ;
	string s ;
	cin >> n ;
	cin >> s ;
	string ans = "" ;
	int cnt = 0 ;	
	for(int i = 0 ; i < s.size() ; i+=2){
		if(s[i] == s[i+1]){
			if(s[i] == 'a') ans += "ab" ;
			else ans += "ba" ;
		}
		else ans += s.substr(i,2) ;
	}
	for(int i = 0 ; i < s.size() ; i++)
		cnt += s[i] != ans[i] ;
		cout << cnt << endl << ans ;
	return 0 ;
}

