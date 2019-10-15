#include <iostream>
using namespace std;

int main() {
	int t ;
	cin >> t ;
	while(t--){
		int s , t , e ;
		cin >> s >> t >> e ;
		cout << max(0,(s-t+e)/2) << '\n';
	}
	return 0;
}

