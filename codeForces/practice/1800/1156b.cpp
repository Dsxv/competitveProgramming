#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string st; 
		cin >> st ;
		int a[26] = {} ;
		for(auto i : st){
			a[i-'a']++ ;
		}
		string s = "" , x = "" ;
		int cnt = 0 ;
		for(int i = 0 ; i < 26 ; i++){
			if(i&1){
				s += string(a[i],'a'+i) ;
			} else {
				x += string(a[i],'a'+i) ;
			}
		}
		
		string ans = s + x ;
		bool found = true ;
		for(int i = 1 ; i < ans.size() ; i++){
			found &= abs(ans[i] - ans[i-1]) != 1 ;
		}
		if(!found) {
			ans = x + s ;
			found = true ;
			for(int i = 1 ; i < ans.size() ; i++){
				found &= abs(ans[i] - ans[i-1]) != 1 ;
			}
		}
		cout << (found?ans:"No answer") << '\n' ;
	}
	return 0 ;
}

