#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int a, b;
	cin >> a >> b ;
	if(a > b) swap(a,b) ;
	for(int i = 0 ; i < b ; i++) cout << a;
	return 0 ;
}

