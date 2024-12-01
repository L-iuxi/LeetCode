/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode* temp[40001];
    struct ListNode* p = head;
    int i = 0;
    if(head == NULL)
    {
        return ;
    }
    while(p)
    {
        temp[i] = p;
        p = p->next;
        i++;
    }
    int right = i-1;
    int left = 0;
    while(right > left)
    {
        temp[left]->next = temp[right];
        left++;
        temp[right]->next = temp[left];
        right--;

    }
    temp[left]->next = NULL;

}