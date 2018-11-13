TARGET = "Depressia"

QT += core \
    widgets

SOURCES += \
    logic/entities/entity.cpp \
    logic/items/item.cpp \
    logic/skills/skill.cpp \
    logic/skills/recover.cpp \
    logic/skills/aftermath.cpp \
    gui/stage.cpp \
    io/entityloader.cpp \
    main.cpp \
    logic/fight.cpp

HEADERS += \
    logic/entities/entity.h \
    logic/items/item.h \
    logic/skills/skill.h \
    logic/skills/recover.h \
    logic/skills/aftermath.h \
    gui/stage.h \
    io/entityloader.h \
    logic/fight.h

