#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  
 
const int N = 2e5 + 10 ;
const int mod = 1e9 + 7 ;
int BIT[N] ;
int total ;

void print(int * a , int n ){
	for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
	cout << endl ;
}

void update(int ind , int val){
    for(int i = ind ; i <= N ; i += i&-i){
        BIT[i] += val ;
    }
}
 
int query(int ind){
    int sum = 0 ;
    for(int i = ind ; i > 0 ; i -= i&-i){
        sum = (sum +  BIT[i]) % mod ;
    }
    return sum ;
}

void solve(int* a , int* dp , int n){
	for(int i = 0 ; i < n ; i++){
		update(a[i],1) ;
		dp[i] = query(a[i]-1) ;
	}
	for(int i = 0 ; i < N ; i++) BIT[i] = 0 ;
	for(int i = 0 ; i < n ; i++){
		update(a[i],dp[i]) ;
		dp[i] = query(a[i]-1) ;
	}
}

int32_t main(){
	
	// s.order_fo_key for index
	//update(1,2) == increase value at index 1
	// query(x) == sum from 1 to x in BIT
	int n ; cin >> n ;
	int a[n] ;
	ordered_set s ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		s.insert(a[i]) ;
	}
	for(int i = 0 ; i < n ; i++){
		a[i] = s.order_of_key(a[i]) + 1 ;
	}
	int dp1[n] = {} , dp2[n] = {};
	solve(a,dp1,n) ;
	for(int i = 0 ; i < N ; i++) BIT[i] = 0 ;
	reverse(a,a+n) ;
	solve(a,dp2,n) ;
	reverse(dp2,dp2+n) ;
	//print(dp1,n) ;
	//print(dp2,n) ;
	int ans = 0 ;
	int temp[n] ;
	for(int i = 0 ; i < n ; i++){
		temp[i] = (dp1[i]*dp2[i]) % mod ;
		ans =  (ans + temp[i]) % mod ;
	}
	cout << ans ;
	return 0 ;
}

