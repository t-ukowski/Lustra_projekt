#pragma once
#include <string>
class ObjectStrings {
	int height;
	int width;
public:
	int** objects;
	ObjectStrings();
	ObjectStrings(int h, int w);
	~ObjectStrings();

	ObjectStrings& operator= (const ObjectStrings& o);


	void add(int val, int i, int j);

	void clear();

	std::string stringify(std::string, int, int);

	std::string commonPart(std::string, std::string, int);
};

