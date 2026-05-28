// --------------------------------------------------------------------------------
// Name: Nahom Kahsay
// Class: SET-252-400
// Assignment: Final Project - CSuperString
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "CSuperString.h"

// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
void ConstructorTests();
void AssignmentOperatorTests();
void ConcatenationTest();
void FindTests();
void TransformationTests();
void SubstringTests();
void ReplaceinsertTests();
void SubscriptTests();
void ConversionTests();
void StreamTests();
void ComparisonTests();
void Test1();
void Test2();

// --------------------------------------------------------------------------------
// Name: main
// Abstract: this is where the program starts
// --------------------------------------------------------------------------------
int main()
{
	cout << "-----------------------------------------------------------------" << endl;
	cout << "CSuperString Tests" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << endl;

	// #1 Constructors, Assignment operators, deep copy, ToString and Print
	ConstructorTests();

	// #2 Assignment operators (char*, char, CSuperString) and self-assignment
	AssignmentOperatorTests();

	// #3 Concatenation operators (+=, =) with all parameter types
	ConcatenationTest();

	// #4 Find methods (FindFirstIndexOf, FindLastIndexOf) for char and substring
	FindTests();

	// #5 Transformation methods (ToUpperCase, ToLowerCase, Trim, Reverse)
	TransformationTests();

	// #6 Substring extraction methods (Left, Right, Substring, Length)
	SubstringTests();

	// #7 Replace and insert methods for char and substring
	ReplaceinsertTests();

	// #8 Subscript methods ([] for reading and writing)
	SubscriptTests();

	// #9 Conversion methods (ToBoolean, ToShort, ToInteger, ToLong, ToFloat, ToDouble)
	ConversionTests();

	// #10 Stream operators (<<, >>)
	StreamTests();

	// #11 Comparison operators (==, !=, <, >, <=, >=) with ASCII odering
	ComparisonTests();

	// #12 Default constructor with stream output
	Test1();

	// #13 Self assignment with substring replacement
	Test2();

	return 0;
}

// --------------------------------------------------------------------------------
// Name: ConstructorTests
// Abstract: Test all the different paramertized constructors
// --------------------------------------------------------------------------------
void ConstructorTests()
{
	CSuperString ssSource1;
	CSuperString ssSource2("I Love Star Trek");
	CSuperString ssSource3a(true);
	CSuperString ssSource3b (false);
	CSuperString ssSource4('X');
	CSuperString ssSource5a((short) SHRT_MIN);
	CSuperString ssSource5b( (short) SHRT_MAX);
	CSuperString ssSource6a( (int) INT_MIN);
	CSuperString ssSource6b( (int) INT_MAX);
	CSuperString ssSource7a( (long) LONG_MIN);
	CSuperString ssSource7b( (long) LONG_MAX);
	CSuperString ssSource8a( (float) FLT_MIN);
	CSuperString ssSource8b( (float) FLT_MAX);
	CSuperString ssSource9a( (double) DBL_MIN);
	CSuperString ssSource9b( (double) DBL_MAX);
	CSuperString ssSource10(ssSource2);


	// --------------------------------------------------------------------------------
	// Constructors
	// --------------------------------------------------------------------------------
	cout << "Constructors" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "1) Default			" << ssSource1.ToString() << endl;
	cout << "2) char*			" << ssSource2.ToString() << endl;
	cout << "3a) bool			" << ssSource3a.ToString() << endl;
	cout << "3b) bool			" << ssSource3b.ToString() << endl;
	cout << "4) char				" << ssSource4.ToString() << endl;
	cout << "5a) short			" << ssSource5a.ToString() << endl;
	cout << "5b) short			" << ssSource5b.ToString() << endl;
	cout << "6a) int				" << ssSource6a.ToString() << endl;
	cout << "6b) int				" << ssSource6b.ToString() << endl;
	cout << "7a) long			" << ssSource7a.ToString() << endl;
	cout << "7b) long			" << ssSource7b.ToString() << endl;
	cout << "8a) float			" << ssSource8a.ToString() << endl;
	cout << "8b) float			" << ssSource8b.ToString() << endl;
	cout << "9a) double			" << ssSource9a.ToString() << endl;
	cout << "9b) double			" << ssSource9b.ToString() << endl;
	cout << "10) SuperString			" << ssSource10.ToString() << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << endl;
}

