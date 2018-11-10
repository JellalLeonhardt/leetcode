int connect(char* a, char* b) {	//判断是不是只有一个不同
	int i, c = 0;
	for (i = 0; a[i] != '\0'; i++) {
		if (a[i] != b[i])c++;
	}
	if (c == 1) return 1;
	else return 0;
}
int minMutation(char* start, char* end, char** bank, int bankSize) {
	if (bankSize == 0)return -1;
	int dist[bankSize];
	int flag = 0, end_lab;;
	for (int i = 0; i<bankSize; i++) {
		if ((!flag) && strcmp(bank[i], end) == 0) {
			end_lab = i;
			flag = 1;
		}
	}
	if (flag == 0)return -1;
	memset(dist, bankSize + 1, sizeof(dist)); //这个地方实际的dist[i]可能会远大于bankSize 不过并不影响什么
	int q[bankSize], head = 0, tail = 0; //q为不带循环的静态队列，因为大小可确定
	for (int i = 0; i<bankSize; i++) {
		if (connect(start, bank[i]) == 1)
		{
			dist[i] = 1;
			q[tail] = i;
			tail++;

		}
	}
	while (head != tail&&dist[end_lab]>bankSize) {	//因为是广搜，所以我之前担心的会错过更佳的路径其实是没有必要的，只用一个dist足矣
													//算法上没什么好说的，dist用来记录经过bank[i]时已有的点数，大于bankSize说明没经过
													//静态队列记录已经经过的点，已经看过的点没必要再看，所以直接head++直到队尾就ok了
													//内存for循环则是用来寻找当前的q[head]的下一个节点，找到了就加入队尾
		for (int i = 0; i<bankSize; i++) {
			if (dist[i]>bankSize&&connect(bank[i], bank[q[head]]) == 1)
			{
				dist[i] = 1 + dist[q[head]];
				q[tail] = i;
				tail++;
			}
		}
		head++;
	}
	if (dist[end_lab] <= bankSize)return dist[end_lab];
	else return -1;
}