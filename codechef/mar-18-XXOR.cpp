#include <cstdio>
#include <algorithm>
#include<math.h>
using namespace std;
typedef long long int lli;int x,y;

struct SegmentTreeNode {
	int a[31];//int num;
	
	void assignLeaf(int value) {
		//num=value;
		for(int i=0;i<31;i++)
		{
			a[i]=value%2;
			value=value/2;
		}
	}
	
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		for(int i=0;i<31;i++){
			a[i]=left.a[i]+right.a[i];
		}
	}
	
	lli getValue() {
		lli sum=0;
		int ch=(y-x+1)/2;ch+=(y-x+1)%2;
		for(int i=0;i<31;i++){
			if(a[i]<ch) sum+=pow(2,i);
		}
		return sum;
	}
};

template<class T, class V>
class SegmentTree {
	SegmentTreeNode* nodes;
	int N;
	
public:
	SegmentTree(T arr[], int N) {
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr, 1, 0, N-1);
	}
	
	~SegmentTree() {
		delete[] nodes;
	}
	
	V getValue(int lo, int hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}
	
	void update(int index, T value) {
		update(1, 0, N-1, index, value);
	}
	
private:	
	void buildTree(T arr[], int stIndex, int lo, int hi) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
	
	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
		if (left == lo && right == hi)
			return nodes[stIndex];
			
		int mid = (left + right) / 2;
		if (lo > mid)
			return getValue(2*stIndex+1, mid+1, right, lo, hi);
		if (hi <= mid)
			return getValue(2*stIndex, left, mid, lo, hi);
			
		SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
		SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
		SegmentTreeNode result;
		result.merge(leftResult, rightResult);
		return result;
	}
	
	int getSegmentTreeSize(int N) {
		int size = 1;
		for (; size < N; size <<= 1);
		return size << 1;
	}
	
	void update(int stIndex, int lo, int hi, int index, T value) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(value);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		if (index <= mid)
			update(left, lo, mid, index, value);
		else
			update(right, mid+1, hi, index, value);
		
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};

int main() {
	int N, i, A[100005], M,q;
	
	scanf("%d %d", &N,&q);
	for (i = 0; i < N; ++i)
		scanf("%d", &A[i]);
	SegmentTree<int,int> st(A, N);
	
	for (i = 0; i < q; ++i) {
		scanf("%d %d", &x, &y);
			printf("%d\n", st.getValue(x-1, y-1));
	}	
	
	return 0;
}
