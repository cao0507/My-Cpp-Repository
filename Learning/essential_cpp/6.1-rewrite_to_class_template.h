template <typename elemType>
class example {
public:
	example( elemType &min, elemType &max );
	example( const elemType *array, int size );
	elemType& operator[]( int index );
	bool operator==( const example& ) const;
	bool insert ( const elemType*, int );
	bool insert ( elemType& );
	elemType min() const 	{ return _min; }
	elemType max() const 	{ return _max; }
	void min( elemType& );
	void max( elemType& );
	int count( elemType &value ) const;

private:
	int size;
	elemType *parray;
	elemType _min;
	elemType _max;
};
