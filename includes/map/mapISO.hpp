// template <class Key, class T, class Compare = less<Key>,
// class Allocator = allocator<pair<const Key, T> > >
// class map {
// public:
// // types:
// // typedef Key key_type;
// // typedef T mapped_type;
// // typedef pair<const Key, T> value_type;
// // typedef Compare key_compare;
// // typedef Allocator allocator_type;
// // typedef typename Allocator::reference reference;
// // typedef typename Allocator::const_reference const_reference;
// // typedef implementation defined iterator; // See 23.1
// // typedef implementation defined const_iterator; // See 23.1
// // typedef implementation defined size_type; // See 23.1
// // typedef implementation defined difference_type;// See 23.1
// // typedef typename Allocator::pointer pointer;
// // typedef typename Allocator::const_pointer const_pointer;
// typedef std::reverse_iterator<iterator> reverse_iterator;
// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;


// T& operator[](const key_type& x);

// iterator find(const key_type& x);
// const_iterator find(const key_type& x) const;
// size_type count(const key_type& x) const;
// iterator lower_bound(const key_type& x);
// const_iterator lower_bound(const key_type& x) const;
// iterator upper_bound(const key_type& x);
// const_iterator upper_bound(const key_type& x) const;
// pair<iterator,iterator>
// equal_range(const key_type& x);
// pair<const_iterator,const_iterator>
// equal_range(const key_type& x) const;
// };
// template <class Key, class T, class Compare, class Allocator>
// bool operator==(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator< (const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator!=(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator> (const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator>=(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator<=(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// // specialized algorithms:
// template <class Key, class T, class Compare, class Allocator>
// void swap(map<Key,T,Compare,Allocator>& x,
// map<Key,T,Compare,Allocator>& y);