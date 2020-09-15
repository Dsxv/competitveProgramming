#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct line{
	int m , c ;
	line(){
		m = 0 , c = 0 ;
	}
	line(int x , int y){
		m = x , c = y ;
	}
} ;

int eval(int x , line l){
	return x*l.m + l.c ;
}

long double intersectX(line a , line b){
	return (long double) (b.c - a.c) / (long double) (a.m - b.m) ;
}

vector<long double> points ; // intersectX between lines
vector<line> v ; // current lines

void insert(line l){
	if(v.empty()){
		v.push_back(l) ;
		return ;
	}
	while(points.size() && 
			intersectX(l , v[v.size() - 2]) <= intersectX(v.back() , v[v.size() - 2])){
		v.pop_back() ;
		points.pop_back() ;
	} // at least 1 size of v will remain
	points.push_back(intersectX(l , v.back())) ;
	v.push_back(l) ;
}

int query(int x){
	int id = lower_bound(points.begin() , points.end() , x) - points.begin() ;
	return eval(x , v[id]) ;
}
	
int32_t main(){
	int n ;
	cin >> n ;
	int a[n+1] = {} ;
	int pre[n+1] = {} , sum[n+1] = {} ;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
		sum[i] = sum[i-1] + a[i] ;
		pre[i] = pre[i-1] + a[i]*i ;
	}
	line l ;
	insert(l) ;
	int ans = 0 ;
	for(int i = 1 ; i <= n ; i++){
		ans = max(ans , query(-sum[i]) + pre[i]) ;
		l.m = i ; l.c = i*sum[i] - pre[i] ;
		insert(l) ;
	}
	cout << ans ;
	return 0 ;
}


