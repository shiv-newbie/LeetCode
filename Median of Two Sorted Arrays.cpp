class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> nums3;
        int i=0,n1=0,n2=0;
        int len=nums1.size()>nums2.size()?nums1.size():nums2.size();
        while(i<nums2.size()+nums1.size()){
            if(n1<nums1.size() && n2<nums2.size()){
                nums1.at(n1)<nums2.at(n2)?nums3.push_back(nums1.at(n1++)):nums3.push_back(nums2.at(n2++));
            }else if(n1<nums1.size()){
                nums3.push_back(nums1.at(n1++));
            }else if(n2<nums2.size()){
                nums3.push_back(nums2.at(n2++));
            }
            i++;
        }

        if(nums3.size()%2==1){
            return nums3.at(int(nums3.size()/2));
        }else{
            return (nums3.at(int(nums3.size()/2)-1)+nums3.at(int(nums3.size()/2)))/2;
        }

    }
};
