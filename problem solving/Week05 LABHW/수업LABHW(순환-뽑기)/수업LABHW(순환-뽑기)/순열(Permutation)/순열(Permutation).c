//���� �ٸ� ���ǵ� �� �� ���� ����� �̾� �Ϸķ� �����ϴ� ��. ���� ���� o
void pick(char* items[], int n, int* picked, int m, int toPick) {
    int i, j, lastIndex;

    if (toPick == 0) {
        int picked_index;
        for (i = 0; i < m; i++) {
            picked_index = picked[i];
            printf("%10s", items[picked_index]);
        }
        printf("\n");
        return;
    }

    lastIndex = m - toPick - 1;

    for (i = 0; i < n; i++) {
        //item�� ���Գ��� �����ϰ� ������ �ʾ�����. �̹� ���������� �˻�
        //�װ��� bucket�� �ְ� ��ͷ� pick�� �θ���.
        int flag = 0;
        for (j = 0; j <= lastIndex; j++)
            if (picked[j] == i)
                flag = 1;
        if (flag == 1) continue;
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1);
    }
}
