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

Rpogram Out:
`make new object`
`modify object`
`print object`

This only covers a small part of what you can do with this library, so to see how to use it see the section below

## Usage Guide