"""
876. 链表的中间结点（简单）

给你单链表的头结点 head ，请你找出并返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。
- 链表的结点数范围是 [1, 100]
- 1 <= Node.val <= 100
"""


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
# 快慢指针，快指针行进永远是慢指针的两倍，快指针走完慢指针走一半
def middleNode(head: ListNode):
    fast, slow = head, head
    # 快指针和快指针的下一个节点都不为零，考虑到两个中间值的问题
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow


# 链表转为列表
def tolist(head: ListNode):
    res = []
    while head:
        res.append(head.val)
        head = head.next
    return res


a = creat_linklidt_tail([1, 2, 3, 4, 5])  # a即是链表的头部
b = tolist(a)

# 打印列表
for i in range(len(b)):
    print(b[i])

print("链表的中间值为", middleNode(a).val)
print("链表的头部为", a.val)
