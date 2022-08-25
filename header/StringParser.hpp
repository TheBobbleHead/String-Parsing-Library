//MIT License
//
//Copyright(c) 2022 Sean Vos
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this softwareand associated documentation files(the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions :
//
//The above copyright noticeand this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.


#include <string>
#include <vector>

class StringParser {

	struct GroupingChar {
		char Char = NULL;
		bool IncludeChar = false;
	};

	struct GroupingCharPiar {
		char OpeningChar = NULL;
		char ClosingChar = NULL;

		bool IncludeOpening = false;
		bool IncludeClosing = false;

		bool operator == (GroupingCharPiar GroupingPair);
	};

	struct Seperator {
		char Char =  NULL;
		bool Include = false;

		bool operator == (char CompareChar);
	};

private:

	std::vector<GroupingChar> GroupingChars;
	std::vector<GroupingCharPiar> GroupingCharPiars;
	std::vector<char> IgnoreChars;
	std::vector<Seperator> Seperators;

public:

	std::string operator [] (const int &Index);

	StringParser(std::string* UseString);

	std::string* String;
	std::vector<std::string>* ChunkedString;

	bool IgnoreCharsEnabled = false;
	bool IgnoreSeperatorInGroup = false;
	bool IngnoreExtraSeperators = false;
	//bool SplitNestedGroups = false;

	void SeperateString(char Seperator, bool IncludeSeperator);

	void AddGroupingChar(char GroupingChar_, bool IncludeThisChar);
	void AddGroupingCharPair(char OpenChar, char ClosingChar, bool IncludeOpen, bool IncludeClose);
	void RemoveGroupingChar(char GroupingChar);
	void RemoveGroupingCharPair(char OpenChar, char ClosingChar);
	void ClearGroupingChars();

	void AddIgnoreChar(char Ignore);
	void RemoveIgnoreChar(char IgnoreRM);
	void ClearIgnoreChars();

	void AddSeperator(char Char, bool IncludeChar);
	void RemoveSeperator(char Char);

	void ClearChunkedString();
	void ClearAll();

	~StringParser();
};