// --------------------------------------------------------------------------------
// Name: AssignmentOperatorTests
// Abstract: Test all the different assignment operators
// --------------------------------------------------------------------------------
void AssignmentOperatorTests()
{
	CSuperString ssSource1;
	CSuperString ssSource2;
	CSuperString ssSource3;
	CSuperString ssSource4("Test");

	ssSource1 = "Hello World";
	ssSource2 = 'Z';
	ssSource3 = ssSource1;
	ssSource4 = ssSource4;


	// --------------------------------------------------------------------------------
	// Assignment Operators
	// --------------------------------------------------------------------------------
	cout << "Assignment Operators" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "1) char*			" << ssSource1.ToString() << endl;
	cout << "2) char				" << ssSource2.ToString() << endl;
	cout << "3) CSuperString			" << ssSource3.ToString() << endl;
	cout << "4) Self-assignment		" << ssSource4.ToString() << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << endl;
	

}

// --------------------------------------------------------------------------------
// Name: ConcatenationTests
// Abstract: Test all the different concatenation operators
// --------------------------------------------------------------------------------
void ConcatenationTest()
{
	CSuperString ssSource1("Hello");
	CSuperString ssSource2(" World");

	ssSource1 += " There";

	CSuperString ssSource3(ssSource1);
	ssSource3 += '!';

	CSuperString ssSource4(ssSource3);
	ssSource4 += ssSource2;

	CSuperString ssSource5(CSuperString("Star") + CSuperString(" Trek"));
	CSuperString ssSource6("I Love " + CSuperString("Programming"));
	CSuperString ssSource7(CSuperString("C++") + " is fun");


	// --------------------------------------------------------------------------------
	// Concatenation Operators
	// --------------------------------------------------------------------------------
	cout << "Concatenation Operators" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "1) += const char*		" << ssSource1.ToString() << endl;
	cout << "2) += char			" << ssSource3.ToString() << endl;
	cout << "3) += CSuperString		" << ssSource4.ToString() << endl;
	cout << "4) + (SS + SS)			" << ssSource5.ToString() << endl;
	cout << "5) + (char* + SS)		" << ssSource6.ToString() << endl;
	cout << "6) + (SS + char*)		" << ssSource7.ToString() << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << endl;
}

// --------------------------------------------------------------------------------
// Name: FindTests
// Abstract: Test all find methods
// --------------------------------------------------------------------------------
void FindTests()
{
	CSuperString ssSource("I Love Star Wars and I Love Star Trek");

	long lngResult1(ssSource.FindFirstIndexOf('L'));
	long lngResult2(ssSource.FindFirstIndexOf('L', 3));
	long lngResult3(ssSource.FindLastIndexOf('L'));
	long lngResult4(ssSource.FindFirstIndexOf("Love"));
	long lngResult5(ssSource.FindFirstIndexOf("Love", 10));
	long lngResult6(ssSource.FindLastIndexOf("Love"));
	long lngResult7(ssSource.FindFirstIndexOf("Trek"));
	long lngResult8(ssSource.FindFirstIndexOf("Spock"));


	// --------------------------------------------------------------------------------
	// Find Methods
	// --------------------------------------------------------------------------------
	cout << "Find Methods" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Test String: " << ssSource.ToString() << endl;
	cout << endl;
	cout << "1) FindFirstIndexOf('L')		" << lngResult1 << endl;
	cout << "2) FindFirstIndexOf('L', 3)		" << lngResult2 << endl;
	cout << "3) FindLastIndexOf('L')			" << lngResult3 << endl;
	cout << "4) FindFirstIndexOf(\"Love\")		" << lngResult4 << endl;
	cout << "5) FindFirstIndexOf(\"Love\", 10)		" << lngResult5 << endl;
	cout << "6) FindLastIndexOf(\"Love\")		" << lngResult6 << endl;
	cout << "7) FindFirstIndexOf(\"Trek\")		" << lngResult7 << endl;
	cout << "8) FindFirstIndexOf(\"Spock\")		" << lngResult8 << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << endl;
}

// --------------------------------------------------------------------------------
// Name: TransformationTests
// Abstract: Test all transformation methods
// --------------------------------------------------------------------------------
void TransformationTests()
{
	CSuperString ssSource1("Hello World");
	CSuperString ssSource2("	Hello World		");
	
	CSuperString ssSource3(ssSource1.ToUpperCase());
	CSuperString ssSource4(ssSource1.ToLowerCase());
	CSuperString ssSource5(ssSource2.TrimLeft());
	CSuperString ssSource6(ssSource2.TrimRight());
	CSuperString ssSource7(ssSource2.Trim());
	CSuperString ssSource8(ssSource1.Reverse());


	// --------------------------------------------------------------------------------
	// Transformation Methods
	// --------------------------------------------------------------------------------
	cout << "Transformation Methods" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Original: "<< ssSource1.ToString() << endl;
	cout << endl;
	cout << "1) ToUpperCase: " << ssSource3.ToString() << endl;
	cout << "2) ToLowerCase: " << ssSource4.ToString() << endl;
	cout << endl;
	cout << "Original with spaces:" << ssSource2.ToString() << endl;
	cout << endl;
	cout << "3) TrimLeft: " << ssSource5.ToString() << endl;
	cout << "4) TrimRight: " << ssSource6.ToString() << endl;
	cout << "5) Trim: " << ssSource7.ToString() << endl;
	cout << endl;
	cout << "Original: " << ssSource1.ToString() << endl;
	cout << endl;
	cout << "6) Reverse: " << ssSource8.ToString() << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << endl;

}

