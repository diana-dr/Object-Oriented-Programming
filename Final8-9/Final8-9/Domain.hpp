#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Evidence
{
private:
	std::string id;
	std::string measurement;
	int image_clarity_level;
	int quantity;
	std::string photograph;

public:
	Evidence();
	~Evidence();

	Evidence(const std::string& id, const std::string& measurement,
		int image_clarity_level, int quantity,
		const std::string& photograph);

	std::string getId() const { return id; }
	std::string getMeasurement() const { return measurement; }
	int getImageClarity() const { return image_clarity_level; }
	int getQuantity() const { return quantity; }
	std::string getPhotograph() const { return photograph; }

	friend std::istream& operator>>(std::istream& is, Evidence& s);
	friend std::ostream& operator<<(std::ostream& os, const Evidence& s);
};

