void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int l1 = m-1;
    int l2 = n-1;
    int idx = nums1Size - 1;
    while(l1 >= 0 && l2 >= 0)
    {
        if(nums1[l1] > nums2[l2])
        {
            nums1[idx] = nums1[l1];
            l1--;
        }else{
            nums1[idx] = nums2[l2];
            l2--;
        }
        idx--;
    }

    while(l2 >= 0)
    {
        nums1[idx] = nums2[l2];
        l2--;
        idx--;
    }
        
    }