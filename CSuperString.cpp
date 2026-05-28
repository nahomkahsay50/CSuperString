// --------------------------------------------------------------------------------
// Name: CSuperString
// --------------------------------------------------------------------------------


// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CSuperString.h"

// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Default constructor
// --------------------------------------------------------------------------------
CSuperString::CSuperString()
{
	Initialize("");
}

// --------------------------------------------------------------------------------
// Name: Parameter Constructor #1
// Abstract: const char*
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const char* pstrStringTocopy)
{
	Initialize(pstrStringTocopy);
}

// --------------------------------------------------------------------------------
// Name: Parameter Constructor #2
// Abstract: boolean
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const bool blnBooleanToCopy)
{
	Initialize("");

	if (blnBooleanToCopy == true)
	{
		*this = "true";
	}
	else
	{
		*this = "false";
	}
}

// --------------------------------------------------------------------------------
// Name: Parameter Constructor #3
// Abstract: char
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const char chrLetterToCopy)
{
	char strSource[2] = { chrLetterToCopy, 0 };

	Initialize(strSource);

}

// --------------------------------------------------------------------------------
// Name: Parameter Constructor #4
// Abstract: short
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const short shtShortToCopy)
{
	//32767 = 5 digits + 1 digit for sign (+/-) + 1 digit for terminator + 1 for caution = 8
	char strSource[8] = "";

	sprintf_s(strSource, "%hd", shtShortToCopy);

	Initialize(strSource);

}

// --------------------------------------------------------------------------------
// Name: Parameter Constructor #5
// Abstract: int
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const int intIntegerToCopy)
{
	char strSource[15] = "";

	sprintf_s(strSource, "%d", intIntegerToCopy);

	Initialize(strSource);
}

// --------------------------------------------------------------------------------
// Name: Parameter Constructor #6
// Abstract: long
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const long lngLongToCopy)
{
	char strSource[25] = "";

	sprintf_s(strSource, "%ld", lngLongToCopy);

	Initialize(strSource);
}

// --------------------------------------------------------------------------------
// Name: Parameter Constructor #7
// Abstract: float
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const float sngFloatToCopy)
{
	char strSource[128] = "";

	sprintf_s(strSource, "%g", sngFloatToCopy);

	Initialize(strSource);
}

// --------------------------------------------------------------------------------
// Name: Parameter Constructor #8
// Abstract: double
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const double dblDoubleToCopy)
{
	char strSource[512] = "";

	sprintf_s(strSource, "%g", dblDoubleToCopy);

	Initialize(strSource);
}

// --------------------------------------------------------------------------------
// Name: Copy Constructor
// Abstract: Copy constructor
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const CSuperString &ssOriginalToCopy)
{
	Initialize(ssOriginalToCopy.ToString());
}

// --------------------------------------------------------------------------------
// Name: Initialize
// Abstract: Set class pointers to zero and then call set methods
// --------------------------------------------------------------------------------
void CSuperString::Initialize(const char* pstrSource)
{
	m_pstrSuperString = 0;

	//Funnel all memory allocation through the assignment operator
	*this = pstrSource;
}

// --------------------------------------------------------------------------------
// Name: Length
// Abstract: How long are we?
// --------------------------------------------------------------------------------
long CSuperString::Length() const
{
	long lngLength = 0;

	lngLength = (long)strlen(m_pstrSuperString);

	return lngLength;
}

// --------------------------------------------------------------------------------
// Name: Assignment Operator #3
// Abstract: char
// --------------------------------------------------------------------------------
void CSuperString::operator = (const char chrLetterToCopy)
{
	char strSource[2] = { chrLetterToCopy, 0 };

	*this = strSource;

}

// --------------------------------------------------------------------------------
// Name: Assignment Operator #1
// Abstract: const char*
// --------------------------------------------------------------------------------
void CSuperString::operator = (const char* pstrSource)
{
	//Self assignment?
	if (m_pstrSuperString != pstrSource)
	{
		//No, clean up and...
		CleanUp();

		//Deep copy
		DeepCopy(pstrSource);
	}
}

