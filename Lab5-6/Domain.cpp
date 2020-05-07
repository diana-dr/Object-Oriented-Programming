#include "Domain.h"

Evidence::Evidence(): id{ "" }, measurement{ "" }, image_clarity_level{ 0 }, quantity{ 0 },
        photograph{ "" } {}

Evidence::Evidence(const std::string& id, const std::string& measurement,
                   float image_clarity_level, float quantity,
                   const std::string& photograph):
                   id{id}, measurement{measurement}, image_clarity_level{image_clarity_level},
                    quantity{quantity}, photograph{photograph}
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