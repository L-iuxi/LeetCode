/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
   struct ListNode* t = NULL;
   struct ListNode* p = head;
   while(p != NULL)
   {
    struct ListNode* q = p->next;
    p->next = t;
    t = p;
    p = q;

   }

  
    return t;
}