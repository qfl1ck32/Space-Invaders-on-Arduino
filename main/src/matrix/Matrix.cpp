#include "./Matrix.h"

void Matrix::increaseIntensity(short amount) {
    this->intensity = constrain(this->intensity + amount, 0, 15);

    this->setIntensity(0, this->intensity);

    EEPROM.write(EEPROM_MATRIX_INTENSITY_INDEX, this->intensity);
}

void Matrix::setup() {
    this->shutdown(0, false);
    this->clearDisplay(0);
}

void Matrix::setLed(int addr, int row, int column, boolean state) {
    LedControl::setLed(addr, this->columns - column - 1, row, state);
}

void Matrix::clear() {
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            this->setLed(0, i, j, false);
        }
    }
}

void Matrix::displayImage(uint64_t image) {
    for (int row = 0; row < this->rows; ++row) {
        byte rowByte = (image >> row * this->columns) & 0xFF;

        for (int column = 0; column < this->columns; ++column) {
            this->setLed(0, row, column, bitRead(rowByte, column));
        }
    }
}
