#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	vector<int> v = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575 } ;
	cout << accumulate(v.begin() , v.end() , 0LL) ;
	return 0 ;
}

