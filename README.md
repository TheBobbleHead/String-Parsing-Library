# String Parsing Library
[![Build](https://github.com/TheBobbleHead/String-Parsing-Library/actions/workflows/cmake.yml/badge.svg)](https://github.com/TheBobbleHead/String-Parsing-Library/actions/workflows/cmake.yml)

## Use Cases
It is important to know what this library is meant and capable of before use.
This library helps in the prosses of parsing strings by seperating strings into a list of substrings refered to as Chunked Strings.

### Here are some situations where you might use this library

If you need to get a list of words used in a text file you might write something like this:

```cpp
StringParser StringHelper(&TextFromFile);
StringHelper.SeperateString(' ', false);

for (int i = 0; i < StringHelper.ChunkedString->size(); i++) {
	std::cout << StringHelper.ChunkedString->at(i) << std::endl;
}
```

This chunk of code will seperate every chunk of text that is seperated by a space char

Program In: `This text will be seperated`

Program Out:
`This`
`text`
`will`
`be`
`seperated`

This is only a basic example but it shows the power of what this library can do
if you wanted for some reason to include the space char in the chunks you could change:
`StringHelper.SeperateString(' ', false)`
to:
`StringHelper.SeperateString(' ', true)`

This would then append the space char to the end of string chunk

If you where witing your own scripting language and wanted to get a list of instructions as strings you could wirte this:

```cpp
StringParser.StringHelper(&Script);
StringHelper.SeperateString(';', false);

for (int i = 0; i < StringHelper.ChunkedString->size(); i++) {
	std::cout << StringHelper.ChunkedString->at(i) << std::endl;
}
```

Program In:
```
make new object;
modify object;
print object;
```

Program Out:
`make new object`
`modify object`
`print object`

This only covers a small part of what you can do with this library, so to see how to use it see the section below.

## Usage Guide
The basic idea for how the `StringParser` class works is that it takes a pointer to the string you want to opperate on, then after you have
run all of the prossesing functions on this string you take a list of strings in the form of a `std::vector<std::string>` declorated as `ChunkedString`, which is the outputed data.
Note that the `StringParser` class will not modify the contents of the string given as input.

### `StringParser` Setup and States
Setting up `StringParser` properly is vital for getting the results that you want when parsing.
To start you want to create an instance of `StringParser`.
To create an instance you want to pass a pointer to your input string as a parameter like so `StringParser StringHelper(&InputStringPointer)`
Then set the state and options of that instance as seen below. 

#### Ignore Chars
The following funtion `StringParser::AddIgnoreChar(char Ignore)` adds the inputed char to a list of chars the the parser will completely remove from output when parsing.
But in order for `StringParser` to ignore any chars in the list while parsing you have to make sure that `StringParser::IgnoreCharsEnabled` is set to `true`.

#### Grouping Chars
A Grouping Char is a specified char that tells the parser to ignore seperators when inside two of that char.
For example this would be a use case to add a grouping char: `hey "Every thing in these qoutes will be in one string"`.
output:
`hey`
`Every thing in these qoutes will be in one string`
If you add `"` as a grouping char then the parser will not split the string up even if there is seperator chars within the group.

To add a grouping char you would run the function `StringParser::AddGroupingChar(char GroupingChar_, bool IncludeThisChar)`
`GroupingChar_` of corse is the grouping char to add, but `IncludeThisChar` tells the parser wether or not to include the grouping char in the string if it gets
split.
The setting `StringParser::IgnoreSeperatorInGroup` if set to true will not include seperators in a split string if they are inside a group.

#### Extra Seperators
If you want to remove any extra seperators in your string, for example `this string  has    to  many   seperators`.
You can enable the option `StringParser::ngnoreExtraSeperators` by setting it to `true`
This then results in the output: `this` `string` `has` `to` `many` `seperators`.

### Parsing
Now that you have setup the `StringParser` Instance to your need and liking you can now call a single function to parse the provided string.
Call `StringParser::SeperateString(char Seperator, bool IncludeSeperator)`. The `Seperator` param is the char that will divide up your string for example Engilsh words
are seperated by a space so is you want to get each word in it's own string you would put ` ` in as the Seprator. The `IncludeSeperator` param will append the seperator
at the end of a seperated string.

After you have called the function you can access the split up string or (ChunkedString) by acessing `StringParser::ChunkedString`.
And there you have it you provide a string to the parser then setup the prossesing options then divide the string up to help with parsing.

##installation

####There are a few ways that you can install this library for your program

First you can use [CMake](https://cmake.org) and add this project as a subdirectory and link it to your project.

Second you can download the realese binary and link it to your library in any way you choose.

Third you can copy the header and source files into your project and compile with your project. Which
is probably the easiest way since this library dose not have any third party dependancies, appart from the standard template library.