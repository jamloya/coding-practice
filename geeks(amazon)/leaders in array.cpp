#include<bits/stdc++.h>
using namespace std;

void leader(vector<int> &nums)
{
	stack<int> s;
	int currMax;
	currMax=nums.back();
	for(int i=nums.size()-1;i>=0;i--)
	{
		if(nums[i]>=currMax)
			{
				s.push(nums[i]);
				currMax=nums[i];	
			}
	}
	while(!s.empty())
		{
			cout<<s.top()<<endl;
			s.pop();
		}
}

int main()
 {
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        int temp;
        cin>>n;
        vector<int> nums;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            nums.push_back(temp);
        }
        leader(nums);
    }
	return 0;
}
