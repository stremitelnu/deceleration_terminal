QT += widgets serialport

TARGET = terminal
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    console.cpp \
    protocol.cpp \
    cam_setup.cpp \
    settings_brake_distance.cpp

HEADERS += \
    mainwindow.h \
    settingsdialog.h \
    console.h \
    protocol.h \
    cam_setup.h \
    settings_brake_distance.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui \
    cam_setup.ui \
    settings_brake_distance.ui

RESOURCES += \
    terminal.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target
