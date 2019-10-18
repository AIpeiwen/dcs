#include "ListNode.cpp"
template <typename T>
class List
{
protected:
	void  init();//列表创建时的初始化
	int clear();
	void copyNodes(ListNodePosi(T) p, int n);
public:
	List();
	
	~List();
	T& operator[](Rank r);
	
	ListNodePosi(T) first();
	ListNodePosi(T) last();
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p);//无序向量查找
	ListNodePosi(T) insertAsfirst(T const& e);
	ListNodePosi(T) insertAslast(T const& e);
	ListNodePosi(T) insertBefore(T const & e,ListNodePosi(T) p);
	ListNodePosi(T) insertAfter(T const& e, ListNodePosi(T) p);
private:
	int _size;
	ListNodePosi(T) header;
	ListNodePosi(T) trailer;

};
template<typename T>
List<T>::List()
{
	init();
}
template<typename T>
List<T>::~List()
{

}

template<typename T>
void List<T>::init()
{
	header  = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer; header->pred = NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0;


}

template<typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n)
{
	init();
	ListNodePosi(T) q;
	q =this.header;
	while (0<n--)
	{
		insertAslast(p->data);
		p = p->succ;
	}
}
template<typename T>
T& List<T>::operator[](Rank r)
{
	ListNodePosi(T) p = first();
	while (0 < r--) {
		p = p->succ; 
	}
	return p->data;
}
template<typename T>
ListNodePosi(T) List<T>::first()
{
	return header->succ;
}

template<typename T>
ListNodePosi(T) List<T>::last()
{
	return trailer->pred;
}

template<typename T>
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p)
{
	while (0<n--)
	{
		if (e == (p = p->pred)->data) {
			return p;
		}
	}
	return NULL;
}

template<typename T>
ListNodePosi(T) List<T>::insertAsfirst(T const& e)
{
	_size++;
	return header->insertAsSucc(e);
}

template<typename T>
ListNodePosi(T) List<T>::insertAslast(T const& e)
{
	_size++;
	return trailer->insertAspred(e);
}

template<typename T>
ListNodePosi(T) List<T>::insertBefore(T const& e, ListNodePosi(T) p)
{
	_size++;
	return p->insertAspred(e);
	
}

template<typename T>
ListNodePosi(T) List<T>::insertAfter(T const& e, ListNodePosi(T) p)
{
	_size++;
	return p->insertAsSucc(e);
}
