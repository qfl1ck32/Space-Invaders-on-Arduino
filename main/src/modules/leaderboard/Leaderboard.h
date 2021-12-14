#ifndef Leaderboard_h
#define Leaderboard_h

#include "../../constants/app.h"
#include "../../eeprom-handler/EEPROMHandler.h"
#include "../../utils/utils.h"
#include "./NameAndScore.h"
#include "LinkedList.h"

class Leaderboard {
   public:
    EEPROMHandler *eeprom;

    static const char *const nameAndScoreDelimiter;

    static int size;

    Leaderboard() {
        this->eeprom = new EEPROMHandler(EEPROM_LEADERBOARD_START_INDEX, 256);

        // this->eeprom->clear();
    }

    LinkedList<NameAndScore> *get();

    void write(const char *, int);

    int getHighscore();
};

#endif
