QT       += core gui sql multimedia printsupport charts network serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT       += core gui network
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    activite.cpp \
    admin.cpp \
    aide.cpp \
    anim.cpp \
    animal.cpp \
    arduino.cpp \
    boutique.cpp \
    calculator.cpp \
    connection.cpp \
    contact.cpp \
    cuisine.cpp \
    enfant.cpp \
    fiche_animal.cpp \
    fourniture.cpp \
    ingr.cpp \
    ingredient.cpp \
    login.cpp \
    mailing.cpp \
    main.cpp \
    mainwindow.cpp \
    medicament.cpp \
    menu.cpp \
    note.cpp \
    notification.cpp \
    pinter.cpp \
    prestataire.cpp \
    programme.cpp \
    sante.cpp \
    securite.cpp \
    statistics.cpp \
    suivi.cpp \
    vetement.cpp

HEADERS += \
    activite.h \
    admin.h \
    aide.h \
    anim.h \
    animal.h \
    arduino.h \
    boutique.h \
    calculator.h \
    connection.h \
    contact.h \
    cuisine.h \
    enfant.h \
    fiche_animal.h \
    fourniture.h \
    ingr.h \
    ingredient.h \
    login.h \
    mailing.h \
    mainwindow.h \
    medicament.h \
    menu.h \
    note.h \
    notification.h \
    pinter.h \
    prestataire.h \
    programme.h \
    sante.h \
    securite.h \
    statistics.h \
    suivi.h \
    vetement.h
FORMS += \
    aide.ui \
    animal.ui \
    calculator.ui \
    capteur_dincendie.ui \
    contact.ui \
    cuisine.ui \
    login.ui \
    mailing.ui \
    mainwindow.ui \
    menu.ui \
    note.ui \
    pinter.ui \
    programme.ui \
    sante.ui \
    securite.ui \
    statistics.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
  RC_ICONS = Ic.ico

RESOURCES += \
    Resource.qrc \
    traducion.qrc
