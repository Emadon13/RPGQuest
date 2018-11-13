TARGET = "Depressia"

QT += core \
    widgets

SOURCES += \
    logic/entities/entity.cpp \
    logic/items/item.cpp \
    logic/skills/skill.cpp \
    logic/skills/recover.cpp \
    logic/skills/aftermath.cpp \
<<<<<<< HEAD:RPGQuest/RPGQuest.pro
    logic/battle.cpp \
    io/entityloader.cpp \
    main.cpp \
    gui/globalspec.cpp
=======
    gui/stage.cpp \
    io/entityloader.cpp \
    main.cpp \
    logic/fight.cpp
>>>>>>> 78e10a12edfa570eb7dc47d79f7f3cde520dce83:Depressia/Depressia.pro

HEADERS += \
    logic/entities/entity.h \
    logic/items/item.h \
    logic/skills/skill.h \
    logic/skills/recover.h \
    logic/skills/aftermath.h \
<<<<<<< HEAD:RPGQuest/RPGQuest.pro
    logic/battle.h \
    io/entityloader.h \
    gui/globalspec.h
=======
    gui/stage.h \
    io/entityloader.h \
    logic/fight.h
>>>>>>> 78e10a12edfa570eb7dc47d79f7f3cde520dce83:Depressia/Depressia.pro

