#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	cout << "LU" ;
	char ch[2] = { 'R' , 'L' } ;
	for(int i = 0 ; i < n - 1 ; i++){
		cout << string(m + 1 , ch[i]) + "U" ;
	}

	return 0 ;
}

