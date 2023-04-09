# 定义单链表
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# 尾插法定义链表
def creat_linklidt_tail(li):
    head = ListNode(None)
    tail = head
    for element in li:
        node = ListNode(element)
        tail.next = node
        tail = node
    return head.next


# shift+tab整体取消缩进
def middleNode(head: ListNode):
    fast, slow = head, head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow


a = creat_linklidt_tail([1, 2, 3, 4, 5])  # a即是链表的头部
print(middleNode(a).val)
print(a.val)
