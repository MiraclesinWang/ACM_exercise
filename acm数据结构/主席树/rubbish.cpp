struct node{
	int val;
	node * lchild;
	node * rchild;
} rt[maxn];
int num[maxn];

void init()
{
	//�ٶ�rt[0]�Ѿ����ã�ȫ��Ϊ0����m��Ҷ�ӽ�������
	for(int i = 1; i <= n; i++){
		int l = 1, r = m;
		rt[i].val = rt[i-1].val +1;
		node pos = rt[i];
		while(l != r){
			int mid = (l+r) >> 1;
			if(a[i] <= mid){
				r = mid;
				
			}
		}
	}
}

