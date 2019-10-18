typedef  int Rank;
# define ListNodePosi(T) ListNode<T> *
# define NULL 0
template<typename T>
struct ListNode
{

	T data;//数值
	ListNodePosi(T) pred;//前驱
	ListNodePosi(T) succ;//后继
	//构造函数
	ListNode() {}
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL) :data (e), pred(p),succ(s)
	{}
	//操作接口
	ListNodePosi(T) insertAspred(T const& e);
	ListNodePosi(T) insertAsSucc(T const& e);
};

template<typename T>
ListNodePosi(T) ListNode<T>::insertAspred(T const& e)
{
	ListNodePosi(T) x=	new ListNode(e, pred, this);
	pred->succ = x;  pred = x;
	return x;
}

template<typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e)
{
	ListNodePosi(T) x = new ListNode(e, this, succ);
	succ->pred = x; succ = x;
	return x;
}