// --------------------------------------------------------------------------------
// Name: Assignment Operator #2
// Abstract: CSuperString
// --------------------------------------------------------------------------------
void CSuperString::operator = (const CSuperString& ssStringToCopy)
{

	*this = ssStringToCopy.m_pstrSuperString;

}

// --------------------------------------------------------------------------------
// Name: Concatenate Operator #1
// Abstract: const char*
// --------------------------------------------------------------------------------
void CSuperString::operator += (const char* pstrStringToAppend)
{
	long lngNewLength = 0;
	char* pstrNewString = 0;

	lngNewLength = Length() + strlen(pstrStringToAppend);
	pstrNewString = new char[lngNewLength + 1];

	strcpy_s(pstrNewString, lngNewLength + 1, m_pstrSuperString);
	strcat_s(pstrNewString, lngNewLength + 1, pstrStringToAppend);

	*this = pstrNewString;

	delete[] pstrNewString;
}

// --------------------------------------------------------------------------------
// Name: Concatenate Operator #2
// Abstract: char
// --------------------------------------------------------------------------------
void CSuperString::operator += (const char chrCharacterToAppend)
{
	char strSource[2] = { chrCharacterToAppend, 0 };

	*this += strSource;
}

// --------------------------------------------------------------------------------
// Name: Concatenate Operator #3
// Abstract: CSuperString
// --------------------------------------------------------------------------------
void CSuperString::operator += (const CSuperString& ssStringToAppend)
{
	*this += ssStringToAppend.m_pstrSuperString;
}

// --------------------------------------------------------------------------------
// Name: Addition Operator #1
// Abstract: CSuperString + CSuperString
// --------------------------------------------------------------------------------
CSuperString operator + (const CSuperString& ssLeft, const CSuperString& ssRight)
{
	CSuperString ssResult = ssLeft;
	ssResult += ssRight;
	
	return ssResult;
}

// --------------------------------------------------------------------------------
// Name: Addition Operator #2
// Abstract: char* + CSuperString
// --------------------------------------------------------------------------------
CSuperString operator + (const char* pstrLeftSide, const CSuperString& ssRightSide)
{
	CSuperString ssResult = pstrLeftSide;
	ssResult += ssRightSide;

	return ssResult;
}

// --------------------------------------------------------------------------------
// Name: Addition Operator #3
// Abstract: CSuperString + char*
// --------------------------------------------------------------------------------
CSuperString operator + (const CSuperString& ssLeftSide, const char* pstrRightSide)
{
	CSuperString ssResult = ssLeftSide;
	ssResult += pstrRightSide;

	return ssResult;
}

// --------------------------------------------------------------------------------
// Name: FindFirstIndexOf #1
// Abstract: First index of a letter
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char chrLetterToFind)
{
	return FindFirstIndexOf(chrLetterToFind, 0);
}

// --------------------------------------------------------------------------------
// Name: FindFirstIndexOf #2
// Abstract: First index of character starting from index
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex)
{
	long lngIndex = -1;
	long lngLength = Length();

	for (long lngCurrentIndex = lngStartIndex; lngCurrentIndex < lngLength; lngCurrentIndex++)
	{
		if (m_pstrSuperString[lngCurrentIndex] == chrLetterToFind)
		{
			lngIndex = lngCurrentIndex;
			break;
		}
	}

	return lngIndex;
}

// --------------------------------------------------------------------------------
// Name: FindLastIndexOf #1
// Abstract: Last index of character
// --------------------------------------------------------------------------------
long CSuperString::FindLastIndexOf(const char chrLetterToFind)
{
	long lngIndex = -1;
	long lngLength = Length();

	for (long lngCurrentIndex = lngLength - 1; lngCurrentIndex >= 0; lngCurrentIndex--)
	{
		if (m_pstrSuperString[lngCurrentIndex] == chrLetterToFind)
		{
			lngIndex = lngCurrentIndex;
			break;
		}
	}

	return lngIndex;
}

// --------------------------------------------------------------------------------
// Name: FindFirstIndexOf #3
// Abstract: First index of substring
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind)
{
	return FindFirstIndexOf(pstrSubStringToFind, 0);
}

