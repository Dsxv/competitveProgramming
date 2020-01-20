#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ; 
 
#define int long long 
 
typedef tree<int, null_type , less<int> , rb_tree_tag,
            tree_order_statistics_node_update>
        ordered_set  ;  
 
const int N = 3e4 + 20;

struct v{
	int l , r , ind ;
} ;

int BIT[N] ;
int total ;
void update(int ind , int val){
    for(int i = ind ; i <= N ; i += i&-i){
        BIT[i] += val ;
    }
}
 
int query(int ind){
    int sum = 0 ;
    for(int i = ind ; i > 0 ; i -= i&-i){
        sum += BIT[i] ;
    }
    return sum ;
}

bool check(v a , v b){
	return a.r < b.r ;
}

int32_t main(){
	
	// s.order_fo_key for index
	//update(1,2) == increase value at index 1
	// query(x) == sum from 1 to x in BIT
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n; 
	int a[n+1] ;
	for(int i = 0; i < n ; i++) cin >> a[i+1] ;
	int q ; cin >> q ;
	v tp[q] ;
	for(int i = 0 ; i < q ; i++){
		cin >> tp[i].l >> tp[i].r;
		tp[i].ind = i ;
	}
	sort(tp,tp+q,check) ;
	int k = 0 ;
	map<int,int> mp ;
	vector<int> ans(q) ;
	for(int i = 1 ; i <= n ; i++){
		if(mp.count(a[i])){
				update(mp[a[i]],-1) ;
		}
		mp[a[i]] = i ;
		update(i,1) ;
		while(k < q && tp[k].r == i){
			ans[tp[k].ind] = query(i) - query(tp[k].l-1) ;
			k++;
		}
		if(k == q) break ;
	}
	for(auto i : ans) cout << i << "\n" ;
	return 0 ;
}

