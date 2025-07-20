#ifndef __node_HPP
#define __node_HPP

template<class T>
class node
{
public:
	node() {}

	node( const node& src ) {}

	bool operator<( const node& that ) 
	{
		return false;
	}

	virtual ~node() {}

private:
	node* left;
	node* right;
	T value;
};

#endif
