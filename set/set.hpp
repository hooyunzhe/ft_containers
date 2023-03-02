#ifndef SET_HPP
# define SET_HPP

# include <iostream>
# include <string>
# include "../RedBlackTree/RedBlackTree.hpp"
# include "../utils/pair.hpp"

using std::cout;
using std::endl;
using std::string;

namespace	ft
{
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class	set {
		public:
			typedef T												key_type;
			typedef T												value_type;
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef Compare											key_compare;
			typedef Compare											value_compare;
			typedef Alloc											allocator_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef value_type*										pointer;
			typedef const value_type*								const_pointer;

			typedef ft::RedBlackTree<value_type, key_compare, Alloc>	tree_type;
			typedef typename tree_type::const_iterator					iterator;
			typedef typename tree_type::const_iterator					const_iterator;
			typedef typename tree_type::const_reverse_iterator			reverse_iterator;
			typedef typename tree_type::const_reverse_iterator			const_reverse_iterator;

			explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
			template <class Iter>
			set(Iter first, Iter last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
			set(const set &set_var);
			~set();
			set	&operator = (const set &set_var);

			allocator_type	get_allocator(void) const;
			tree_type		get_tree(void) const;

			iterator				begin(void);
			const_iterator			begin(void) const;
			iterator				end(void);
			const_iterator			end(void) const;
			reverse_iterator		rbegin(void);
			const_reverse_iterator	rbegin(void) const;
			reverse_iterator		rend(void);
			const_reverse_iterator	rend(void) const;

			bool		empty(void) const;
			size_type	size(void) const;
			size_type	max_size(void) const;

			void						clear(void);
			ft::pair<iterator, bool>	insert(const_reference value);
			iterator					insert(iterator pos, const_reference value);
			template <class Iter>
			void						insert(Iter first, Iter last);
			void						erase(iterator pos);
			void						erase(iterator first, iterator last);
			size_type					erase(const key_type &key);
			void						swap(set &set_var);

			size_type									count(const key_type &key) const;
			iterator									find(const key_type &key);
			const_iterator								find(const key_type &key) const;
			ft::pair<iterator, iterator>				equal_range(const key_type &key);
			ft::pair<const_iterator, const_iterator>	equal_range(const key_type &key) const;
			iterator									lower_bound(const key_type &key);
			const_iterator								lower_bound(const key_type &key) const;
			iterator									upper_bound(const key_type &key);
			const_iterator								upper_bound(const key_type &key) const;

			key_compare		key_comp(void) const;
			value_compare	value_comp(void) const;

		private:
			key_compare		_compare;
			allocator_type	_alloc;
			tree_type		_tree;	
	};
}

# include "set.tpp"

#endif