// --------------------------------------------------------------------------------
// Name: FindFirstIndexOf #4
// Abstract: First index of substring starting from index
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind, long lngStartIndex)
{
	long lngIndex = -1;
	char* pstrFound = 0;

	pstrFound = strstr(m_pstrSuperString + lngStartIndex, pstrSubStringToFind);

	if (pstrFound != 0)
	{
		lngIndex = pstrFound - m_pstrSuperString;
	}

	return lngIndex;
}

// --------------------------------------------------------------------------------
// Name: FindLastIndexOf #2
// Abstract: Last index of substring
// --------------------------------------------------------------------------------
long CSuperString::FindLastIndexOf(const char* pstrSubStringToFind)
{
	long lngIndex = -1;
	long lngSubStringLength = strlen(pstrSubStringToFind);
	long lngLength = Length();

	for (long lngCurrentIndex = lngLength - lngSubStringLength; lngCurrentIndex >= 0; lngCurrentIndex--)
	{
		bool blnMatch = true;
		for (long lngSubIndex = 0; lngSubIndex < lngSubStringLength; lngSubIndex++)
		{
			if (m_pstrSuperString[lngCurrentIndex + lngSubIndex] != pstrSubStringToFind[lngSubIndex])
			{
				blnMatch = false;
				break;
			}
		}

		if (blnMatch)
		{
			lngIndex = lngCurrentIndex;
			break;
		}
	}

	return lngIndex;
}

// --------------------------------------------------------------------------------
// Name: ToUpperCase
// Abstract: Return uppercase
// --------------------------------------------------------------------------------
const char* CSuperString::ToUpperCase()
{
	static CSuperString ssResult;
	ssResult = "";
	long lngLength = Length();

	for (long lngIndex = 0; lngIndex < lngLength; lngIndex++)
	{
		ssResult += (char)toupper(m_pstrSuperString[lngIndex]);
	}

	return ssResult.ToString();
}

// --------------------------------------------------------------------------------
// Name: ToLowerCase
// Abstract: Return lowercase
// --------------------------------------------------------------------------------
const char* CSuperString::ToLowerCase()
{
	static CSuperString ssResult;
	ssResult = "";
	long lngLength = Length();

	for (long lngIndex = 0; lngIndex < lngLength; lngIndex++)
	{
		ssResult += (char)tolower(m_pstrSuperString[lngIndex]);
	}

	return ssResult.ToString();
}

// --------------------------------------------------------------------------------
// Name: TrimLeft
// Abstract: Remove whitespace from left side
// --------------------------------------------------------------------------------
const char* CSuperString::TrimLeft()
{
	static CSuperString ssResult;
	ssResult = "";
	long lngLength = Length();
	long lngStartIndex = 0;

	//Find first non-whitespace character
	for (long lngIndex = 0; lngIndex < lngLength; lngIndex++)
	{
		if (!isspace(m_pstrSuperString[lngIndex]))
		{
			lngStartIndex = lngIndex;
			break;
		}
	}

	//Copy from start to end
	for (long lngIndex = lngStartIndex; lngIndex < lngLength; lngIndex++)
	{
		ssResult += m_pstrSuperString[lngIndex];
	}

	return ssResult.ToString();
}

// --------------------------------------------------------------------------------
// Name: TrimRight
// Abstract: Remove whitespace from right side
// --------------------------------------------------------------------------------
const char* CSuperString::TrimRight()
{
	static CSuperString ssResult;
	ssResult = "";
	long lngLength = Length();
	long lngEndIndex = 0;

	//Find last non-whitespace character
	for (long lngIndex = lngLength - 1; lngIndex >= 0; lngIndex--)
	{
		if (!isspace(m_pstrSuperString[lngIndex]))
		{
			lngEndIndex = lngIndex + 1;
			break;
		}
	}

	//Copy from start to end
	for (long lngIndex = 0; lngIndex < lngEndIndex; lngIndex++)
	{
		ssResult += m_pstrSuperString[lngIndex];
	}

	return ssResult.ToString();
}

// --------------------------------------------------------------------------------
// Name: Trim
// Abstract: Remove withspace
// --------------------------------------------------------------------------------
const char* CSuperString::Trim()
{
	static CSuperString ssResult;
	ssResult = *this;
	ssResult = ssResult.TrimLeft();
	ssResult = ssResult.TrimRight();

	return ssResult.ToString();
}

