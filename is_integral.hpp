#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace	ft
{
	template <class T, T v>
	struct	integral_constant {
		typedef T						value_type;
		typedef integral_constant<T, v>	type;

		static constexpr	value_type	value = v;

		operator T (void) const { return value };
	};

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	template <class T>
	struct	is_integral : false_type {};

	template <> struct	is_integral<bool> : true_type {};
	template <> struct	is_integral<char> : true_type {};
	template <> struct	is_integral<char16_t> : true_type {};
	template <> struct	is_integral<char32_t> : true_type {};
	template <> struct	is_integral<wchar_t> : true_type {};
	template <> struct	is_integral<signed char> : true_type {};
	template <> struct	is_integral<short> : true_type {};
	template <> struct	is_integral<int> : true_type {};
	template <> struct	is_integral<long> : true_type {};
	template <> struct	is_integral<long long> : true_type {};
	template <> struct	is_integral<unsigned char> : true_type {};
	template <> struct	is_integral<unsigned short> : true_type {};
	template <> struct	is_integral<unsigned int> : true_type {};
	template <> struct	is_integral<unsigned long> : true_type {};
	template <> struct	is_integral<unsigned long long> : true_type {};
}

#endif