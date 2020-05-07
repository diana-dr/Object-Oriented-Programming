#define _CRT_SECURE_NO_WARNINGS
#include "Domain.hpp"
#include <sstream>
#include <vector>

Evidence::Evidence() : id{ "" }, measurement{ "" }, image_clarity_level{ 0 }, quantity{ 0 },
photograph{ "" } {}

Evidence::Evidence(const std::string& id, const std::string& measurement,
                   float image_clarity_level, float quantity,
                   const std::string& photograph) :
id{ id }, measurement{ measurement }, image_clarity_level{ image_clarity_level },
quantity{ quantity }, photograph{ photograph }
{
    this->id = id;
    this->measurement = measurement;
    this->image_clarity_level = image_clarity_level;
    this->quantity = quantity;
    this->photograph = photograph;
}

Evidence::~Evidence()
{
}

void Evidence::setMeasurement(const std::string& new_measurement)
{
    this->measurement = new_measurement;
}

void Evidence::setPhotograph(const std::string& new_photograph)
{
    this->photograph = new_photograph;
}

void Evidence::setImageClarity(float new_image_clarity_level)
{
    this->image_clarity_level = new_image_clarity_level;
}
void Evidence::setQuantity(float new_quantity)
{
    this->quantity = new_quantity;
}

vector<string> tokenize(string str, char delimiter)
{
    vector <string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);
    
    return result;
}

std::istream & operator>>(std::istream & is, Evidence & evidence)
{
    std::string line;
    getline(is, line);
    
    std::vector<std::string> tokens = tokenize(line, ',');
    if (tokens.size() != 5)
        return is;
    
    evidence.id = tokens[0];
    evidence.measurement = tokens[1];
    evidence.image_clarity_level = std::stoi(tokens[2]);
    evidence.quantity = std::stoi(tokens[3]);
    evidence.photograph = tokens[4];
    
    return is;
}

std::ostream & operator<<(std::ostream & os, const Evidence & evidence)
{
    os << evidence.id << "," << evidence.measurement << "," << evidence.image_clarity_level << "," << evidence.quantity
    << "," << evidence.photograph << "\n";
    return os;
}
