#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e6 ;

void update(int* bit , int val , int ind){
	for(int i = ind ; i < N ; i += i&-i){
		bit[i] += val ;
	}
}

int query(int* bit , int ind){
	int sum = 0 ;
	for(int i = ind ; i ; i -= i&-i){
		sum += bit[i] ;
	}
	return sum ;
}

int32_t main(){
	int bit[N+2] = {} ;
	int q ;
	cin >> q ;
	while(q--){
		int t ;
		cin >> t ;
		if(t == 1){
			int ind , val ;
			cin >> ind >> val ;
			update(bit,val,ind) ;
		} else {
			int ind ;
			cin >> ind ;
			cout << query(bit,ind) << endl;
		}
	}
	return 0 ;
}

