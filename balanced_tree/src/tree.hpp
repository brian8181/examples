#ifndef __tree_HPP
#define __tree_HPP

#include "node.hpp"

template<typename T>
class tree
{

public:
	tree() 
	{
	}

	tree( const node<T>& root )  : _root(root)
	{

	}

	tree( const tree& src ) 
	{

	}

	bool operator<( const tree& that ) 
	{
		return false;
	}

	virtual ~tree() 
	{

	}

	node<T>& get_parent()
	{

	}

	void insert() 
	{

	}

	void remove() 
	{

	}

	void find() 
	{

	}

private:
node<T>* _root;

};

#endif
