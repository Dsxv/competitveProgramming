#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	string s; 
	cin >> n >> s;
	for(auto i : s){
		cout << char(((i-'A') + n)%26 + 'A');
	}
	return 0 ;
}

