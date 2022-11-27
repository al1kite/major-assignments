#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include <stdlib.h> 

int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);

	int* c = (int*)malloc(sizeof(int) * n);
	int remain = 0;
	int i = 0;
	int flag = 1;
	while (n > 0) {
		remain = n % k;
		n /= k;
		c[i] = remain;
		i++;
	} 
	for (int j = 0; j < i / 2; j++)
		if (c[i - j - 1] != c[j])
			flag = 0;
	printf("%d", flag); 
}

/*
* 
    # �Ű����� decimal�� ���� ���� 10���� ���� 2���� ������ ��ȯ�� ���� ��ȯ
    digit = ""  # ��ȯ�� 2���� ���� ������ ����

    while decimal > 0:
        remainder = decimal % 2
        decimal = decimal // 2
        digit = str(remainder) + digit

    return digit
*/