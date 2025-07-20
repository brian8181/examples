#ifndef __tree_HPP
#define __tree_HPP

class tree
{

public:
	tree();
	tree( const tree& src );
	bool operator<( const tree& that );
	virtual ~tree();

private:

};

#endif
