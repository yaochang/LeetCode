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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
        	return NULL;
        if(l1 != NULL && l2 == NULL)
        	return l1;
        if(l1 == NULL && l2 != NULL)
        	return l2;
        ListNode* ret = NULL;
        ListNode* cur = NULL;
        while(l1 != NULL || l2 != NULL) {
        	if(ret == NULL) {
        		if(l1->val < l2->val) {
        			ret = l1;
        			cur = ret;
        			l1 = l1->next;
        		}else{
        			ret = l2;
        			cur = ret;
        			l2 = l2->next;
        		}
        		continue;
        	}

        	if(l1 == NULL) {
        		cur->next = l2;
        		return ret;
        	}else if(l2 == NULL) {
        		cur->next = l1;
        		return ret;
        	}else{
        		if(l1->val < l2->val) {
        			cur->next = l1;
        			l1 = l1->next;
        			cur = cur->next;
        		}else{
        			cur->next = l2;
        			l2 = l2->next;
        			cur = cur->next;
        		}
        	}
        }
        return ret;
    }
};