// --------------------------------------------------------------------------------
// Name: Reverse
// Abstract: Return reversed string
// --------------------------------------------------------------------------------
const char* CSuperString::Reverse()
{
	static CSuperString ssResult;
	ssResult = "";
	long lngLength = Length();

	//Loop backwards through the string
	for (long lngIndex = lngLength - 1; lngIndex >= 0; lngIndex--)
	{
		ssResult += m_pstrSuperString[lngIndex];
	}

	return ssResult.ToString();
}

// --------------------------------------------------------------------------------
// Name: Left
// Abstract: Get first 
// --------------------------------------------------------------------------------
const char* CSuperString::Left(long lngCharactersToCopy)
{
	static CSuperString ssResult;
	ssResult = "";
	long lngLength = Length();

	if (lngCharactersToCopy > lngLength)
	{
		lngCharactersToCopy = lngLength;
	}
	
	for (long lngIndex = 0; lngIndex < lngCharactersToCopy; lngIndex++)
	{
		ssResult += m_pstrSuperString[lngIndex];
	}

	return ssResult.ToString();
}

// --------------------------------------------------------------------------------
// Name: Right
// Abstract: Get last
// --------------------------------------------------------------------------------
const char* CSuperString::Right(long lngCharactersToCopy)
{
	static CSuperString ssResult;
	ssResult = "";
	long lngLength = Length();
	long lngStartIndex = 0;

	if (lngCharactersToCopy > lngLength)
	{
		lngCharactersToCopy = lngLength;
	}

	lngStartIndex = lngLength - lngCharactersToCopy;

	for (long lngIndex = lngStartIndex; lngIndex < lngLength; lngIndex++)
	{
		ssResult += m_pstrSuperString[lngIndex];
	}

	return ssResult.ToString();
}

// --------------------------------------------------------------------------------
// Name: Substring
// Abstract: Get substring at index with length
// --------------------------------------------------------------------------------
const char* CSuperString::Substring(long lngStart, long lngSubStringLength)
{
	static CSuperString ssResult;
	ssResult = "";
	long lngLength = Length();
	long lngEndIndex = lngStart + lngSubStringLength;

	if (lngEndIndex > lngLength)
	{
		lngEndIndex = lngLength;
	}

	for (long lngIndex = lngStart; lngIndex < lngEndIndex; lngIndex++)
	{
		ssResult += m_pstrSuperString[lngIndex];
	}

	return ssResult.ToString();
}

// --------------------------------------------------------------------------------
// Name: Replace #1
// Abstract: Replace character with character
// --------------------------------------------------------------------------------
const char* CSuperString::Replace(char chrLetterToFind, char chrReplace)
{
	static CSuperString ssResult;
	ssResult = "";
	long lngLength = Length();

	for (long lngIndex = 0; lngIndex < lngLength; lngIndex++)
	{
		if (m_pstrSuperString[lngIndex] == chrLetterToFind)
		{
			ssResult += chrReplace;
		}
		else
		{
			ssResult += m_pstrSuperString[lngIndex];
		}
	}

	return ssResult.ToString();
}

