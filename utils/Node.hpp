#ifndef NODE_HPP
# define NODE_HPP

namespace	ft
{
	enum	Color {
		RED,
		BLACK
	};

	template <class T>
	struct	Node {
		T		*value;
		Color	color;
		Node	*parent;
		Node	*left;
		Node	*right;

		Node() {
			this->value = nullptr;
			this->color = BLACK;
			this->parent = nullptr;
			this->left = nullptr;
			this->right = nullptr;
		};

		~Node() {};
	};
}

#endif