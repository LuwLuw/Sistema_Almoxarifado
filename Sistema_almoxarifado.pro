QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
RC_ICONS = icone.ico
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adicionar.cpp \
    atualizar.cpp \
    devolucao.cpp \
    main.cpp \
    pedidos.cpp \
    remover.cpp \
    tela_inicial.cpp

HEADERS += \
    adicionar.h \
    atualizar.h \
    devolucao.h \
    pedidos.h \
    quotedprintable.h \
    remover.h \
    tela_inicial.h

FORMS += \
    adicionar.ui \
    atualizar.ui \
    devolucao.ui \
    pedidos.ui \
    remover.ui \
    tela_inicial.ui

TRANSLATIONS += \
    Sistema_almoxarifado_pt_BR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



DISTFILES += \
    ReadMe.txt

