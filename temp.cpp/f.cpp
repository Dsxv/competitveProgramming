#include <bits/stdc++.h>
using namespace std ;

#define int long long

int maxarray(int input1 ,int input2[]){
	int x = *max_element(input2,input2+input1) ;
	if(x <= 0) {
		return x ;
	}
	int ans = 0 , cur = 0 ;
	for(int i = 0 ; i < input1 ; i++){
			cur += input2[i] ;
			if(cur < 0) cur = 0 ;
			ans = max(cur,ans) ;
	}
	return ans ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	cout << maxarray(n,a) ;
	return 0 ;
}

