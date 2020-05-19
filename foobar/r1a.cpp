#include <bits/stdc++.h>
using namespace std ;

#define int long long

string solution(string& s){
	for(auto &i : s)
		if(i >= 'a' && i <= 'z')
			i = char('z' + 'a' - i) ;
	return s ;
}

int32_t main(){
	string s ;
	getline(cin,s) ;
	cout << solution(s) ;
	return 0 ;
}

