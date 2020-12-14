#include <bits/stdc++.h>
using namespace std ;

#define int long long

int maxarray(int input1 , int input2[]){
	int sum = -1e9 , maxsum = -1e9 ;
	for(int i = 0 ; i < input1 ; i++){
		if(sum < 0) sum = 0 ;
		sum += input2[i] ;
		if(sum > maxsum) maxsum = sum ;
	}
	return maxsum ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	cout << maxarray(n , a) ;
	return 0 ;
}

