typedef int Rank;
# define DEFAULT_CAPACITY 3
#include<stdlib.h>
template <typename T> class Vector
{
protected:
	Rank _size; int _capacity; T* _element;
	void copyFrom(T const* A, int lo, int hi);
	void expand();
	void shrink();
	void swap(T&, T&);
	void unsort() {
		unsort(0, _size);//整体置乱
	}
	void unsort(Rank lo, Rank hi);
	Rank bubble(Rank lo, Rank hi) {
		Rank last = lo;
		while (++lo<hi)
		{
			if (_element[lo - 1] > _element[lo]){
				swap(_element[lo], _element[lo - 1]);
				last = lo;
			}
		}
		return last;
	}
	void bubbleSort(Rank lo,Rank hi) {
		while (lo<hi)
		{
			hi = bubble(lo, hi);
		}

	}
	

public:
	Vector(int c = DEFAULT_CAPACITY, int s = 0,T v = 0) {
		_element = new T[_capacity = c];
		for (_size = 0; _size < s; _element[_size++] = v);
	}
	Vector(T const* A ,Rank lo, Rank hi) {
	
		copyFrom(A, lo, hi);
	
	}

	~Vector() {
		delete[] _element;
	}
	//只读访问接口
	void merge(Rank lo, Rank  mi, Rank hi);
	void mergeSort(Rank lo, Rank hi);
	Rank size() const {
		return _size;
	}
	T& operator[](Rank r) const {
		return _element[r];
	}
	static Rank binSearch(T* A, T const& e, Rank  lo, Rank  hi);
	Rank search(T const & e) const{  //有序向量整体查找
		return (0>=_size)?-1:search(e, (Rank)0,(Rank)_size);
	}
	Rank search(T const & e,Rank lo,Rank hi) const{//有序向量整体查找
			
		//return (rand() % 2) ? binSearch(_element, e, lo, hi) : fibSearch(_element, e, lo, hi);
		return binSearch(_element, e, lo, hi);
	}
	int disordered() const ;
	
	//读写访问接口
	Vector<T>& operator=(Vector<T> const& V) {
		if (_element) { delete[] _element; }
		copyFrom(V._element, 0, V.size());

	}
	
	Rank insert(Rank r, T const& e) {
			expand();
		for (int i = _size; i > r; i--)
		{
			_element[i] = _element[i - 1];
		}
		_element[r] = e;
		_size++;
		return r;
	}

	Rank insert(T const& e) {
		return insert(_size, e);
	}

	int remove(Rank lo, Rank hi);//区间移除
	T remove(Rank r);//删除秩为r的元素
	int deduplicate();//无序向量去重
	int uniquify();
};
template <typename T>
void Vector<T>::copyFrom(T const* A, int lo, int hi) {
	_element = new T[_capacity = 2 * (hi - lo)];
	_size = 0;
	while (hi > lo)
	{
		_element[_size++] = A[lo++];
	}

}

template<typename T> void Vector<T>::expand() {
	if (_size < _capacity) return;
	if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
	T* _oldelement = _element;
	_element = new	T[_capacity <<= 1];
	for (int i = 0; i < _size; i++)
	{
		_element[i] = _oldelement[i];
	}
	delete[] _oldelement;

}
template<typename T>
void Vector<T>::shrink() {
	if (_capacity < DEFAULT_CAPACITY << 1) return;//不至于缩容之后小于默认容量以下
	if (size << 2 > _capacity)return;//size大于容量的25%不缩容
	T* _oldelement = _element;
	_element = new T[_capacity >>= 1];
	for (int i = 0; i < size; i++)
	{
		_element[i] = _oldelement[i];
	}
	delete[] _oldelement;

}
template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi) {
	T* V = _element + lo;
	for (int i = hi - lo; i > 0; i--)
	{
		swap(V[i - 1], V[rand() % i]);
	}

}

template<typename T>
void Vector<T>::swap(T& v1, T& v2)
{
	T temp = v1;
	v1 = v2;
	v2 = temp;

}

template<typename T>
int Vector<T>::remove(Rank lo,Rank hi) {
	while (hi<_size)
	{
		_element[lo++] = _element[hi++];
	}
	size = lo;
	return  hi - lo;
}
template<typename T>
T Vector<T>::remove(Rank r) {
	T e = _element[r];
	remove(r, r + 1);
	return e;
}

template<typename T>
int Vector<T>::deduplicate()
{
	int oldsize = _size;
	int i = 1;
	(find(_element[i], 0, i) < 0) ? i++ : remove(i);
	return oldsize - _size;
	
}
template<typename T>
int Vector<T>::disordered() const {
	int n = 0;
	for (int i = 1; i < _size; i++)
	{
		n += (_element[i - 1] > _element[i]);
	}
	return n; 
	
}
template <typename T>
int Vector<T>::uniquify() {
	int oldsize = _size;
	int i = 0; int j = 0;
	while (++j<_size)
	{
		if (_element[i] != _element[j])
			_element[++i] = _element[j];
	}
	_size = ++i;//size是长度，i是数组下标，所以要++
	return oldsize - _size;

}

 template<typename T>
 static Rank Vector<T>::binSearch(T* A, T const& e, Rank lo, Rank hi)
 {
	 
	 while (lo<hi)
	 {
		 Rank mi = (lo + hi) >> 1;
		 (e <  A[mi]) ? hi = mi : lo = mi + 1;
	 }
	 return --lo;
 }

 template<typename T>
 void Vector<T>:: mergeSort(Rank lo, Rank hi) {
	 if (hi - lo < 2) return;
	 Rank mi = lo + hi >> 1;
	 mergeSort(lo, mi);
	 mergeSort(mi, hi);
	 merge(lo, mi, hi);
 
 
 }
 template<typename T>
 void Vector<T>::merge(Rank lo,Rank mi,Rank hi){
	 T* A = _element + lo;
	 int lb = mi - lo;
	 T* B = new T[lb];
	 for (int i = 0; i < lb; i++)
	 {
		 B[i] = A[i];
	 }
	 T* C = _element + mi;
	 int lc = hi - mi;


	 for ( int i = 0,j=0,k=0; j<lb; )
	 {
		 if ((k < lc) && C[k] <= B[j])A[i++] = C[k++];
		 if (lc <= k || B[j] < C[k])A[i++] = B[j++];
	 }
		
 
 }