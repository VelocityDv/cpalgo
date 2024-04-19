// slidingwindow
#include <bits/stdc++.h>



int solve(vector<int> prices, int budget){

	int ans = 0;
	int cur = 0;
	int right = 0;
	int left = 0;
	while(right < prices.size()){
		if(prices[right] + cur == budget){
			ans = max(ans, right-left+1);
			right++;
		}
		else if(prices[right] + cur < budget){
			cur += prices[right];
			right++;
		}
		else{
			cur -= prices[left];
			left++;
		}

	}

	return ans;
}

int main(){

	

}