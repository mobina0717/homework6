#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <memory>

class Device {
public:
    Device(const std::string& name, const std::string& manufacturer);
    virtual ~Device() = default;

    virtual std::string getInfo() const;
    virtual bool connect();
    virtual void disconnect();

    std::string getName() const { return m_name; }
    std::string getManufacturer() const { return m_manufacturer; }
    bool isConnected() const { return m_isConnected; }

protected:
    std::string m_name;
    std::string m_manufacturer;
    bool m_isConnected = false;
};

#endif // DEVICE_H
