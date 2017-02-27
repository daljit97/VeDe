#-------------------------------------------------
#
# Project created by QtCreator 2016-11-17T00:18:38
#
#-------------------------------------------------

#include(../VeDe-Graphics/VeDe-Graphics.pro)

QT       += core gui

#DEFINES += DEBUG

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VeDe
TEMPLATE = app

unix {
    QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
    QMAKE_CXXFLAGS_WARN_ON += -Wno-sign-compare
}

SOURCES += main.cpp\
        mainwindow.cpp \
    qtcustompainter.cpp \
    toolaction.cpp \
    workspace.cpp \
    propertyconverter.cpp \
    canvasimpl.cpp \
    currtooltoolbar.cpp \
    colorchangebutton.cpp \
    propertywidgetfactory.cpp \
    objects/basegraphicsitem.cpp \
    objects/ellipsegraphicsitem.cpp \
    objects/linegraphicsitem.cpp \
    objects/rectgraphicsitem.cpp \
    objects/pathgraphicsitem.cpp \
    objects/guidrawer.cpp

HEADERS  += mainwindow.h \
    qtcustompainter.h \
    toolaction.h \
    workspace.h \
    propertyconverter.h \
    canvasimpl.h \
    currtooltoolbar.h \
    colorchangebutton.h \
    propertywidgetfactory.h \
    objects/basegraphicsitem.h \
    objects/ellipsegraphicsitem.h \
    objects/rectgraphicsitem.h \
    objects/linegraphicsitem.h \
    objects/pathgraphicsitem.h \
    objects/guidrawer.h

FORMS    +=

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-vede-graphics/release/ -lVeDe-Graphics
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-vede-graphics/debug/ -lVeDe-Graphics
#else:unix: LIBS += -L$$PWD/../build-vede-graphics/ -lVeDe-Graphics

#INCLUDEPATH += $$PWD/../VeDe-Graphics
#INCLUDEPATH += $$PWD/../VeDe-Graphics/objects
#INCLUDEPATH += $$PWD/../VeDe-Graphics/commands
#INCLUDEPATH += $$PWD/../VeDe-Graphics/tools
#DEPENDPATH += $$PWD/../VeDe-Graphics

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-vede-graphics/release/libVeDe-Graphics.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-vede-graphics/debug/libVeDe-Graphics.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-vede-graphics/release/VeDe-Graphics.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-vede-graphics/debug/VeDe-Graphics.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../build-vede-graphics/libVeDe-Graphics.a

RESOURCES += \
    images.qrc

DISTFILES +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../tt/build-vede-graphics-debug/release/ -lVeDe-Graphics
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../tt/build-vede-graphics-debug/debug/ -lVeDe-Graphics
else:unix: LIBS += -L$$PWD/../../../../tt/build-vede-graphics-debug/ -lVeDe-Graphics

INCLUDEPATH += $$PWD/../../../../tt/VeDe-Graphics
DEPENDPATH += $$PWD/../../../../tt/VeDe-Graphics

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../tt/build-vede-graphics-debug/release/libVeDe-Graphics.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../tt/build-vede-graphics-debug/debug/libVeDe-Graphics.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../tt/build-vede-graphics-debug/release/VeDe-Graphics.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../tt/build-vede-graphics-debug/debug/VeDe-Graphics.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../tt/build-vede-graphics-debug/libVeDe-Graphics.a
