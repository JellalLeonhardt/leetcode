int connect(char* a, char* b) {	//�ж��ǲ���ֻ��һ����ͬ
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
	memset(dist, bankSize + 1, sizeof(dist)); //����ط�ʵ�ʵ�dist[i]���ܻ�Զ����bankSize ��������Ӱ��ʲô
	int q[bankSize], head = 0, tail = 0; //qΪ����ѭ���ľ�̬���У���Ϊ��С��ȷ��
	for (int i = 0; i<bankSize; i++) {
		if (connect(start, bank[i]) == 1)
		{
			dist[i] = 1;
			q[tail] = i;
			tail++;

		}
	}
	while (head != tail&&dist[end_lab]>bankSize) {	//��Ϊ�ǹ��ѣ�������֮ǰ���ĵĻ������ѵ�·����ʵ��û�б�Ҫ�ģ�ֻ��һ��dist����
													//�㷨��ûʲô��˵�ģ�dist������¼����bank[i]ʱ���еĵ���������bankSize˵��û����
													//��̬���м�¼�Ѿ������ĵ㣬�Ѿ������ĵ�û��Ҫ�ٿ�������ֱ��head++ֱ����β��ok��
													//�ڴ�forѭ����������Ѱ�ҵ�ǰ��q[head]����һ���ڵ㣬�ҵ��˾ͼ����β
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