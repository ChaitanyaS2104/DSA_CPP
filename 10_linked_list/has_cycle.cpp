/*
- Checks whether a linked list contains a cycle.
- Uses the slow and fast pointer technique.
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int value)
    {
        val = value;
        next = nullptr;
    }
};

ListNode *buildList(const vector<int> &arr);
bool hasCycle(ListNode *head);

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = buildList(values);

    head->next->next->next->next->next = head->next->next;

    cout << (hasCycle(head) ? "Cycle detected" : "No cycle") << endl;
    return 0;
}

ListNode *buildList(const vector<int> &arr)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int x : arr)
    {
        ListNode *newNode = new ListNode(x);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}
