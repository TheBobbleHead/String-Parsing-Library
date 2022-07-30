#include "StringParser.hpp"
#include <iostream>

int main(int argc, char** argv) {
	char TestNumber = NULL;
	if (argc > 1) {
		TestNumber = *argv[1];
		std::cout << "TestParam = " << TestNumber << " of " << argc << std::endl;
	}
	else {
		std::cout << "Enter test number: ";
		std::cin >> TestNumber;
	}

	if (TestNumber != NULL) { 
		//basic string seperation test
		if (TestNumber == '1') {

			std::string TestString = "this is a test string";
			StringParser StringHelper(&TestString);

			StringHelper.SeperateString(' ', false);

			std::string SegmentedString[5];
			SegmentedString[0] = "this";
			SegmentedString[1] = "is";
			SegmentedString[2] = "a";
			SegmentedString[3] = "test";
			SegmentedString[4] = "string";

			if (StringHelper.ChunkedString->size() != 5) {
				std::cout << "Error: Seperation error -> amount of strings dose not match" << std::endl;
				return 2; 
			}

			for (int i = 0; i < StringHelper.ChunkedString->size(); i++) {
				if (StringHelper.ChunkedString->at(i) != SegmentedString[i]) {
					std::cout << "Error: Seperation error -> found unmatching string" << std::endl;
					return 1;
				}
			}

			return 0;
		}
		else if (TestNumber == '2') {

			//string seperation with groups test
			std::string TestString = "|this string| is to \"test groups\"";
			StringParser StringHelper(&TestString);

			StringHelper.AddGroupingChar('|', false);
			StringHelper.AddGroupingChar('\"', false);

			StringHelper.SeperateString(' ', false);

			std::string SegmentedString[4];
			SegmentedString[0] = "this string";
			SegmentedString[1] = "is";
			SegmentedString[2] = "to";
			SegmentedString[3] = "test groups";

			if (StringHelper.ChunkedString->size() != 4) {
				std::cout << "Error: Seperation error -> amount of strings dose not match" << std::endl;
				return 2;
			}

			for (int i = 0; i < StringHelper.ChunkedString->size(); i++) {
				if (StringHelper.ChunkedString->at(i) != SegmentedString[i]) {
					std::cout << "Error: Seperation error -> found unmatching string" << std::endl;
					return 1;
				}
			}

			return 0;

		}
		else if (TestNumber == '3') {

			//string seperation with ignore chars
			std::string TestString = "1this stri2ng is to te3st ign4ore chars";
			StringParser StringHelper(&TestString);

			StringHelper.AddIgnoreChar('1');
			StringHelper.AddIgnoreChar('2');
			StringHelper.AddIgnoreChar('3');
			StringHelper.AddIgnoreChar('4');

			StringHelper.IgnoreCharsEnabled = true;

			StringHelper.SeperateString(' ', false);

			std::string SegmentedString[7];
			SegmentedString[0] = "this";
			SegmentedString[1] = "string";
			SegmentedString[2] = "is";
			SegmentedString[3] = "to";
			SegmentedString[4] = "test";
			SegmentedString[5] = "ignore";
			SegmentedString[6] = "chars";

			if (StringHelper.ChunkedString->size() != 7) {
				std::cout << "Error: Seperation error -> amount of strings dose not match" << std::endl;
				return 2;
			}

			for (int i = 0; i < StringHelper.ChunkedString->size(); i++) {
				if (StringHelper.ChunkedString->at(i) != SegmentedString[i]) {
					std::cout << "Error: Seperation error -> found unmatching string" << std::endl;
					return 1;
				}
			}

			return 0;
		}
		else if (TestNumber == '4') {

			//string seperation that ignores extra seperator
			std::string TestString = "this  string   tests     extra      seperators";
			StringParser StringHelper(&TestString);

			StringHelper.IngnoreExtraSeperators = true;

			StringHelper.SeperateString(' ', false);
			std::string SegmentedString[5];
			SegmentedString[0] = "this";
			SegmentedString[1] = "string";
			SegmentedString[2] = "tests";
			SegmentedString[3] = "extra";
			SegmentedString[4] = "seperators";

			if (StringHelper.ChunkedString->size() != 5) {
				std::cout << "Error: Seperation error -> amount of strings dose not match" << std::endl;
				return 2;
			}

			for (int i = 0; i < StringHelper.ChunkedString->size(); i++) {
				if (StringHelper.ChunkedString->at(i) != SegmentedString[i]) {
					std::cout << "Error: Seperation error -> found unmatching string" << std::endl;
					return 1;
				}
			}

			return 0;
		}
		else if (TestNumber == '5') {
			std::string TestString = "this string |tests \"interconnected groups\"|";
			StringParser StringHelper(&TestString);

			StringHelper.AddGroupingChar('|', false);
			StringHelper.AddGroupingChar('\"', false);

			StringHelper.SeperateString(' ', false);

			std::string SegmentedString[3];
			SegmentedString[0] = "this";
			SegmentedString[1] = "string";
			SegmentedString[2] = "tests \"interconnected groups\"";

			if (StringHelper.ChunkedString->size() != 3) {
				std::cout << "Error: Seperation error -> amount of strings dose not match" << std::endl;
				return 2;
			}

			for (int i = 0; i < StringHelper.ChunkedString->size(); i++) {
				if (StringHelper.ChunkedString->at(i) != SegmentedString[i]) {
					std::cout << "Error: Seperation error -> found unmatching string" << std::endl;
					return 1;
				}
			}

			return 0;
		}
		else {
			std::cout << "Error invalid argumnet: " << std::endl;
			return 100;
		}
	}
	else {
		std::cout << "Error TestNumber param is equal to NULL" << std::endl;
	}

	return 101;
}