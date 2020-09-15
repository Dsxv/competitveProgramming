#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 1e9 + 7 ;
int basis[20] ;
int sz ;
void insert(int x){
	for(int i = 0 ; i < 20 ; i++){
		if((x & 1 << i) == 0) continue ;
		if(basis[i] == 0){
			basis[i] = x ;
			sz++ ;
			return ;
		}
		x ^= basis[i] ;
	}
}

int solve(map<int,int> mp , int n){
	int arr[20] = {} ;
	for(int i = 2 ; i <= sqrt(n) ; i++){
		bool f = mp.count(i) ;
		while(n % i == 0){
			n /= i ;
			if(f) arr[mp[i]]++ ;
		}
	}
	if(n >= 2){
		arr[mp[n]]++ ;
	}
	int ans = 0 ;
	for(int i = 0 ; i < 20 ; i++){
		if(arr[i]%2) ans |= 1 << i ;
	}
	return ans ;
}	

int modexp(int a , int n ){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	map<int,int> mp ;
	int cnt = 0 ;
	for(int i = 2 ; i < 100 ; i++){
		bool ok = true ;
		for(int j = 2 ; j < i; j++){
			if(i%j == 0){
				ok = false ; 
				break ;
			}
		}
		if(ok) mp[i] = cnt++ ;
	}
	for(int i = 0 ; i < n ; i++){
		int x = solve(mp , a[i]) ;
		insert(x) ;
	}
	cout << ( modexp(2 , n - sz) - 1 + mod ) % mod ;
	return 0 ;
}

