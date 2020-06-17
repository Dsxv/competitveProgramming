#include <bits/stdc++.h>
using namespace std ;
 
#define int long long
 
int32_t main(){
	string s ;
	cin >> s ;
	int ch[26] = {} ;
	for(auto i : s){
		ch[i-'A']++ ;
	}
	int oc = -1 ;
	for(int i = 0 ; i < 26 ; i++){
		if(ch[i]&1){
			if(~oc){
				cout << "NO SOLUTION" ;
				return 0 ;
			} 
			oc = i ;
		}
	}
	string sx = "" ;
	for(int i = 0 ; i < 26 ; i++){
		if(i == oc) continue ;
		for(int j = 0 ; j < ch[i] / 2 ; j++) {
			sx += (char)(i + 'A') ;
		}
	}
	string temp = "" ;
	if(~oc) temp = string(ch[oc] , (char)( 'A' + oc)) ;
	string t = sx ;
	reverse(sx.begin() , sx.end()) ;
	cout << t + temp + sx ;
	return 0 ;
}
