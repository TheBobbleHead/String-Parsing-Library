/*
https://github.com/TheBobbleHead/String-Parsing-Library
* MIT License

Copyright (c) 2022 Sean Robbert Vos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/



#include <string>
#include <vector>

class StringParser {

	struct GroupingChar
	{
		char Char = NULL;
		bool IncludeChar = false;
	};

private:

	std::vector<GroupingChar> GroupingChars;
	std::vector<char> IgnoreChars;

public:

	StringParser(std::string* UseString);

	std::string* String;
	std::vector<std::string>* ChunkedString;

	bool IgnoreCharsEnabled = false;
	bool IgnoreSeperatorInGroup = false;
	bool IngnoreExtraSeperators = false;
	//bool SplitNestedGroups = false;

	void SeperateString(char Seperator, bool IncludeSeperator);
	void AddGroupingChar(char GroupingChar_, bool IncludeThisChar);
	void RemoveGroupingChar(char GroupingChar);
	void ClearGroupingChars();
	void AddIgnoreChar(char Ignore);
	void RemoveIgnoreChar(char IgnoreRM);
	void ClearIgnoreChars();

	void ClearChunkedString();

	void ClearAll();
};