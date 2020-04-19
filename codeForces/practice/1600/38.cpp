#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e6 ;
const int mod = 1e9 + 7 ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a,n/2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int32_t main(){
	int x , n ;
	cin >> x >> n ;
	vector<int> v ;
	int l = sqrt(x) ;
	if(x%2 == 0) {
		v.push_back(2) ;
		while(x%2 == 0) x/=2 ;
	}
	for(int i = 3 ; i <= l ; i+=2){
		if(x%i == 0){
			v.push_back(i);
			while(x%i == 0){
				x /= i;
			}
		}
	}
	if(x > 1) v.push_back(x) ;
	int mans = 1 ;
	for(auto i : v){
		int ans = 0 ;
		int temp = n;
		while(temp){
			ans += temp/i ;
			temp /= i ;
		}
		mans = (mans*modexp(i,ans)) % mod ;
	}
	cout << mans ;
	return 0 ;
}

