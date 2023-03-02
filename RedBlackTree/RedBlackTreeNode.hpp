#ifndef NODE_HPP
# define NODE_HPP

namespace	ft
{
	enum	Color {
		RED,
		BLACK
	};

	template <class T>
	struct	RedBlackTreeNode {
		T*					value;
		Color				color;
		RedBlackTreeNode*	parent;
		RedBlackTreeNode*	left;
		RedBlackTreeNode*	right;
		bool				is_sentinel;

		RedBlackTreeNode() {
			this->value = nullptr;
			this->color = BLACK;
			this->parent = nullptr;
			this->left = nullptr;
			this->right = nullptr;
			is_sentinel = false;
		};

		~RedBlackTreeNode() {};
	};
}

#endif
