//서로 다른 물건들 중 몇 가지 대상을 뽑아 일렬로 나열하는 것. 순서 생각 o
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
        //item이 나왔나를 점검하고 나오지 않았으면. 이미 뽑혔는지를 검사
        //그것을 bucket에 넣고 재귀로 pick을 부른다.
        int flag = 0;
        for (j = 0; j <= lastIndex; j++)
            if (picked[j] == i)
                flag = 1;
        if (flag == 1) continue;
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1);
    }
}
