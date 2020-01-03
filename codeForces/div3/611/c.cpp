#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ; cin >> n ;
	set<int> s ;
	for(int i = 0 ; i < n ; i++) s.insert(i+1) ;
	int a[n] , b[n] ;
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i] ;
		b[i] = a[i] ;
		if(a[i]) s.erase(a[i]) ;
	}
	for(int i = 0 ; i < n ; i++) {
		if(!a[i]){
			//if(s.size() == 0) cout << "oh" ;
			a[i] = *s.begin() ;
			s.erase(s.begin()) ;
		}
	}
	assert(s.size() == 0) ;
	vector<int> v;
	int x = -1 ;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == i+1){
			v.push_back(i) ;
		}
		if(x == -1 && b[i] == 0 && a[i] != i + 1){
			x = i;
		}
	}
	if(v.size() % 2 && x != -1)  v.push_back(x) ;
	if(v.size() % 2) v.push_back(v[v.size()-2]) ;
	for(int i = 0 ;  i < (int)v.size() - 1 ; i+=2){
		swap(a[v[i]] , a[v[i+1]]) ;
	}
	for(auto i : a) cout << i << " " ;
	return 0 ;
}

