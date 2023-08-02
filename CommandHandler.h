/*

[+]======INFO======[+]
CommandHandler.h
Created May 30, 2023
Copyright Bebula Games
[+]================[+]

[+]=====PURPOSE=====[+]

Handles commands for CLI games.
e.g "> help" prints a help page.

[+]=================+]

[+]===IMPLEMENTATION=====[+]

In Main.cpp

    CommandExecutor commandExecutor;
    while (true) {
        std::string userInput;
        std::getline(std::cin, userInput);
        if (!userInput.empty()) {
            commandExecutor.executeCommand(userInput);
            if (userInput == "debug") {
                std::cout << "debug stuff" << std::endl;
            }
        } else {
            std::cout << "Invalid Command" << std::endl;
        }
    }

[+]======================[+]

*/

#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <ncurses.h>

class CommandExecutor {
public:
    void executeCommand(const std::string& command) {
        std::string gameCommand = command;
        std::transform(gameCommand.begin(), gameCommand.end(), gameCommand.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        if (gameCommand == "help") {
            std::cout << "[+] help" << std::endl;
            std::cout << "[+] " << std::endl;
            std::cout << "[+] " << std::endl;
            std::cout << "[+] " << std::endl;
            std::cout << "[+] " << std::endl;
            std::cout << "[+] " << std::endl;
            std::cout << "[+] " << std::endl;
            std::cout << "[+] quit" << std::endl;
        } else if (gameCommand == "quit") {
            exit(0);
        } else {
            std::cout <<"Unrecognized command! Try again." << std::endl;
            refresh();
        }
    }
};

#endif