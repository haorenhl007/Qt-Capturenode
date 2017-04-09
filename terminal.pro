QT += widgets serialport sql core gui axcontainer testlib svg

TARGET = terminal
TEMPLATE = app

DEFINES += QT_DLL QWT_DLL

LIBS += -L"C:\Qt\Qt5.6.0\5.6\mingw49_32\lib" -lqwtd
LIBS += -L"C:\Qt\Qt5.6.0\5.6\mingw49_32\lib" -lqwt

INCLUDEPATH += C:\Qt\Qt5.6.0\5.6\mingw49_32\include\qwt

RC_FILE  += resource/RCFile.rc

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    hismainwin.cpp \
    datathread.cpp

HEADERS += \
    connectdb.h \
    hismainwin.h \
    mainwindow.h \
    mastermsg.h \
    datathread.h \
    pointerapp.h \
    settingsdialog.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui \
    hismainwin.ui

RESOURCES += \
    terminal.qrc
