// Int.cpp : 定义静态库的Int对象
//
# include "MathPlus.h"

namespace Mathplus
{
	Int::Int(short s)
	{
		fromShort(s);
	}
	Int::Int(unsigned short us)
	{
		fromUnsignedShort(us);
	}
	Int::Int(int i)
	{
		fromInt(i);
	}
	Int::Int(unsigned int ui)
	{
		fromUnsignedInt(ui);
	}
	Int::Int(long long ll)
	{
		fromLongLong(ll);
	}
	Int::Int(unsigned long long ull)
	{
		fromUnsignedLongLong(ull);
	}
	Int::Int(std::string str)
	{
		fromString(str);
	}

	void Int::fromShort(short s)
	{
		if (s >= 0)
			sign = Sign::Positive;
		else
			sign = Sign::Negative;
		s = abs(s);
		while (s)
		{
			num.push_back(DecUnit(s % 10));
			s /= 10;
		}
	}
	void Int::fromUnsignedShort(unsigned short us)
	{
		sign = Sign::Positive;
		while (us)
		{
			num.push_back(DecUnit(us % 10));
			us /= 10;
		}
	}
	void Int::fromInt(int i)
	{
		if (i >= 0)
			sign = Sign::Positive;
		else
			sign = Sign::Negative;
		i = abs(i);
		while (i)
		{
			num.push_back(DecUnit(i % 10));
			i /= 10;
		}
	}
	void Int::fromUnsignedInt(unsigned int ui)
	{
		sign = Sign::Positive;
		while (ui)
		{
			num.push_back(DecUnit((int)(ui % 10)));
			ui /= 10;
		}
	}
	void Int::fromLongLong(long long ll)
	{
		if (ll >= 0)
			sign = Sign::Positive;
		else
			sign = Sign::Negative;
		ll = abs(ll);
		while (ll)
		{
			num.push_back(DecUnit((int)(ll % 10)));
			ll /= 10;
		}
	}
	void Int::fromUnsignedLongLong(unsigned long long ull)
	{
		sign = Sign::Positive;
		while (ull)
		{
			num.push_back(DecUnit((int)(ull % 10)));
			ull /= 10;
		}
	}
	void Int::fromString(std::string str)
	{
		if (str.length() < 1)
			return;
		if (str[0] == '-')
		{
			sign = Sign::Negative;
			for (unsigned int i = str.length() - 1; i >= 1; i--)
				num.push_back(DecUnit(str[i]));
		}
		else if (isdigit(str[0]))
		{
			sign = Sign::Positive;
			for (unsigned int i = str.length() - 1; i > 0; i--)
				num.push_back(DecUnit(str[i]));
			num.push_back(str[0]);
		}
		pop0();
	}

	short Int::toShort()
	{
		short ret = 0;

		for (unsigned int i = 0; i < num.size(); i++)
		{
			unsigned long long k = 1;
			for (unsigned int j = 1; j <= i; j++)
				k *= 10;
			ret += num[i].toInt() * (short)k;
		}

		if (sign == Sign::Negative)
			ret = -ret;

		return ret;
	}
	unsigned short Int::toUnsignedShort()
	{
		unsigned short ret = 0;

		for (unsigned int i = 0; i < num.size(); i++)
		{
			unsigned long long k = 1;
			for (unsigned int j = 1; j <= i; j++)
				k *= 10;
			ret += num[i].toInt() * (unsigned short)k;
		}

		return ret;
	}
	int Int::toInt()
	{
		int ret = 0;

		for (unsigned int i = 0; i < num.size(); i++)
		{
			unsigned long long k = 1;
			for (unsigned int j = 1; j <= i; j++)
				k *= 10;
			ret += num[i].toInt() * (int)k;
		}

		if (sign == Sign::Negative)
			ret = -ret;

		return ret;
	}
	unsigned int Int::toUnsignedInt()
	{
		unsigned int ret = 0;

		for (unsigned int i = 0; i < num.size(); i++)
		{
			unsigned long long k = 1;
			for (unsigned int j = 1; j <= i; j++)
				k *= 10;
			ret += num[i].toInt() * (unsigned int)k;
		}

		return ret;
	}
	long long Int::toLongLong()
	{
		long long ret = 0;

		for (unsigned int i = 0; i < num.size(); i++)
		{
			unsigned long long k = 1;
			for (unsigned int j = 1; j <= i; j++)
				k *= 10;
			ret += num[i].toInt() * k;
		}

		if (sign == Sign::Negative)
			ret = -ret;

		return ret;
	}
	unsigned long long Int::toUnsignedLongLong()
	{
		unsigned long long ret = 0;

		for (unsigned int i = 0; i < num.size(); i++)
		{
			unsigned long long k = 1;
			for (unsigned int j = 1; j <= i; j++)
				k *= 10;
			ret += num[i].toInt() * k;
		}

		return ret;
	}
	std::string Int::toString()
	{
		std::ostringstream oss;
		if (sign == Sign::Negative)
			oss << '-';
		for (unsigned int i = num.size(); i > 0; i--)
		{
			oss << num[i - 1].toChar();
		}
		return oss.str();
	}

