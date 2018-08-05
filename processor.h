#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "startmenu.h"
#include "mainwindow.h"

class Processor
{
public:

    Processor();

    static bool inGame;
    static bool Menu;
    static bool Game;
    static int level;
    static int green;
    static int red;
    static bool newLevel;
    static int time;
    static bool b_orientation;
};

#endif // PROCESSOR_H
