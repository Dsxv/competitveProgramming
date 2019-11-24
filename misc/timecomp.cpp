#include <bits/stdc++.h>
using namespace std;

void print(double t){
	cout <<fixed <<  setprecision(8) << t/(1e6) << endl ;
}

int main() {
	clock_t s1 , e1 , s2 , e2 ;
	int count = 0 ;
	s1 = clock() ;
	for(int i = 0 ; i < 1e9 ; i++){
		if(i%2) ++count ;
	}
	e1 = clock() ;
	cout << count <<" ";
	print(e1-s1) ;
	count = 0 ;
	s2 = clock() ;
	for(int i = 0 ; i < 1e9 ; i++){
		if(i&1) ++count ;
	}
	e2 = clock() ;
	cout << count <<" ";
	print(e2 - s2) ;
	
	return 0;
}
