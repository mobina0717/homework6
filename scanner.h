#ifndef SCANNER_H
#define SCANNER_H

#include "device.h"
#include <vector>

class Scanner : public Device {
public:
    Scanner(const std::string& name, const std::string& manufacturer,
            const std::string& resolution = "1200dpi");

    std::string getInfo() const override;
    std::vector<uint8_t> scanDocument(const std::string& docName);

    void setResolution(const std::string& resolution);
    std::string getResolution() const { return m_resolution; }

private:
    std::string m_resolution;
};

#endif // SCANNER_H
