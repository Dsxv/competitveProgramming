#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int x , y , a , b ;
	cin >> x >> y >> a >> b ;
	int cur = x ;
	int mx = 0 ;
	int i = 0 ;
	while(cur < y){
		mx = max(mx , (y - cur - 1) / b + i);
		i++ ;
		if(cur >= y / a) break ;
		cur *= a ;
	}
	cout << mx ;
	return 0 ;
}

