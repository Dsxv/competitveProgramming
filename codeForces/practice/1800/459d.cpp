#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  
const int N = 1e6 + 10;

struct BIT{
	int n ;
	vector<int> v; 
	BIT(int n){
		this->n = n ;
		v.resize(n) ;
	}
	void update(int ind , int val){
		ind++ ;
		for(int i = ind ; i < n ; i += i&-i){
			v[i] += val ;
		}
	}
	int query(int ind){
		ind++ ;
		int sum = 0 ;
		for(int i = ind ; i > 0 ; i -= i&-i){
			sum += v[i] ;
		}
		return sum ;
	}
} bit(N);
int a[N] ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	// s.order_fo_key for index
	//update(1,2) == increase value at index 1
	// query(x) == sum from 1 to x in BIT
	int n ; cin >> n ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	map<int,int> mp ;
	int pre[n] , suf[n] ;
	for(int i = 0 ; i < n ; i++){
		mp[a[i]]++ ;
		pre[i] = mp[a[i]] ;
	}
	mp.clear() ;
	for(int i = n - 1 ; i >= 0 ; i--){
		mp[a[i]]++ ;
		suf[i] = mp[a[i]] ;
	}
	//for(int i = 0 ; i < n ; i++)
	int ans = 0 ;
	for(int i = n - 1 ; i >= 0 ; i--){
		ans += bit.query(pre[i]-1) ;
		bit.update(suf[i],1) ;
	}
	cout << ans ;
	return 0 ;
}

