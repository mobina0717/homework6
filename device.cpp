#include "device.h"

Device::Device(const std::string& name, const std::string& manufacturer)
    : m_name(name), m_manufacturer(manufacturer) {}

std::string Device::getInfo() const {
    return "Device: " + m_name +
           "\nManufacturer: " + m_manufacturer +
           "\nStatus: " + (m_isConnected ? "Connected" : "Disconnected");
}

bool Device::connect() {
    m_isConnected = true;
    return true;
}

void Device::disconnect() {
    m_isConnected = false;
}
