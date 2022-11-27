void pick(int n, int* bucket, int bucketSize, int k) //서로 다른 물건들 중 몇 가지 대상을 뽑아 일렬로 나열하는 것. 순서 생각 o
{
	int i, lastIndex, smallest, item;
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d", bucket[i]);
		printf("\n");
		return;
	}
	lastIndex = bucketSize - k - 1;
	smallest = 0;
	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		pick(n, bucket, bucketSize, k - 1);
	}
}