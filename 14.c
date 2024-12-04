/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p = head;
    struct ListNode *dummy = malloc(sizeof(struct ListNode ));
    dummy->next = head;
    struct ListNode *result = dummy;
    if(p == NULL)
    {
        return NULL;
    }
    int sum = 0;
    int i = 0;
    while(p)
    {
        sum++;
        p = p->next;
    }
    p = head;
    while(p)
    {
        if(i == sum - n)
        {
            result->next = p->next;
            free(p);
            break;
        }else{
     
        result = result->next;
        p = p->next;
        }
        i++;
    }

    return dummy->next;
}