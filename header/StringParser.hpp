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