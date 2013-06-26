/**
 * accept_test_gen.c++
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>

int main(){
	using namespace std;

	int ln_cnt = 0;
	int n = rand () % 20 +1 ;
	int idx = 0;

	while (ln_cnt < 5){	
		int i;
		int j;
		
		vector<vector<int> > test;
		int b = rand () % (n - 1) + 1;	// number of rules
		while (b > 0){
			i = rand () % n + 1;		//  vertex number
			vector<int> tmp;			// vector for each rule
			tmp.push_back(i);
			int c = rand () % (n - 1) + 1;		// number of dependencies
			while(c > 0){
				j = rand () % n + 1;		// vertex that "i" will depend on
				while(i >= j)
					j = rand () % n + 1; 
				tmp.push_back(j);
				--c;
			}
			test.push_back(tmp);
			++idx;
			--b;
		}
		cout << n << " " << idx << endl;
		++ln_cnt;

		for(int k = 0; k < idx; ++k){
			cout << test[k].at(0) << " " << test[k].size() - 1 << " ";
			for(vector<int>::iterator it = test[k].begin() + 1; it != test[k].end(); ++it){
				cout << *it << " ";
			}
			cout << endl;
			++ln_cnt;
		}
		cout << endl;
		++ln_cnt;
	}
}
