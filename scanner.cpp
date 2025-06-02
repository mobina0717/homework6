#include "scanner.h"
#include <stdexcept>
#include <random>

Scanner::Scanner(const std::string& name, const std::string& manufacturer,
                 const std::string& resolution)
    : Device(name, manufacturer), m_resolution(resolution) {}

std::string Scanner::getInfo() const {
    return Device::getInfo() +
           "\nType: Scanner" +
           "\nResolution: " + m_resolution;
}

std::vector<uint8_t> Scanner::scanDocument(const std::string& docName) {
    if (!m_isConnected) {
        throw std::runtime_error("Scanner is not connected");
    }

    // Simulate scanning by generating random data
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    std::vector<uint8_t> scanData(1024 * 1024); // 1MB dummy data
    for (auto& byte : scanData) {
        byte = static_cast<uint8_t>(dis(gen));
    }

    return scanData;
}

void Scanner::setResolution(const std::string& resolution) {
    m_resolution = resolution;
}
