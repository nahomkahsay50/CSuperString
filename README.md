# CSuperString

A custom C++ string class built from scratch using raw `char*` and manual heap memory management. Features operator overloading, type conversion, search, transformation, and substring methods — demonstrating core OOP principles without relying on the STL `string` type.

---

## Overview

`CSuperString` was built from scratch as a C++ final project to demonstrate manual heap memory management, deep copying, and operator overloading. It reimplements many of the conveniences of `std::string` using only `char*` under the hood — no STL string types.

---

## Files

| File | Description |
|---|---|
| `CSuperString.h` | Class declaration and interface |
| `CSuperString.cpp` | Full implementation |
| `FinalProject.cpp` | Test driver covering all features |
| `SET252FinalProject.sln` | Visual Studio solution file |
| `SET252FinalProject.vcxproj` | Visual Studio project file |

---

## Features

## Constructors
Supports construction from nearly any primitive type:

```cpp
CSuperString ss1;                  // Default (empty string)
CSuperString ss2("Hello World");   // const char*
CSuperString ss3(true);            // bool  → "true" / "false"
CSuperString ss4('X');             // char
CSuperString ss5((short) 32767);   // short
CSuperString ss6(42);              // int
CSuperString ss7(100L);            // long
CSuperString ss8(3.14f);           // float
CSuperString ss9(2.71828);         // double
CSuperString ss10(ss2);            // Copy constructor
```

# Assignment Operators
```cpp
ss = "Hello";   // const char*
ss = 'Z';       // char
ss = other;     // CSuperString (with self-assignment guard)
```

## Concatenation Operators
```cpp
ss += " World";     // += const char*
ss += '!';          // += char
ss += other;        // += CSuperString

CSuperString result = ss1 + ss2;        // SS + SS
CSuperString result = "Prefix" + ss;    // char* + SS
CSuperString result = ss + "Suffix";    // SS + char*
```

## Search Methods
```cpp
ss.FindFirstIndexOf('o');                    // First occurrence of char
ss.FindFirstIndexOf('o', 5);                 // Search starting at index
ss.FindLastIndexOf('o');                     // Last occurrence of char
ss.FindFirstIndexOf("Star");                 // First occurrence of substring
ss.FindFirstIndexOf("Star", 5);              // Substring search with offset
ss.FindLastIndexOf("Star");                  // Last occurrence of substring
```

## Transformation Methods
These return a new string and do **not** modify the original:
```cpp
ss.ToUpperCase();   // "i love c++"  →  "I LOVE C++"
ss.ToLowerCase();   // "I LOVE C++"  →  "i love c++"
ss.TrimLeft();      // Strips leading whitespace
ss.TrimRight();     // Strips trailing whitespace
ss.Trim();          // Strips both ends
ss.Reverse();       // "Hello"  →  "olleH"
```

## Substring Extraction
```cpp
ss.Left(5);               // First 5 characters
ss.Right(5);              // Last 5 characters
ss.Substring(2, 4);       // 4 characters starting at index 2
ss.Length();              // Returns character count
```

### Replace & Insert
```cpp
ss.Replace('o', 'O');                      // Replace all char occurrences
ss.Replace("Love", "Really Love");         // Replace substring
ss.Insert('!', 16);                        // Insert char at index
ss.Insert(" So Much", 16);                 // Insert substring at index
```

## Subscript Operator
```cpp
char c = ss[0];     // Read access
ss[0] = 'J';        // Write access
```

## Type Conversion
```cpp
ss.ToString();      // const char*
ss.ToBoolean();     // "true"/"1" → true, else false
ss.ToShort();
ss.ToInteger();
ss.ToLong();
ss.ToFloat();
ss.ToDouble();
```

## Stream Operators
```cpp
cout << ss;    // Output
cin  >> ss;    // Input
```

## Comparison Operators
Comparisons use ASCII ordering via `strcmp`:
```cpp
ss1 == ss2
ss1 != ss2
ss1 <  ss2
ss1 >  ss2
ss1 <= ss2
ss1 >= ss2
```

---

## Memory Management

`CSuperString` manages its own heap memory manually:

- Every constructor funnels through `Initialize()` → `operator=` → `DeepCopy()` → `CloneString()` to allocate and copy the string.
- The destructor calls `CleanUp()` → `DeleteString()`, which safely deletes and nulls the internal pointer.
- Self-assignment is guarded in `operator=` to avoid freeing memory that is still in use.

---

## Building

This project targets **Windows / MSVC** and uses `sprintf_s`, `strcpy_s`, and `strcat_s`. To build:

1. Open `SET252FinalProject.sln` in **Visual Studio** and run, or
2. Compile from the command line:

```
cl FinalProject.cpp CSuperString.cpp /Fe:CSuperStringDemo.exe
```

> For cross-platform use, the `_s` safe string functions would need to be swapped for their standard equivalents (`sprintf`, `strcpy`, `strcat`).

---

## Running the Tests

`FinalProject.cpp` contains a comprehensive test driver that exercises every feature:

| Test Function | What It Covers |
|---|---|
| `ConstructorTests()` | All parameterized constructors |
| `AssignmentOperatorTests()` | Assignment with all types + self-assignment |
| `ConcatenationTest()` | `+=` and `+` operator variants |
| `FindTests()` | `FindFirstIndexOf` / `FindLastIndexOf` |
| `TransformationTests()` | Case, trim, reverse |
| `SubstringTests()` | Left, Right, Substring, Length |
| `ReplaceinsertTests()` | Replace and Insert |
| `SubscriptTests()` | Read and write via `[]` |
| `ConversionTests()` | All `ToXxx()` methods |
| `StreamTests()` | `<<` and `>>` |
| `ComparisonTests()` | All six comparison operators |

---

## Author

**Nahom Kahsay** — SET-252-400, Final Project
