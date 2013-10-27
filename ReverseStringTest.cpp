///////////////////////////////////////////////////////////////
// ReverseStringTest.cpp      Reverse String Test File       //
// Yueyong Su                                                //
///////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <time.h>
#include "UnitTestBase.h"
#include "ReverseStringClass.h"
using namespace Test;
using namespace ReverseStringSpace;

//TestGeneral class
class TestGeneral: public TestBase<TestGeneral>
{
public:
	TestGeneral() //constructor
	{ 		
		std::cout << "\n\n  Testing Reverse String General Cases";
	}
    //test string with one character
	bool testOne()
	{
		string str="a";
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testOne");
	}
	//test string with two characters
	bool testTwo()
	{
		string str="ab";
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testTwo");
	}
	//test string with three characters
	bool testThree()
	{
		string str="abc";
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testThree");
	}
	//test normal string
	bool testNormal()
	{
		string str="This is a normal string";
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testNormal");
	}
	//test string with special characters
	bool testSpecialChar()
	{
		string str="ab$cdefg*#1AD";
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testSpecialChar");
	}
	//test empty string
	bool testEmpty()
	{
		string str="";
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testEmpty");
	}
	//test one space
	bool testOneSpace()
	{
		string str=" ";
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testOneSpace");
	}
	//test several spaces
	bool testSeveralSpace()
	{
		string str="        ";
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testSeveralSpace");
	}
	//test string begin with space
	bool testBeginSpace()
	{
		string str=" abcd";
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testBeginSpace");
	}

	//execute all the tests in this class
	bool test()
	{
		bool t1;
		t1 = doTest(&TestGeneral::testOne);
		bool t2;
		t2 = doTest(&TestGeneral::testTwo);
		bool t3;
		t3 = doTest(&TestGeneral::testThree);
		bool t4;
		t4 = doTest(&TestGeneral::testNormal);
		bool t5;
		t5 = doTest(&TestGeneral::testSpecialChar);
		bool t6;
		t6 = doTest(&TestGeneral::testEmpty);
		bool t7;
		t7 = doTest(&TestGeneral::testOneSpace);
		bool t8;
		t8 = doTest(&TestGeneral::testSeveralSpace);
		bool t9;
		t9 = doTest(&TestGeneral::testBeginSpace);
		
		return t1&&t2&&t3&&t4&&t5&&t6&&t7&&t8&&t9;
	}

private:
	ReverseStringClass rs;
};

//TestSpecial class
class TestSpecial: public TestBase<TestSpecial>
{
public:
	TestSpecial() //constructor
	{ 		
		std::cout << "\n\n  Testing Reverse String Special Cases";
	}
    //test string with even length
	bool testAllLetters()
	{
		string str="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testAllLetters");
	}
	//test string with all asciis
	bool testAllAsciis()
	{
		string str=""; 
		for(int i=0; i<=255; i++){char c=i; str+=c;}
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testAllAsciis");
	}
	//test large string
	bool testLarge()
	{
		string str="";
		for(int i=0; i<1000; i++){ str+="a1b2c3d4";}
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testLarge");
	}
	//test palindrome string
	bool testPalindrome()
	{
		string str="amoreroma";
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testPalindrome");
	}	
	//test palindrome string with uppercase and lowercase
	bool testUpLowCase()
	{
		string str="baAB";
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testUpLowCase");
	}	
	//test random string
	bool testRand()
	{
		srand((unsigned)time(0));
		string str="";
		for(int i=0; i<15; i++)	
		{	
			char c=rand()%58+65; 
			str+=c;
		}
		string rev=str;
		reverse(rev.begin(), rev.end());
		rs.ReverseString(str);
		return checkResult(str.compare(rev)==0, "testRand");
	}	


	//execute all the tests in this class
	bool test()
	{
		bool t1;
		t1 = doTest(&TestSpecial::testAllLetters);		
		bool t2;
		t2 = doTest(&TestSpecial::testAllAsciis);	
		bool t3;
		t3 = doTest(&TestSpecial::testLarge);	
		bool t4;
		t4 = doTest(&TestSpecial::testPalindrome);
		bool t5;
		t5 = doTest(&TestSpecial::testUpLowCase);
		bool t6;
		t6 = doTest(&TestSpecial::testRand);

		return t1&&t2&&t3&&t4&&t5&&t6;
	}

private:
	ReverseStringClass rs;
};



//function to check all the tests
bool alltest()
{
	bool t1;
	TestGeneral te;
	t1 = te.test();
	bool t2;
	TestSpecial ts;
	t2 = ts.test();

	return t1&&t2;
}

int main(int argc, char* argv[])
{
	Title("Testing ReverseString");//test title

	if(alltest())
		std::cout << "\n\n  All tests passed\n\n";
	else
		std::cout << "\n\n  At least one test failed\n\n";	
}
