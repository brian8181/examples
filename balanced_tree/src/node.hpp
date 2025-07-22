#ifndef __node_HPP
#define __node_HPP

template<class T>
class node
{
public:
	node() : _parent(0), _left(0), _right(0) {	}

	node (node<T>* parent ) : _parent(parent), _left(0), _right(0) {	}

	node(node<T>* parent, node<T>* left, node<T>* right ) : _parent(parent), _left(_left), _right(_right) {	}

	node( const node<T>& n ) : _parent(n._parent), _left(n._left), _right(n._right)	{ }

	virtual ~node()	{	}

	bool operator<( const node<T>& that )
	{
		return *this->_value < that._value;
	}

	T get_value()
	{
		return _value;
	}

	void set_value(T& n)
	{
		_value = n;
	}

	node<T>* get_parent()
	{
		return _parent;
	}

	void set_parent(const node& n)
	{
		_parent = n;
	}

	node<T>* get_left()
	{
		return _left;
	}

	void set_left(const node& n)
	{
		_left = n;
	}

	node<T>* get_right()
	{
		return _right;
	}

	void set_right(const node& n)
	{
		_right = n;
	}

private:
	node<T>* _parent;
	node<T>* _left;
	node<T>* _right;
	T _value;
};

#endif
