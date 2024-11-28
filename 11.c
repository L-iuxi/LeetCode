/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *a = head;
    int len = 0;
    int nums[500001];
    if(head = NULL)
    {
        return NULL;
    }
    while(a!=NULL)
    {
        nums[len] = a->val;
        len++;
        a = a->next;
    }
    for(int i = 0,j = len-1;i < j;i++,j--)
    {
        if(nums[i] != nums[j])
        {
            return false;
        }
    }
    
    return true;
}