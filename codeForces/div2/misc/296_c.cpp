#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(set<int>& s , multiset<int>& ms , int x){
	s.insert(x) ;
	auto temp = s.find(x) ;
	auto l = temp , r = temp ;
	l-- ; r++ ;
	int old = (*r - *l) ;
	ms.erase(ms.lower_bound(old)) ;
	ms.insert(*r-x) ;
	ms.insert(x-*l) ;
}

int32_t main(){
	multiset<int> hori , verti ;
	set<int> hr , vr ;
	int w , h , n ;
	cin >> w >> h >> n ;
	hori.insert(w) ;
	verti.insert(h) ;
	hr.insert(0) ; hr.insert(w) ; // created when vertical cut made
	vr.insert(0) ; vr.insert(h) ; // created when horizontal cut made
	while(n--){
		char ch ; int x ;
		cin >> ch >> x ;
		if(ch == 'H') {
			solve(vr,verti,x) ;
		} else {
			solve(hr,hori, x) ;
		}
		int vmax = *verti.rbegin() ;
		int hmax = *hori.rbegin() ;
		cout << vmax*hmax << '\n' ;
	}
	return 0 ;
}

