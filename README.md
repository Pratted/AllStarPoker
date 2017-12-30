# All Star Poker

## About

All Star Poker is a client/server application designed to host poker games. The project itself has unique 3 applications - game, server and client.


## Game

Each game application consists of a dealer hosting a Texas Hold'em style game thats runs on its on unique port and acts as a TCP server for all of the players in the game (playing or spectating). Players can connect directly to a game if they know the host, port and password (if requested).

## Server

Server works alongside game and they have a master-slave relationship. Each server can spawn however many games are specified in the settings file. When players wish to play allstarpoker they'll typically connect to the master server which then shows all the games available to join. From there the server will send a signal to that games dealer notifying them of the incoming connection. 

## Client

The client application lets players make decisions through a modern GUI. It displays timers, chip counts and has a chat box for all players to talk to one another. The client is designed to interact with both the server and game.


## Installation and Building

QT 5 is required to build the project. The offical source can be found [here](https://www.qt.io/download/). If you prefer to use QT Creator, you can simply open the .pro file using QT Creator and build from there. If on windows, I highly recommend using mingw as your compiler because it makes deployment easier. Instructions for deploying a QT application on windwows can be found [here](https://wiki.qt.io/Deploy_an_Application_on_Windows). On the other hand, if you'd like to build from the command line make sure qmake has been installed and use it to create your makefile. 

`$ cd your/project/dir
 $ qmake ASPServer.pro`

qmake will create the makefile, so the next step is to build the project using make. 

` $ make`

This will create the executable which can be called as such:

` $ ./ASPServer`


## Features
* Host up to 10 games on each instance of the server.
* Game sizes range from 2 to 8 players.
* In game chat so clients can chat with one another.
* Customizable player timers to keep the game running smoothly.
* Pick and choose your seat - Sit next to your friends.

## Gameplay

#### Choose your seat.

![alt text](https://github.com/Pratted/poker/blob/master/client/images/joingame.png "Choose a seat")

#### Make a bet.

![alt text](https://github.com/Pratted/poker/blob/master/client/images/betscreen.png "Make a bet")