// --------------------------------------------------------------------------------
// Name: Replace #2
// Abstract: Replace substring with substring
// --------------------------------------------------------------------------------
const char* CSuperString::Replace(const char* pstrFind, const char* pstrReplace)
{
	static CSuperString ssResult;
	ssResult = "";
	long lngLength = Length();
	long lngFindLength = strlen(pstrFind);
	long lngIndex = 0;

	while (lngIndex < lngLength)
	{
		long lngFoundIndex = FindFirstIndexOf(pstrFind, lngIndex);
		
		if (lngFoundIndex == lngIndex)
		{
			//found match at current position
			ssResult += pstrReplace;
			lngIndex += lngFindLength;
		}
		else if (lngFoundIndex > lngIndex)
		{
			//Copy characters up to found position
			for (long i = lngIndex; i < lngFoundIndex; i++)
			{
				ssResult += m_pstrSuperString[i];
			}
			//Add replacement
			ssResult += pstrReplace;
			lngIndex = lngFoundIndex + lngFindLength;
		}
		else
		{
			//No more matches, copy rest of string
			for (long i = lngIndex; i < lngLength; i++)
			{
				ssResult += m_pstrSuperString[i];
			}
			break;
		}
	}

	return ssResult.ToString();
}
// --------------------------------------------------------------------------------
// Name: Insert #1
// Abstract: Insert character at index
// --------------------------------------------------------------------------------
const char* CSuperString::Insert(const char chrLetterToInsert, long lngIndex)
{
	char strSource[2] = { chrLetterToInsert, 0 };

	return Insert(strSource, lngIndex);
}
// --------------------------------------------------------------------------------
// Name: Insert #2
// Abstract: Insert substring at index
// --------------------------------------------------------------------------------
const char* CSuperString::Insert(const char* pstrSubString, long lngIndex)
{
	static CSuperString ssResult;
	ssResult = "";
	long lngLength = Length();

	//Copy characters before insertion point
	for (long i = 0; i < lngIndex && i < lngLength; i++)
	{
		ssResult += m_pstrSuperString[i];
	}

	//Insert substring
	ssResult += pstrSubString;

	//Copy remaining characters
	for (long i = lngIndex; i < lngLength; i++)
	{
		ssResult += m_pstrSuperString[i];
	}

	return ssResult.ToString();
}

// --------------------------------------------------------------------------------
// Name: Subscript operator #1
// Abstract: char
// --------------------------------------------------------------------------------
char& CSuperString::operator [ ] (long lngIndex)
{
	return m_pstrSuperString[lngIndex];
}

// --------------------------------------------------------------------------------
// Name: Subscript operator #2
// Abstract: const char
// --------------------------------------------------------------------------------
const char& CSuperString::operator [ ] (long lngIndex) const
{
	return m_pstrSuperString[lngIndex];
}

// --------------------------------------------------------------------------------
// Name: ToBoolean
// Abstract: convert to boolean
// --------------------------------------------------------------------------------
bool CSuperString::ToBoolean()
{
	bool blnResult = false;

	if (strcmp(m_pstrSuperString, "true") == 0 || strcmp(m_pstrSuperString, "1") == 0)
	{
		blnResult = true;
	}

	return blnResult;
}

// --------------------------------------------------------------------------------
// Name: ToShort
// Abstract: convert to short
// --------------------------------------------------------------------------------
short CSuperString::ToShort()
{
	return (short)atoi(m_pstrSuperString);
}

// --------------------------------------------------------------------------------
// Name: ToInteger
// Abstract: convert to integer
// --------------------------------------------------------------------------------
int CSuperString::ToInteger()
{
	return atoi(m_pstrSuperString);
}

// --------------------------------------------------------------------------------
// Name: ToLong
// Abstract: convert to long
// --------------------------------------------------------------------------------
long CSuperString::ToLong()
{
	return atol(m_pstrSuperString);
}

// --------------------------------------------------------------------------------
// Name: ToFloat
// Abstract: convert to float
// --------------------------------------------------------------------------------
float CSuperString::ToFloat()
{
	return (float)atof(m_pstrSuperString);
}

// --------------------------------------------------------------------------------
// Name: ToDouble
// Abstract: convert to double
// --------------------------------------------------------------------------------
double CSuperString::ToDouble()
{
	return atof(m_pstrSuperString);
}

// --------------------------------------------------------------------------------
// Name: Stream Output Operator
// Abstract: cout << ssBuffer
// --------------------------------------------------------------------------------
ostream & operator << (ostream & osOut, const CSuperString & ssOutput)
{
	osOut << ssOutput.m_pstrSuperString;
	return osOut;
}

// --------------------------------------------------------------------------------
// Name: Stream Input Operator
// Abstract: cin >> ssBuffer
// --------------------------------------------------------------------------------
istream& operator >> (istream& isIn, CSuperString& ssInput)
{
	char strBuffer[10000];
	isIn >> strBuffer;
	ssInput = strBuffer;
	return isIn;
}

// --------------------------------------------------------------------------------
// Name: Comparison Operator ==
// Abstract: Check if equal
// --------------------------------------------------------------------------------
bool operator == (const CSuperString& ssLeft, const CSuperString& ssRight)
{
	return strcmp(ssLeft.m_pstrSuperString, ssRight.m_pstrSuperString) == 0;
}

