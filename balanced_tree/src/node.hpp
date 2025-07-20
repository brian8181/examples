#ifndef __node_HPP
#define __node_HPP

class node
{

public:
	node();
	node( const node& src );
	bool operator<( const node& that );
	virtual ~node();

private:

};

#endif
