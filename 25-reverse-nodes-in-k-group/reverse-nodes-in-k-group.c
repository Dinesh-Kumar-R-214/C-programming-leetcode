struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy, *curr, *next;

    while (1) {
        struct ListNode* tail = prev;
        for (int i = 0; i < k; i++) {
            tail = tail->next;
            if (!tail) return dummy.next;
        }

        curr = prev->next;
        struct ListNode* groupNext = tail->next;

        // Reverse k nodes
        struct ListNode* prevNode = groupNext;
        struct ListNode* node = curr;
        for (int i = 0; i < k; i++) {
            next = node->next;
            node->next = prevNode;
            prevNode = node;
            node = next;
        }

        prev->next = prevNode;
        prev = curr;
    }
}
