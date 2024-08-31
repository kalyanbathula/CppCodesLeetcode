#include<bits/stdc++.h>
using namespace std;

	int getCost(string &s1) {
		int n = s1.size();
		int cost = 0;
		int chairs = 0;

		for (int i = 0; i < n; i++) {
			if (s1[i] == 'C' || s1[i] == 'U') {
				if (chairs > 0) {
					chairs--;
				} else {
					cost++;
				}
			} else if (s1[i] == 'R' || s1[i] == 'L') {
				chairs++;
			}
		}

		return cost;
	}

	int main() {
	    vector<string> arr={"CRUL"};
		int n = arr.size();
		vector<int> ans(n);

		for (int i = 0; i < n; i++) {
			ans[i] = getCost(arr[i]);
		}
        for(auto it:ans) cout<<it<<" ";
		//return ans;
	}
