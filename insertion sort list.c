#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct ListNode
{
    int val;
    struct ListNode *next;
};

// Insertion Sort
struct ListNode* insertionSortList(struct ListNode* head)
{
    // If list is empty or has only one node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Create dummy node
    struct ListNode* temp =
        (struct ListNode*)malloc(sizeof(struct ListNode));

    temp->val = 0;
    temp->next = NULL;

    // curr points to the node currently being processed
    struct ListNode* curr = head;

    while (curr != NULL)
    {
        // Save the next node of original list
        struct ListNode* nextNode = curr->next;

        // Start searching from dummy node
        struct ListNode* prev = temp;

        // Find correct position for curr
        while (prev->next != NULL &&
               prev->next->val < curr->val)
        {
            prev = prev->next;
        }

        // Insert curr between prev and prev->next
        curr->next = prev->next;
        prev->next = curr;

        // Move to next node in original list
        curr = nextNode;
    }

    // First actual node of sorted list
    struct ListNode* sortedHead = temp->next;

    // Delete dummy node
    free(temp);

    return sortedHead;
}

// Create a new node
struct ListNode* createNode(int value)
{
    struct ListNode* newNode =
        (struct ListNode*)malloc(sizeof(struct ListNode));

    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}

// Print linked list
void printList(struct ListNode* head)
{
    struct ListNode* temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->val);

        if (temp->next != NULL)
        {
            printf(" -> ");
        }

        temp = temp->next;
    }

    printf(" -> NULL\n");
}

// Main function
int main()
{
    // Create linked list:
    // 4 -> 2 -> 1 -> 3 -> NULL

    struct ListNode* head = createNode(4);

    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);

    printf("Original List:\n");
    printList(head);

    // Sort the linked list
    head = insertionSortList(head);

    printf("\nSorted List:\n");
    printList(head);

    return 0;
}
