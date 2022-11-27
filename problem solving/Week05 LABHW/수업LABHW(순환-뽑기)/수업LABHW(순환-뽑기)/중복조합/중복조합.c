void pick(int n, int* bucket, int bucketSize, int k) //���� �ٸ� n�� �߿��� �ߺ��� ����� r�� �̱�  
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
		smallest = bucket[lastIndex]; // ������ +1, �ߺ������� +0. �� �κи� ���հ� ����
	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		pick(n, bucket, bucketSize, k - 1);
	}
}