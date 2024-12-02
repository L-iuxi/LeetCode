/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {

    struct ListNode *p = head;
    if(head == NULL)
    {
        return NULL;
    }
    int n = 0;
    int m = 0;
    while(p)
    {
        n++;
        p = p->next;
    }
    p = head;
    if(n == 1)
    {
        return head;
    }
    while(p)
    {
        m++;
        p = p->next;
        if(m == n/2)
        {
            break;
        }
       
    }
    return p;
}