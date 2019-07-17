#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct SegmentTreeNode {
	multiset<int>m;
	
	void assignLeaf(int value) {
		m.clear();
		m.insert(value);
	}
	
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		m.clear();
		m.insert(left.m.begin(),left.m.end());m.insert(right.m.begin(),right.m.end());
	}
	
	lli getValue() {int d=0;
		//printf("%d\n",m.size());
		if(m.size()<3) return 0;
		multiset<int>::reverse_iterator rit;lli k=0,s=0,f;
		for(rit=m.rbegin();rit!=m.rend();++rit){k++;
			 if(k>1) s=s+(*rit);if(k==1) f=*rit;
			 if(k==3) {
			 	if(s>f) {d=1;
				 return s+f;}
			 	k=0;s=0;rit--;//printf("%d\n",*rit);
			 }
		}
		if(d==0) return 0;
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
		//	nodes[stIndex].m.erase(nodes[stIndex].m.find(value));
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
	int N, i, A[100005], q, x, y, operation;
	
	scanf("%d %d", &N,&q);
	for (i = 0; i < N; ++i)
		scanf("%d", &A[i]);
	SegmentTree<int,int> st(A, N);
	
	for (i = 0; i < q; ++i) {
		scanf("%d %d %d", &operation, &x, &y);
		if (operation == 1)
			st.update(x-1, y);
		else
			printf("%d\n", st.getValue(x-1, y-1));
	}	
	
	return 0;
}
