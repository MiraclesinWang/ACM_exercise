
#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
	int get_the_res(vector<int>& nums1, vector<int>& nums2){
        int l1 = nums1.size(), l2 = nums2.size();
        if(!l2) return nums1[l1/2];
		if(nums1[0] >= nums2[l2-1]){
    		if(l1 > l2) return nums1[(l1+l2+1)/2-l2-1];
    		else return nums2[(l1+l2+1)/2-1];
		}
		if(nums1[l1-1] <= nums2[0]){
			if(l1 < l2) return nums2[(l1+l2+1)/2-l1-1];
			else return nums1[(l1+l2+1)/2-1];
		}
		if(nums1[(l1+l2+1)/2-1] <= nums2[0]) return nums1[(l1+l2+1)/2-1];
		
		
        int l = 0, r = min((l1+l2+1)/2, l1)-1;
        while(l < r){
        	int mid = (l+r) >> 1, oth = (l1+l2+1)/2-2-mid;
        	//printf("%d %d %d %d\n", l, r, mid, oth);
			if(nums1[mid] == nums2[oth]) return nums1[mid];
			if(nums1[mid] < nums2[oth]){
				if(mid+1 == l1) return nums2[oth];
				else if(nums1[mid+1]>= nums2[oth]) return nums2[oth];
				else l = mid+1;
			}
			else{
				if(oth+1 == l2) return nums1[mid];
				else if(nums2[oth+1] >= nums1[mid]) return nums1[mid];
				else r = mid;
			}
		}
		return 0;

	}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int l1 = nums1.size(), l2 = nums2.size(), tmp;
		if(l1 < l2) swap(l1, l2), swap(nums1, nums2);
		if((l1+l2)%2) return get_the_res(nums1, nums2);
		if(!l2) tmp = nums1[l1-1], nums1.pop_back();
		else{
			if(nums1[l1-1] > nums2[l2-1]) tmp = nums1[l1-1], nums1.pop_back();
			else tmp = nums2[l2-1], nums2.pop_back();
		}
        if(nums1.size() < nums2.size()) swap(nums1, nums2);
		int pre = get_the_res(nums1, nums2);
		nums1.push_back(tmp);nums2.push_back(tmp);
        //printf("%d %d\n", pre, get_the_res(nums1, nums2));
		return (pre+get_the_res(nums1, nums2))/2.0;
    }
};

int main()
{
	Solution a;
	vector <int> nums1, nums2;
	nums2.push_back(4);//nums2.push_back(4);
	nums1.push_back(1); nums1.push_back(2); nums1.push_back(3); nums1.push_back(5);
	double res = a.findMedianSortedArrays(nums1, nums2);	
	printf("%f\n", res);
}

