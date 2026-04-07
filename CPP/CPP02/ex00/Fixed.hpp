
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int _value;
	static const int _bits = 8;

public:
	Fixed();
	Fixed(Fixed const &src);
	~Fixed();
	Fixed &operator=(Fixed const &src);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
