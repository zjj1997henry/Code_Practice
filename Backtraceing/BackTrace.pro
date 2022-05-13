TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        fangtong.cpp \
        full_arrangement.cpp \
        main.cpp \
        nqueens.cpp \
        outstack.cpp \
        yanjiao.cpp

HEADERS += \
    fangtong.h \            #三国杀张梁方统技能
    full_arrangement.h \    #全排列
    nqueens.h \             #N皇后
    outstack.h \            #出栈顺序
    yanjiao.h               #三国杀张菖蒲严教技能
