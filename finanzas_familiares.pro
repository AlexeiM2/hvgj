QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acerca.cpp \
    agregar_miembro.cpp \
    main.cpp \
    pantalla_principal.cpp \
    register.cpp \
    usuario.cpp \
    widget.cpp

HEADERS += \
    acerca.h \
    agregar_miembro.h \
    pantalla_principal.h \
    register.h \
    usuario.h \
    widget.h

FORMS += \
    acerca.ui \
    agregar_miembro.ui \
    pantalla_principal.ui \
    register.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    file.qrc \
    icons.qrc \
    images.qrc

DISTFILES +=
