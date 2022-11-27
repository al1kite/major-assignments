void pick(int n, int* bucket, int bucketSize, int k) //서로 다른 n개 중에서 중복을 허용해 r개 뽑기  
{
	int i, lastIndex, smallest, item;
	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d", bucket[i]);
		printf("\n");
		return;
	}
	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex]; // 조합은 +1, 중복조합은 +0. 이 부분만 조합과 차의
	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		pick(n, bucket, bucketSize, k - 1);
	}
}