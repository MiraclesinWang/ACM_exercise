struct node{
	int val;
	node * lchild;
	node * rchild;
} rt[maxn];
int num[maxn];

void init()
{
	//假定rt[0]已经建好（全部为0，有m个叶子结点的树）
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