// --------------------------------------------------------------------------------
// Name: TransformationTests
// Abstract: Test all transformation methods
// --------------------------------------------------------------------------------
void SubstringTests()
{
	CSuperString ssSource("I Love Star Trek");
	CSuperString ssSource2(ssSource.Left(6));
	CSuperString ssSource3(ssSource.Right(9));
	CSuperString ssSource4(ssSource.Substring(7, 4));
	CSuperString ssSource5(ssSource.Substring(2, 4));


	// --------------------------------------------------------------------------------
	// Substring Methods
	// --------------------------------------------------------------------------------
	cout << "Substring Methods" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Default: " << ssSource.ToString() << endl;
	cout << endl;
	cout << "Length: " << ssSource.Length() << endl;
	cout << "1) Left(6): " << ssSource2.ToString() << endl;
	cout << "2) Right(9): " << ssSource3.ToString() << endl;
	cout << "3) Substring(7, 4): " << ssSource4.ToString() << endl;
	cout << "4) Substring(2, 4): " << ssSource5.ToString() << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << endl;
}

// --------------------------------------------------------------------------------
// Name: ReplaceInsertTests
// Abstract: Test replace and insert methods
// --------------------------------------------------------------------------------
void ReplaceinsertTests()
{
	CSuperString ssSource("I Love Star Wars ");
	CSuperString ssSource2(ssSource.Replace('o', 'O'));
	CSuperString ssSource3(ssSource.Replace("Love", "Hate"));
	CSuperString ssSource4(ssSource.Insert('!', 17));
	CSuperString ssSource5(ssSource.Insert("So Much", 17));


	// --------------------------------------------------------------------------------
	// Replace and Insert Methods
	// --------------------------------------------------------------------------------
	cout << "Replace and Insert Methods" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Original: " << ssSource.ToString() << endl;
	cout << endl;
	cout << "1) Replace('o', 'O'): " << ssSource2.ToString() << endl;
	cout << "1) Replace('Love', 'Hate'): " << ssSource3.ToString() << endl;
	cout << "1) Insert('!', 16): " << ssSource4.ToString() << endl;
	cout << "1) Insert(' So Much', 16): " << ssSource5.ToString() << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << endl;
}

// --------------------------------------------------------------------------------
// Name: SubscriptTests
// Abstract: Test subscript operators
// --------------------------------------------------------------------------------
void SubscriptTests()
{

	CSuperString ssSource("Hello");
	CSuperString ssSource2("Hello");

	char chrResult1(ssSource[0]);
	char chrResult2(ssSource[4]);

	ssSource2[0] = 'J';


	// --------------------------------------------------------------------------------
	// Subscript Operators
	// --------------------------------------------------------------------------------
	cout << "Subscript Operators" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Original: " << ssSource.ToString() << endl;
	cout << endl;
	cout << "1) [0]: " << chrResult1 << endl;
	cout << "2) [4]: " << chrResult2 << endl;
	cout << "3) After ssSource2[0] = 'J': " << ssSource2.ToString() << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << endl;
}

// --------------------------------------------------------------------------------
// Name: ConversionTests
// Abstract: Test conversion methods
// --------------------------------------------------------------------------------
void ConversionTests()
{
	CSuperString ssSource1("true");
	CSuperString ssSource2("false");
	CSuperString ssSource3("42");
	CSuperString ssSource4("12345");
	CSuperString ssSource5("3.14159");
	CSuperString ssSource6("2.71828");

	bool blnResult1(ssSource1.ToBoolean());
	bool blnResult2(ssSource2.ToBoolean());
	short shtResult(ssSource3.ToShort());
	int intResult(ssSource4.ToInteger());
	long lngResult(ssSource4.ToLong());
	float sngResult(ssSource5.ToFloat());
	double dblResult(ssSource6.ToDouble());


	// --------------------------------------------------------------------------------
	// Conversion Methods
	// --------------------------------------------------------------------------------
	cout << "Conversion Methods\n" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "1) ToBoolean() - \"true\"		" << blnResult1 << endl;
	cout << "2) ToBoolean() - \"false\"	" << blnResult2 << endl;
	cout << "3) ToShort() - \"42\"		" << shtResult << endl;
	cout << "4) ToInteger() - \"12345\"	" << intResult << endl;
	cout << "5) ToLong() - \"12345\"		" << lngResult << endl;
	cout << "6) ToFloat() - \"3.14159\"	" << sngResult << endl;
	cout << "7) ToDouble() - \"2.71828\"	" << dblResult << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << endl;
}

