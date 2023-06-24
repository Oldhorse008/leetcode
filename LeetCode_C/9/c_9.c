/*
���۵�9�⣨�򵥣�
����һ������ x ����� x ��һ���������������� true �����򣬷��� false��
��������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
���磬121 �ǻ��ģ��� 123 ���ǡ�
*/

#include <stdio.h>
#include <stdbool.h>

int isPlidrome(int x) {
    int div = 1;
    int left = 0;
    int right = 0;
    if (x < 0)
        return false;
    while (x / div >= 10)
        div *= 10;
    while (x > 0) {
        left = x / div;
        right = x % 10;
        if (left != right)
            return false;
        x = (x % div) / 10;
        div /= 100;
    }
    return true;
}

int main() {
    int x = 121;
    bool res;
    res = isPlidrome(x);
    printf("�Ƿ��ǻ�������%d", res);
}