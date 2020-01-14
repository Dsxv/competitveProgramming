#include <bits/stdc++.h>
using namespace std ;

int main(){
	int t ;
	cin >> t ;
	while(t--){
		long long n , temp;
		cin >> n ;
		long long md = pow(10LL,n) ;
		cin >> temp; 
		cout << temp + 2*md << endl;
		cin >> temp;
		cout << md-temp << endl;
		cin >> temp; 
		cout << md-temp << endl;
		cin >> temp;
		if(temp == -1) return 0; // ded
	}
	return 0 ;
}

