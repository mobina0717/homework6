#ifndef PRINTER_H
#define PRINTER_H

#include "device.h"

class Printer : public Device {
public:
    Printer(const std::string& name, const std::string& manufacturer,
            int paperCount = 100, int inkLevel = 100);

    std::string getInfo() const override;
    bool connect() override;
    void printDocument(const std::string& docName);

    int getPaperCount() const { return m_paperCount; }
    int getInkLevel() const { return m_inkLevel; }
    void refillPaper(int count);
    void refillInk(int amount);

private:
    int m_paperCount;
    int m_inkLevel;
};

#endif // PRINTER_H
