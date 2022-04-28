# pragma once

# include "framework.h"

namespace Mathplus
{
	/************************************/
	/*      Enumerate DecUnitEnum		*/
	/*		枚举列表:	  DecUnitEnum		*/
	/*	  Goal: decimal digits			*/
	/*	  目标:     十进制数码				*/
	/************************************/
	enum class DecUnitEnum
	{
		_0, _1, _2, _3, _4, _5, _6, _7, _8, _9 
	};
	/************************************/
	/*      Enumerate Sign				*/
	/*		枚举列表:	  Sign				*/
	/*	  Goal: Store the sign of a Int	*/
	/*	  目标:     储存数符号				*/
	/************************************/
	enum class Sign
	{
		Positive, Negative
	};
	/************************************************/
	/*         Enumerate SizeRelationship			*/
	/*		   枚举列表: Relationship					*/
	/*	  Goal: Represents the size relationship of */
 	/* two numbers									*/
	/*	  目标:     ‎		表示数字的大小关系‎				*/
	/************************************************/
	enum class SizeRelationship
	{
		Greater, Less, Equal
	};

	/****************************************/
	/*      Structure DecUnit				*/
	/*		结构体:	  DecUnit				*/
	/*	  Goal: Store the sign of a Decimal	*/
	/*	  目标:     储存十进制数码并转换		*/
	/****************************************/
	struct DecUnit
	{
		DecUnitEnum num;
		DecUnit(int i = 0);
		DecUnit(char c = '0');
		void fromInt(int i);
		void fromChar(char c);
		int  toInt();
		char toChar();
	};
	
	class Int
	{
	private:
		Sign sign;
		std::vector<DecUnit> num;

		Int Add(Int a);
		Int Sub(Int a);
		Int Mul(Int a);
		Int Div(Int a);
	public:
		Int(short s);
		Int(unsigned short us);
		Int(int i = 0);
		Int(unsigned int ui);
		Int(long long ll);
		Int(unsigned long long ull);
		Int(std::string str);

		void fromShort(short s);
		void fromUnsignedShort(unsigned short us);
		void fromInt(int i);
		void fromUnsignedInt(unsigned int ui);
		void fromLongLong(long long ll);
		void fromUnsignedLongLong(unsigned long long ull);
		void fromString(std::string str);

		short toShort();
		unsigned short toUnsignedShort();
		int toInt();
		unsigned int toUnsignedInt();
		long long toLongLong();
		unsigned long long toUnsignedLongLong();
		std::string toString();

		friend std::istream& operator>>(std::istream& in,  Int& a);
		friend std::ostream& operator<<(std::ostream& out, Int& a);

		unsigned int length();
		unsigned int max_length();
		DecUnit& at(unsigned int pos);
		void push0(unsigned int num);
		void pop0();
		std::vector<DecUnit>::iterator begin();
		std::vector<DecUnit>::iterator end();
		SizeRelationship GetSizeRelationship(Int a);

		Int& operator=(Int a);
		Int& operator=(const short& a);
		Int& operator=(const unsigned short& a);
		Int& operator=(const int& a);
		Int& operator=(const unsigned int& a);
		Int& operator=(const long long& a);
		Int& operator=(const unsigned long long& a);
		Int& operator=(const std::string& a);

		bool operator>(Int a);

		Int operator+(const Int& a);
	};
}