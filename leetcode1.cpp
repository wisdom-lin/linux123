//given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
    	if(head == NULL)
    		return head;
    	if(k==0)
    		return head;


    	ListNode *p = head;
    	ListNode * pre;
    	while(k>0)
    	{
    		pre = p;
    		p=p->next;
    		k--;
    		if(p==NULL)
    		{
    			p = head;
    		}
    	}

    	if(p==head)
    	{
    		return head;
    	}

    	ListNode * home_pre;
    	ListNode * home = head;
    	while(p!=NULL)
    	{
    		home_pre = home;
    		home= home->next;
    		pre = p;
    		p = p->next;
    	}

    	home_pre->next = NULL;
    	pre->next = head;

    	return home;

    }
};
