QT += core \
    widgets

SOURCES += \
    logic/entities/entity.cpp \
    logic/items/item.cpp \
    logic/skills/skill.cpp \
    logic/skills/recover.cpp \
    logic/skills/aftermath.cpp \
    logic/battle.cpp \
    io/entityloader.cpp \
    main.cpp \
    gui/globalspec.cpp

HEADERS += \
    logic/entities/entity.h \
    logic/items/item.h \
    logic/skills/skill.h \
    logic/skills/recover.h \
    logic/skills/aftermath.h \
    logic/battle.h \
    io/entityloader.h \
    gui/globalspec.h

DISTFILES += \
    files/goblin
