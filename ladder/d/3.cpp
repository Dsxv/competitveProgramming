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

int t[4*N] ;

void build(int* a , int v , int tl , int tr, bool l){
	if(tl == tr){
		t[v] = a[tl] ;
	}else{
		int tm = (tl+tr)/2 ;
		build(a, 2*v, tl, tm,!l) ; build(a, 2*v+1, tm+1, tr,!l) ;
		if(l) t[v] = t[2*v] | t[2*v+1] ;
		else t[v] = t[2*v] ^ t[2*v+1] ;
	}
}

int query(int v , int tl , int tr , int l , int r, bool level){
	if(l > r){
		return 0 ;
	}
	if(tl == l && tr == r){
		return t[v] ;
	}
	int tm = (tl + tr) / 2 ;
	int a = query(2*v, tl, tm, l, min(r,tm), !level) ;
	int b = query(2*v + 1 , tm + 1 , tr , max(l,tm+1) , r, !level) ;
	if(level) return a|b ;
	else return a^b ;
}

void update(int v , int tl , int tr , int pos , int new_val , bool l){
	if(tl == tr){
		t[v] = new_val ;
	}else{
		int tm = (tl + tr) / 2 ;
		if(pos <= tm) // left jao
			update(2*v, tl, tm, pos, new_val,!l) ;
		else 
			update(2*v + 1, tm+1, tr, pos, new_val,!l) ;
		if(l) t[v] = t[2*v] | t[2*v+1] ;
		else t[v] = t[2*v] ^ t[2*v+1] ;
	}
}


int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int p ; 
	cin >> p ;
	int n = (1<<p) ;
	int m ; cin >> m ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	build(a,1,0,n-1,p%2) ; // segtree from 1 index
	while(m--){
		int pos , val ;
		cin >> pos >> val ;
		update(1,0,n-1,pos-1,val,p%2) ;
		cout << t[1] << '\n' ;
	}
	return 0 ;
}



