#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include "../RedBlackTree/RedBlackTree.hpp"
# include "../utils/pair.hpp"

using std::cout;
using std::endl;
using std::string;

namespace	ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class	map {
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const Key, T>							value_type;
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef value_type*										pointer;
			typedef const value_type*								const_pointer;

			class value_compare : std::binary_function<T, T, bool> {
				public:
					value_compare(Compare c) : comp(c) {};
					bool	operator()(const value_type &value_left, const value_type &value_right) const {
						return (comp(value_left.first, value_right.first));
					};

				protected:
					Compare	comp;
			};

			typedef ft::RedBlackTree<value_type, value_compare, Alloc>	tree_type;
			typedef typename tree_type::iterator						iterator;
			typedef typename tree_type::const_iterator					const_iterator;
			typedef typename tree_type::reverse_iterator				reverse_iterator;
			typedef typename tree_type::const_reverse_iterator			const_reverse_iterator;

			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
			template <class Iter>
			map(Iter first, Iter last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
			map(const map &map_var);
			~map();
			map	&operator = (const map &map_var);

			allocator_type	get_allocator(void) const;
			tree_type	get_tree(void) const;

			mapped_type	&at(const key_type &key);
			const mapped_type	&at(const key_type &key) const;
			mapped_type	&operator [] (const key_type &key);

			iterator	begin(void);
			const_iterator	begin(void) const;
			iterator	end(void);
			const_iterator	end(void) const;
			reverse_iterator	rbegin(void);
			const_reverse_iterator	rbegin(void) const;
			reverse_iterator	rend(void);
			const_reverse_iterator	rend(void) const;

			bool	empty(void) const;
			size_type	size(void) const;
			size_type	max_size(void) const;

			void	clear(void);
			ft::pair<iterator, bool>	insert(const_reference value);
			iterator	insert(iterator pos, const_reference value);
			template <class Iter>
			void	insert(Iter first, Iter last);
			void	erase(iterator pos);
			void	erase(iterator first, iterator last);
			size_type	erase(const key_type &key);
			void	swap(map &map_var);

			size_type	count(const key_type &key) const;
			iterator	find(const key_type &key);
			const_iterator	find(const key_type &key) const;
			ft::pair<iterator, iterator>	equal_range(const key_type &key);
			ft::pair<const_iterator, const_iterator>	equal_range(const key_type &key) const;
			iterator	lower_bound(const key_type &key);
			const_iterator	lower_bound(const key_type &key) const;
			iterator	upper_bound(const key_type &key);
			const_iterator	upper_bound(const key_type &key) const;

			key_compare	key_comp(void) const;
			value_compare	value_comp(void) const;

		private:
			key_compare		_compare;
			allocator_type	_alloc;
			tree_type		_tree;	
	};
}

# include "map.tpp"

#endif