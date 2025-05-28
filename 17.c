class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        unordered_set<int> set;
        if(nums1.size() > nums2.size())
        {
        for(int i = 0;i < nums1.size();i++)
        {
            for(int j = 0 ;j < nums2.size();j++)
            {
                if(nums2[j] == nums1[i])
                {
                    set.insert(nums1[i]);
                    
                }
            }
        }
        }else{
               for(int i = 0;i < nums2.size();i++)
        {
            for(int j = 0 ;j < nums1.size();j++)
            {
                if(nums1[j] == nums2[i])
                {
                    set.insert(nums2[i]);
                    
                }
            }
        }
        }
        result.insert(result.end(),set.begin(),set.end());
    return result;
    }

    
};