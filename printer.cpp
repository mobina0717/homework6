#include "printer.h"
#include <stdexcept>

Printer::Printer(const std::string& name, const std::string& manufacturer,
                 int paperCount, int inkLevel)
    : Device(name, manufacturer), m_paperCount(paperCount), m_inkLevel(inkLevel) {}

std::string Printer::getInfo() const {
    return Device::getInfo() +
           "\nType: Printer" +
           "\nPaper Count: " + std::to_string(m_paperCount) +
           "\nInk Level: " + std::to_string(m_inkLevel) + "%";
}

bool Printer::connect() {
    if (m_inkLevel <= 0 || m_paperCount <= 0) {
        return false;
    }
    return Device::connect();
}

void Printer::printDocument(const std::string& docName) {
    if (!m_isConnected) {
        throw std::runtime_error("Printer is not connected");
    }
    if (m_paperCount <= 0) {
        throw std::runtime_error("Out of paper");
    }
    if (m_inkLevel <= 0) {
        throw std::runtime_error("Out of ink");
    }

    m_paperCount--;
    m_inkLevel = std::max(0, m_inkLevel - 2);
}

void Printer::refillPaper(int count) {
    m_paperCount += count;
}

void Printer::refillInk(int amount) {
    m_inkLevel = std::min(100, m_inkLevel + amount);
}
