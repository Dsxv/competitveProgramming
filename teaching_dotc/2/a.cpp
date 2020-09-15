#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s; 
	cin >> s ;
	int cnt = 0 ;
	for(auto i : s){
		if(isupper(i)) cnt++ ;
	}
	if(cnt == s.size()){
		for(auto &i : s){
			if(isupper(i))
				i = tolower(i) ;
			else 
				i = toupper(i) ;
		}
	} else if(cnt == (s.size() - 1) && islower(s[0])){
		for(auto &i : s){
			if(isupper(i))
				i = tolower(i) ;
			else 
			 	i = toupper(i) ;
		}
	}
	cout << s ;
	return 0 ;
}

