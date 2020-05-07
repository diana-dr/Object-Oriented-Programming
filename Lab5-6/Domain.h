#include <iostream>

class Evidence
{
private:
    std::string id;
    std::string measurement;
    float image_clarity_level;
    float quantity;
    std::string photograph;

public:
    Evidence();
    ~Evidence();

    Evidence(const std::string& id, const std::string& measurement,
            float image_clarity_level, float quantity,
            const std::string& photograph);

    const std::string& getId() const { return id; }
    const std::string& getMeasurement() const { return measurement; }
    float getImageClarity() const { return image_clarity_level; }
    float getQuantity() const { return quantity; }
    const std::string& getPhotograph() const { return photograph; }
    void setMeasurement(const std::string& measurement);
    void setPhotograph(const std::string& photograph);
    void setImageClarity(float image_clarity_level);
    void setQuantity(float quantity);
};
