#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a , b , n , m ;
		cin >> a >> b >> n >> m ;
		if(m > min(a,b) || (a+b) < (n+m)){
			cout << "No\n" ;
		} else {
			cout << "Yes\n" ;
		}
	}
	return 0 ;
}

