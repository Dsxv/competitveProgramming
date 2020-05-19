#include <bits/stdc++.h>
using namespace std ;

pair<int,int> solution(vector<int>& pegs){
	if(pegs.size() == 2){
		int d = pegs[1] - pegs[0] ;
		if(d*2 < 3) return {-1,-1};
		int x =  __gcd(2*d,3LL) ;
		return {2*d/x,3/x} ;
	}
	int x = 0 , b = pegs.size() - 2;
	for(int i = 1 ; i < pegs.size() - 1 ; i++){
		x += pegs[i] ;
	}
	int r = 4*x - 2*b*(pegs[0] + pegs.back()) ;
	double rad = (double)r/b ;
	double f = rad ;
	if(rad < 1) return {-1,-1} ;
	for(int i = 1 ; i < pegs.size() ; i++){
		double crad = pegs[i] - (pegs[i-1] + rad) ;
		if(crad < 1) return {-1,-1} ;
		rad = crad ;
	}
	if(abs(2*rad-f) > 1e-9) return {-1,-1} ;
	int gc = __gcd(r,b) ;
	return {r/gc,b/gc} ;
}

int32_t main(){
	int n ;
	cin >> n;
	vector<int> pegs(n) ;
	for(auto &i : pegs) cin >> i ;
	pair<int,int> ans = solution(pegs) ;
	cout << ans.first << " " << ans.second ;
	return 0 ;
}

