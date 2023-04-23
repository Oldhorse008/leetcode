/*
876. 链表的中间结点（简单）

给你单链表的头结点 head ，请你找出并返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。
# 链表的结点数范围是 [1, 100]
# 1 <= Node.val <= 100
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义单链表
struct ListNode {
    int val;
    struct ListNode *next;
};

// 创建单链表
struct ListNode *creList(int *a, int size) {
    struct ListNode *head, *p, *s;
    int i = 0;
    printf("链表的长度为：%d\n", size);
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    p = head;
    for (i = 0; i < size; i++) {
        s = (struct ListNode *)malloc(sizeof(struct ListNode));
        s->val = a[i];
        p->next = s;
        s->next = NULL;
        p = s;
    }
    return head->next;
}

// 返回链表中间值
struct ListNode *middleNode(struct ListNode *head) {
    struct ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    int a[] = {0, 1, 2, 3};
    int n = sizeof(a) / sizeof(int);
    printf("a的长度为：%d\n", n);
    struct ListNode *head, *temp;
    head = creList(a, n);
    printf("链表第一个元素：%d\n", head->val);
    temp = head;
    while (temp) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
    // 打印链表中间值
    printf("链表的中间值为：%d\n", middleNode(head)->val);
    free(head);
}