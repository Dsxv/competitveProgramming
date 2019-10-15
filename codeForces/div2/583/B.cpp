#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	int  b , g , n ;
	cin >> b >> g >> n ;
	int G = min(n,g) , B = min(n,b) ;
	cout << abs(n-G-(B+1)) ;
	return 0;
}

