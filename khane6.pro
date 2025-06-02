QT       += core gui
QT += widgets
SOURCES += main.cpp device.cpp printer.cpp scanner.cpp deviceui.cpp \
    device.cpp \
    printer.cpp \
    scanner.cpp
HEADERS += device.h printer.h scanner.h deviceui.h

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DeviceUI.cpp \
    main.cpp

HEADERS += \
    DeviceUI.h \
    device.h \
    printer.h \
    scanner.h

FORMS += \
    DeviceUI.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