// --------------------------------------------------------------------------------
// Name: Comparison Operator !=
// Abstract: Check if not equal
// --------------------------------------------------------------------------------
bool operator != (const CSuperString& ssLeft, const CSuperString& ssRight)
{
	return !(ssLeft == ssRight);
}

// --------------------------------------------------------------------------------
// Name: Comparison Operator >
// Abstract: Check if greater than
// --------------------------------------------------------------------------------
bool operator > (const CSuperString& ssLeft, const CSuperString& ssRight)
{
	return strcmp(ssLeft.m_pstrSuperString, ssRight.m_pstrSuperString) > 0;
}

// --------------------------------------------------------------------------------
// Name: Comparison Operator <
// Abstract: Check if less than
// --------------------------------------------------------------------------------
bool operator < (const CSuperString& ssLeft, const CSuperString& ssRight)
{
	return strcmp(ssLeft.m_pstrSuperString, ssRight.m_pstrSuperString) < 0;
}

// --------------------------------------------------------------------------------
// Name: Comparison Operator >=
// Abstract: Check if greater than or equal
// --------------------------------------------------------------------------------
bool operator >= (const CSuperString& ssLeft, const CSuperString& ssRight)
{
	return (ssLeft > ssRight) || (ssLeft == ssRight);
}

// --------------------------------------------------------------------------------
// Name: Comparison Operator <=
// Abstract: Check if less than or equal
// --------------------------------------------------------------------------------
bool operator <= (const CSuperString& ssLeft, const CSuperString& ssRight)
{
	return (ssLeft < ssRight) || (ssLeft == ssRight);
}

// --------------------------------------------------------------------------------
// Name: DeepCopy
// Abstract: Memory-allocated copy
// --------------------------------------------------------------------------------
void CSuperString::DeepCopy(const char* pstrSource)
{
	m_pstrSuperString = CloneString(pstrSource);
}

// --------------------------------------------------------------------------------
// Name: CloneString
// Abstract: Make a copy of the string
// --------------------------------------------------------------------------------
char* CSuperString::CloneString(const char* pstrSource)
{
	char* pstrClone = 0;
	long lngLength = 0;

	//Null?
	if (pstrSource != 0)
	{
		//No
		lngLength = strlen(pstrSource);
		pstrClone = new char[lngLength + 1];
		strcpy_s(pstrClone, lngLength + 1, pstrSource);
	}
	else
	{
		//Yes, default to empty string
		pstrClone = new char[1];
		*(pstrClone + 0) = 0;
	}

	return pstrClone;
}

// --------------------------------------------------------------------------------
// Name: Deconstructor
// Abstract: Goodbye, cruel world
// --------------------------------------------------------------------------------
CSuperString::~CSuperString()
{
	CleanUp();
}

// --------------------------------------------------------------------------------
// Name: CleaUp
// Abstract: Every call to new must be paired with a call to delete
// --------------------------------------------------------------------------------
void CSuperString::CleanUp()
{
	DeleteString(m_pstrSuperString);
}

// --------------------------------------------------------------------------------
// Name: DeleteString
// Abstract: Delete the string and assign to pointer to zero
// --------------------------------------------------------------------------------
void CSuperString::DeleteString(char*& pstrSource)
{
	// Anything here?
	if (pstrSource != 0)
	{
		delete[] pstrSource;	// sell house
		pstrSource = 0;		// throw away the keys
	}
}

// --------------------------------------------------------------------------------
// Name: ToString
// Abstract: Tell me about yourself
// --------------------------------------------------------------------------------
const char* CSuperString::ToString() const
{
	return m_pstrSuperString;
}

// --------------------------------------------------------------------------------
// Name: Print
// Abstract: Print all the string with caption. Make testing easier
// --------------------------------------------------------------------------------
void CSuperString::Print(const char* pstrCaption) const
{
	// Caption
	cout << endl;
	cout << pstrCaption << endl;
	cout << "-----------------------------------" << endl;

	// Length not 0?
	if (Length() > 0)
	{
		// Yes, print string
		cout << m_pstrSuperString << endl;
	}
	else
	{
		// No, print empty string
		printf("-empty string\n");
	}

	cout << endl;
}