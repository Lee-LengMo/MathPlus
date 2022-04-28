// MathPlus.cpp : 定义静态库的函数。
//
# include "MathPlus.h"

namespace Mathplus
{
	DecUnit::DecUnit(int i)
	{
		fromInt(i);
	}
	DecUnit::DecUnit(char c)
	{
		fromChar(c);
	}

	void DecUnit::fromInt(int i)
	{
		int ui = abs(i);
		switch (ui)
		{
		case 0:num = DecUnitEnum::_0; break;
		case 1:num = DecUnitEnum::_1; break;
		case 2:num = DecUnitEnum::_2; break;
		case 3:num = DecUnitEnum::_3; break;
		case 4:num = DecUnitEnum::_4; break;
		case 5:num = DecUnitEnum::_5; break;
		case 6:num = DecUnitEnum::_6; break;
		case 7:num = DecUnitEnum::_7; break;
		case 8:num = DecUnitEnum::_8; break;
		case 9:num = DecUnitEnum::_9; break;
		}
	}

	void DecUnit::fromChar(char c)
	{
		switch (c)
		{
		case '0':num = DecUnitEnum::_0; break;
		case '1':num = DecUnitEnum::_1; break;
		case '2':num = DecUnitEnum::_2; break;
		case '3':num = DecUnitEnum::_3; break;
		case '4':num = DecUnitEnum::_4; break;
		case '5':num = DecUnitEnum::_5; break;
		case '6':num = DecUnitEnum::_6; break;
		case '7':num = DecUnitEnum::_7; break;
		case '8':num = DecUnitEnum::_8; break;
		case '9':num = DecUnitEnum::_9; break;
		}
	}

	int DecUnit::toInt()
	{
		switch (num)
		{
		case DecUnitEnum::_0:return 0;
		case DecUnitEnum::_1:return 1;
		case DecUnitEnum::_2:return 2;
		case DecUnitEnum::_3:return 3;
		case DecUnitEnum::_4:return 4;
		case DecUnitEnum::_5:return 5;
		case DecUnitEnum::_6:return 6;
		case DecUnitEnum::_7:return 7;
		case DecUnitEnum::_8:return 8;
		case DecUnitEnum::_9:return 9;
		}
		return 0;
	}

	char DecUnit::toChar()
	{
		switch (num)
		{
		case DecUnitEnum::_0:return '0';
		case DecUnitEnum::_1:return '1';
		case DecUnitEnum::_2:return '2';
		case DecUnitEnum::_3:return '3';
		case DecUnitEnum::_4:return '4';
		case DecUnitEnum::_5:return '5';
		case DecUnitEnum::_6:return '6';
		case DecUnitEnum::_7:return '7';
		case DecUnitEnum::_8:return '8';
		case DecUnitEnum::_9:return '9';
		}
		return '0';
	}
}