// --------------------------------------------------------------------------------
// Name: StreamTests
// Abstract: Test stream operators
// --------------------------------------------------------------------------------
void StreamTests()
{
	CSuperString ssSource1("Stream Output Test");
	CSuperString ssSource2;


	// --------------------------------------------------------------------------------
	// Stream Operators
	// --------------------------------------------------------------------------------
	cout << "Stream Operators\n" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "1) Output operator (<<): " << ssSource1 << endl;
	cout << endl;
	cout << "2) Input operator(>>): " << endl;
	cout << "Enter a word for testing: ";
	cin >> ssSource2;
	cout << "You entered: " << ssSource2 << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << endl;
}

// --------------------------------------------------------------------------------
// Name: ComparisonTests
// Abstract: Test comparison operators
// --------------------------------------------------------------------------------
void ComparisonTests()
{
	CSuperString ssSource1("apple");
	CSuperString ssSource2("banana");
	CSuperString ssSource3("Apple");
	CSuperString ssSource4("Banana");

	bool blnResult1(ssSource1 == ssSource3);
	bool blnResult2(ssSource1 == ssSource2);
	bool blnResult3(ssSource1 != ssSource2);
	bool blnResult4(ssSource1 != ssSource3);
	bool blnResult5(ssSource1 < ssSource2);
	bool blnResult6(ssSource2 < ssSource1);
	bool blnResult7(ssSource2 > ssSource1);
	bool blnResult8(ssSource1 > ssSource2);
	bool blnResult9(ssSource1 <= ssSource3);
	bool blnResult10(ssSource2 <= ssSource1);
	bool blnResult11(ssSource1 >= ssSource3);
	bool blnResult12(ssSource1 >= ssSource2);
	bool blnResult13(ssSource4 < ssSource1);
	bool blnResult14(ssSource1 < ssSource4);


	// --------------------------------------------------------------------------------
	// Comparison Operators
	// --------------------------------------------------------------------------------
	cout << "Comparison Operators\n" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Test Strings: \"" << ssSource1 << "\", \"" << ssSource2 << "\", \"" << ssSource3 << "\", \"" << ssSource4 << "\"" << endl;
	cout << endl;
	cout << "1) \"apple\" == \"Apple\"		" << blnResult1 << " (false)" << endl;
	cout << "2) \"apple\" == \"banana\"		" << blnResult2 << " (false)" << endl;
	cout << "3) \"apple\" != \"banana\"		" << blnResult3 << " (true)" << endl;
	cout << "4) \"apple\" != \"Apple\"		" << blnResult4 << " (true)" << endl;
	cout << "5) \"apple\" < \"banana\"		" << blnResult5 << " (true)" << endl;
	cout << "6) \"banana\" < \"apple\"		" << blnResult6 << " (false)" << endl;
	cout << "7) \"banana\" > \"apple\"		" << blnResult7 << " (true)" << endl;
	cout << "8) \"apple\" > \"banana\"		" << blnResult8 << " (false)" << endl;
	cout << "9) \"apple\" <= \"Apple\"		" << blnResult9 << " (false, ASCII)" << endl;
	cout << "10) \"banana\" <= \"apple\"		" << blnResult10 << " (false)" << endl;
	cout << "11) \"apple\" >= \"Apple\"		" << blnResult11 << " (true, ASCII)" << endl;
	cout << "12) \"apple\" >= \"banana\"		" << blnResult12 << " (false)" << endl;
	cout << "13) \"Banana\" < \"apple\"		" << blnResult13 << " (true, ASCII)" << endl;
	cout << "14) \"apple\" < \"Banana\"		" << blnResult14 << " (false, ASCII)" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << endl;
}

// --------------------------------------------------------------------------------
// Name: Test1
// Abstract: Required Test #1 
// --------------------------------------------------------------------------------
void Test1()
{
	CSuperString ssTest;


	// --------------------------------------------------------------------------------
	// Required Test #1
	// --------------------------------------------------------------------------------
	cout << "Required Test #1\n" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Test #1: " << ssTest << endl;
	cout << endl;
	cout << endl;
}

// --------------------------------------------------------------------------------
// Name: Test2
// Abstract: Required Test #2 
// --------------------------------------------------------------------------------
void Test2()
{
	CSuperString ssTest("I Love Star Wars and I Love Star Trek");

	ssTest = ssTest.Replace("Love", "Really Love Love");


	// --------------------------------------------------------------------------------
	// Required Test #2
	// --------------------------------------------------------------------------------
	cout << "Required Test #2\n" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "Test #2: " << ssTest << endl;
	cout << endl;
	cout << endl;
}