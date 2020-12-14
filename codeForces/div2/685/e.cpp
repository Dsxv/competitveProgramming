#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	map<int , int> mp ;
	bool found = false ;
	for(int i = 1 ; i < n ; i++){
		cout << "XOR " << 1 << " " << i + 1 << endl ;
		cin >> a[i] ;
		if(found) continue ;
		if(mp.count(a[i])){
			int id = mp[a[i]] , val ;
			cout << "OR " << id + 1 << " " << i + 1 << endl ;
			cin >> val ;
			a[0] = val ^ a[i] ;
			found = true ;
		}
		mp[a[i]] = i ;
	}
	if(!found){
		int id1 = 1 , id2 = 1 ;
		for(int i = 1 ; i < n ; i++) if(a[i] == 1) id1 = i ;
		for(int i = 1 ; i < n ; i++) if(a[i] == 2) id2 = i ;
		int x1 , x2 ;
		cout << "OR " << 1 << " " << id1 + 1 << endl ;
		cin >> x1 ;
		cout << "OR " << 1 << " " << id2 + 1 << endl ;
		cin >> x2 ;
		a[0] = x1 ;
		a[0] /= 2 ;
		a[0] = a[0]*2 + (x2 % 2) ;
	}
	for(int i = 1 ; i < n ; i++) a[i] = a[i] ^ a[0] ;
	cout << "! " ;
	for(int i = 0 ; i < n ; i++) cout << a[i] << " " ;
	cout << endl ;
	return 0 ;
}

