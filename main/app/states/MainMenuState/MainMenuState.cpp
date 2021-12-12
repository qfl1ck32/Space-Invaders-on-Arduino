#pragma once

#include "./MainMenuState.h"

#include "../AboutMenuState/AboutMenuState.cpp"
#include "../LeaderboardState/LeaderboardState.cpp"
#include "../PlayingState/PlayingState.cpp"
#include "../SettingsMenuState/SettingsMenuState.cpp"

void MainMenuState::setup() {
    const char *messages[] = {"Play", "Settings", "Leaderboard", "About"};

    menu->setMessages(messages, sizeof(messages) / sizeof(char *));

    HandlerFunction handlers[] = {MainMenuState::goToPlay, MainMenuState::goToSettings, MainMenuState::goToLeaderboard, MainMenuState::goToAbout};
    menu->setHandlers(handlers, sizeof(handlers) / sizeof(HandlerFunction));

    joystick->setHandlerOnYAxisChangeUp(menuGoUp);
    joystick->setHandlerOnYAxisChangeDown(menuGoDown);

    joystick->setHandlerSwStateChange(menuSelect);
}

void MainMenuState::handle() {
    menu->run();
    joystick->handleJoystickMovements();
}

void MainMenuState::cleanup() {
    joystick->clearHandlers();
    button->clearHandler();

    lcd->clear();
}

void MainMenuState::goToPlay() {
    stateManager->changeState<PlayingState>();
}

void MainMenuState::goToSettings() {
    stateManager->changeState<SettingsMenuState>();
}

void MainMenuState::goToLeaderboard() {
    stateManager->changeState<LeaderboardState>();
}

void MainMenuState::goToAbout() {
    stateManager->changeState<AboutMenuState>();
}