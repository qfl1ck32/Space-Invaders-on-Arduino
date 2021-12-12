#pragma once

#include "./GameOverState.h"

#include "../../../utils/utils.cpp"
#include "../MainMenuState/MainMenuState.cpp"
#include "../NameSelectionState/NameSelectionState.cpp"

class MainMenuState;

void GameOverState::setup() {
    lcd->clear();

    // TODO: add logic to first show the person another screen
    // if he has the highest score
    button->setOnStateChange(GameOverState::goToNextStep);

    // TODO: not here
    matrix->clear();
}

void GameOverState::handle() {
    // TODO: modularization
    int numberOfDigitsInScore = getNumberOfDigits(gameEngine->score);

    char gameOverMessage[20 + numberOfDigitsInScore];

    sprintf(gameOverMessage, "Game over. Score: %d.", gameEngine->score);

    lcd->printOnRow(gameOverMessage, 0);
    lcd->printOnRow(F("Press X to continue."), 1);

    if (this->delayer.canRun()) {
        lcd->scrollRow(0);
        lcd->scrollRow(1);
    }

    joystick->handleJoystickMovements();
}

void GameOverState::cleanup() {
    lcd->clear();
    button->clearHandler();
}

void GameOverState::goToNextStep() {
    // TODO: please do something, lol
    if (gameEngine->score + 5 > leaderboard->getHighscore()) {
        leaderboard->write("Rusu, lol", gameEngine->score + 5);
        stateManager->changeState<NameSelectionState>();
    }

    else {
        stateManager->changeState<MainMenuState>();
    }

    gameEngine->resetState();
}