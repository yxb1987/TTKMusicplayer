# =================================================
# * This file is part of the TTK Music Player project
# * Copyright (c) 2015 - 2017 Greedysky Studio
# * All rights reserved!
# * Redistribution and use of the source code or any derivative
# * works are strictly forbiden.
# =================================================
   
INCLUDEPATH += $$PWD

!contains(CONFIG, MUSIC_NO_MSVC_LINK_NEED){
HEADERS  += \
    $$PWD/musicvideoqualitypopwidget.h \
    $$PWD/musicvideobarragestylepopwidget.h \
    $$PWD/musicvideocontrolwidget.h \
    $$PWD/musicvideoview.h \
    $$PWD/musicvideotablewidget.h \
    $$PWD/musicvideoplaywidget.h \
    $$PWD/musicvideofloatwidget.h

}

contains(CONFIG, MUSIC_BUILD_LIB){
SOURCES += \
    $$PWD/musicvideoqualitypopwidget.cpp \
    $$PWD/musicvideobarragestylepopwidget.cpp \
    $$PWD/musicvideocontrolwidget.cpp \
    $$PWD/musicvideoview.cpp \
    $$PWD/musicvideotablewidget.cpp \
    $$PWD/musicvideoplaywidget.cpp \
    $$PWD/musicvideofloatwidget.cpp

}
