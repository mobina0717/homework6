#include "deviceui.h"
#include "printer.h"
#include "scanner.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QTextEdit>
#include <QPushButton>

DeviceUI::DeviceUI(QWidget *parent) : QWidget(parent) {
    setupUI();
}

DeviceUI::~DeviceUI() = default;

void DeviceUI::setupUI() {
    // Create widgets
    m_deviceList = new QListWidget(this);
    m_infoDisplay = new QTextEdit(this);
    m_infoDisplay->setReadOnly(true);

    m_addButton = new QPushButton("Add Device", this);
    m_removeButton = new QPushButton("Remove Device", this);
    m_infoButton = new QPushButton("Show Info", this);
    m_connectButton = new QPushButton("Connect", this);
    m_disconnectButton = new QPushButton("Disconnect", this);
    m_actionButton = new QPushButton("Perform Action", this);

    // Layouts
    m_mainLayout = new QVBoxLayout(this);
    m_buttonLayout = new QHBoxLayout();

    m_buttonLayout->addWidget(m_addButton);
    m_buttonLayout->addWidget(m_removeButton);
    m_buttonLayout->addWidget(m_infoButton);
    m_buttonLayout->addWidget(m_connectButton);
    m_buttonLayout->addWidget(m_disconnectButton);
    m_buttonLayout->addWidget(m_actionButton);

    m_mainLayout->addWidget(m_deviceList);
    m_mainLayout->addWidget(m_infoDisplay);
    m_mainLayout->addLayout(m_buttonLayout);

    setLayout(m_mainLayout);
    setWindowTitle("Office Device Manager");

    // Connections
    connect(m_addButton, &QPushButton::clicked, this, &DeviceUI::addDevice);
    connect(m_removeButton, &QPushButton::clicked, this, &DeviceUI::removeDevice);
    connect(m_infoButton, &QPushButton::clicked, this, &DeviceUI::showDeviceInfo);
    connect(m_connectButton, &QPushButton::clicked, this, &DeviceUI::connectDevice);
    connect(m_disconnectButton, &QPushButton::clicked, this, &DeviceUI::disconnectDevice);
    connect(m_actionButton, &QPushButton::clicked, this, &DeviceUI::performDeviceAction);
}

void DeviceUI::addDevice() {
    QStringList deviceTypes = {"Printer", "Scanner"};
    bool ok;
    QString deviceType = QInputDialog::getItem(this, "Add Device",
                                               "Select device type:",
                                               deviceTypes, 0, false, &ok);

    if (!ok || deviceType.isEmpty()) return;

    try {
        if (deviceType == "Printer") {
            m_devices.append(std::make_unique<Printer>("Office Printer", "HP"));
        } else {
            m_devices.append(std::make_unique<Scanner>("Office Scanner", "Epson"));
        }
        updateDeviceList();
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void DeviceUI::removeDevice() {
    int index = m_deviceList->currentRow();
    if (index >= 0 && index < m_devices.size()) {
        m_devices.remove(index);
        updateDeviceList();
    }
}

void DeviceUI::showDeviceInfo() {
    int index = m_deviceList->currentRow();
    if (index >= 0 && index < m_devices.size()) {
        m_infoDisplay->setText(QString::fromStdString(m_devices[index]->getInfo()));
    }
}

void DeviceUI::connectDevice() {
    int index = m_deviceList->currentRow();
    if (index >= 0 && index < m_devices.size()) {
        if (m_devices[index]->connect()) {
            m_infoDisplay->append("\nDevice connected successfully");
        } else {
            m_infoDisplay->append("\nFailed to connect device");
        }
    }
}

void DeviceUI::disconnectDevice() {
    int index = m_deviceList->currentRow();
    if (index >= 0 && index < m_devices.size()) {
        m_devices[index]->disconnect();
        m_infoDisplay->append("\nDevice disconnected");
    }
}

void DeviceUI::performDeviceAction() {
    int index = m_deviceList->currentRow();
    if (index < 0 || index >= m_devices.size()) return;

    try {
        if (auto printer = dynamic_cast<Printer*>(m_devices[index].get())) {
            printer->printDocument("Document1");
            m_infoDisplay->append("\nPrinted document successfully");
        } else if (auto scanner = dynamic_cast<Scanner*>(m_devices[index].get())) {
            auto scanData = scanner->scanDocument("scan1");
            m_infoDisplay->append("\nScanned document. Size: " +
                                  QString::number(scanData.size()) + " bytes");
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Action Failed", e.what());
    }
}

void DeviceUI::updateDeviceList() {
    m_deviceList->clear();
    for (const auto& device : m_devices) {
        QString type = dynamic_cast<Printer*>(device.get()) ? "Printer" : "Scanner";
        m_deviceList->addItem(type + ": " + QString::fromStdString(device->getName()));
    }
}
