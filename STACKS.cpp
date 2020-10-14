#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T, N, val, l, r, m;
	bool found;
	cin>> T;
	for(int i = 0; i < T; i++){
		cin>>N;

		//BIN_SEARCH SHOULD DO
		vector<int> sorted;
		for(int i = 0; i < N; i++) {
			cin>> val;
			if(sorted.size() == 0) sorted.push_back(val);
			else if(sorted[sorted.size()-1] <= val) sorted.push_back(val);
			else if(sorted[0] > val) sorted[0] = val; 
			else {
				l = 1; r = sorted.size() - 1;
				m = (l + r)/2;
				found = false;
				while(!found){
					if(sorted[m - 1] <= val) {
						if(sorted[m] > val) {
							found = true;
							sorted[m] = val;
						}
						else {
							l = m + 1;
							m = (l + r)/2;
						}
					}
					else {
						r = m - 1;
						m = (l + r)/2;
					}
				}
			}
		}
		cout<<sorted.size();
		for(int i = 0; i < sorted.size(); i++) cout<<' '<<sorted[i];
		cout<<'\n';
	}
	return 0;
}

//problem code: STACKS