	std::istream& operator>>(std::istream& in, Int& a)
	{
		std::string str;
		in >> str;
		a.fromString(str);
		return in;
	}
	std::ostream& operator<<(std::ostream& out, Int& a)
	{
		out << a.toString();
		return out;
	}

	unsigned int Int::length()
	{
		return num.size();
	}
	unsigned int Int::max_length()
	{
		return num.max_size();
	}
	void Int::push0(unsigned int cnt)
	{
		for (unsigned int i = 0; i < cnt; i++)
			num.push_back(DecUnit(0));
	}
	void Int::pop0()
	{
		if (num.size() == 0 || (num.size() == 1 && num[0].toInt() == 0))
			return;
		for (unsigned int i = num.size(); num[i - 1].toInt() == 0 && i > 1; i--, num.pop_back());
	}
	DecUnit& Int::at(unsigned int pos)
	{
		return this->num.at(pos);
	}
	std::vector<DecUnit>::iterator Int::begin()
	{
		return this->num.begin();
	}
	std::vector<DecUnit>::iterator Int::end()
	{
		return this->num.end();
	}
	inline SizeRelationship Int::GetSizeRelationship(Int a)
	{
		if (a.sign != this->sign)
		{
			if (a.sign == Sign::Positive && this->sign == Sign::Negative)
				return SizeRelationship::Greater;
			if (a.sign == Sign::Negative && this->sign == Sign::Positive)
				return SizeRelationship::Less;
		}
		if (this->length() != a.num.size())
		{
			if (this->length() > a.num.size())
				return SizeRelationship::Greater;
			if (this->length() < a.num.size())
				return SizeRelationship::Less;
		}
		if (this->sign == Sign::Positive)
		{
			for (unsigned int i = 0; i < this->num.size(); i++)
			{
				if (this->num[i].toInt() == a.num[i].toInt())
					continue;
				else if (this->num[i].toInt() > a.num[i].toInt())
					return SizeRelationship::Greater;
				else
					return SizeRelationship::Less;
			}
		}
		else
		{

		}
		return SizeRelationship::Equal;
	}

	Int& Int::operator=(Int a)
	{
		if (&a == this)
			return *this;
		this->num = a.num;
		return *this;
	}
	Int& Int::operator=(const short& a)
	{
		fromShort(a);
		return *this;
	}
	Int& Int::operator=(const unsigned short& a)
	{
		fromUnsignedShort(a);
		return *this;
	}
	Int& Int::operator=(const int& a)
	{
		fromInt(a);
		return *this;
	}
	Int& Int::operator=(const unsigned int& a)
	{
		fromUnsignedInt(a);
		return *this;
	}
	Int& Int::operator=(const long long& a)
	{
		fromLongLong(a);
		return *this;
	}
	Int& Int::operator=(const unsigned long long& a)
	{
		fromUnsignedLongLong(a);
		return *this;
	}
	Int& Int::operator=(const std::string& a)
	{
		fromString(a);
		return *this;
	}

	bool Int::operator>(Int a)
	{
		return GetSizeRelationship(a) == SizeRelationship::Greater;
	}

	inline Int Int::Add(Int a)
	{
		Int res = 0;
		bool carry = 0;
		int addend;

		if (a.length() > this->length())	this->push0(a.length() - this->length());
		else								a.push0(this->length() - a.length());

		for (unsigned int i = 0; i < num.size(); i++)
		{
			addend = num[i].toInt() + a.num[i].toInt() + carry;
			if (carry = addend > 9)
			{
				res.num.push_back(DecUnit(addend - 10));
			}
			else
			{
				res.num.push_back(DecUnit(addend));
			}
		}
		if (carry)
			res.num.push_back(DecUnit(1));

		a.pop0();
		res.pop0();
		pop0();
		return res;
	}
	inline Int Int::Sub(Int a)
	{
		Int res = 0;

		if (a.length() > this->length())	this->push0(a.length() - this->length());
		else								a.push0(this->length() - a.length());

		a.pop0();
		res.pop0();
		pop0();
		return res;
	}
	inline Int Int::Mul(Int a)
	{
		Int res("0");

		return res;
	}
	inline Int Int::Div(Int a)
	{
		Int res("0");

		return res;
	}
	Int Int::operator+(const Int& a)
	{
		if (a.sign == this->sign)
		{
			Int res = Add(a);
			res.sign = a.sign;
			return res;
		}
		Int res = Sub(a);


		return res;
	}
}