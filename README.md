# Space Invaders &nbsp; <img src="./public/images/oldSprites/oldOctopus.png" height="30"> <img src="./public/images/oldSprites/oldCrab.png" height="30"> <img src="./public/images/oldSprites/oldSquid.png" height="30"> <img src="./public/images/oldSprites/oldUfo.png" height="30">

This solo project is an imitation of the classic 1978 Taito game, Space Invaders. It has been written in [C++](https://en.wikipedia.org/wiki/C%2B%2B) using the [SFML](https://www.sfml-dev.org/) graphics library.

## Features Pending

- Classes for each type of Invader: Crab, Octopus, Squid, and UFO
- Drawing the Invaders on the window
- Collision detection between Invaders and Laser
- Invader horizontal movement
- Invader vertical movement when reaching the edges
- Invade condition when the Invaders reach the bottom of the board
- Random spawning of UFO Invader at the top of the window
- Invaders randomly shooting lasers down
- Collision detection between Invader lasers and Laser Cannon
- Collisions between Invader lasers and Laser Cannon laser
- Lives for the player
- Player score information displayed
- Bunkers protecting the Laser Cannon at the bottom
- Title screen
- Play again option after game over
- ***(Under consideration)*** Submit the player score into a database with their name at game over and display the leaderboard either at game over or on a live website

## How To Use

Start by opening up a terminal and cloning this repository by entering

```
git clone https://github.com/jmcnally17/space-invaders.git
```

Then run the game by entering

```
bin/SpaceInvaders
```

into your terminal while in the [main](https://github.com/jmcnally17/space-invaders) directory. However, if you would like to have a go at compiling the code yourself, see the instructions below for macOS to get started.

## Getting Started

First, open up a terminal and install Homebrew by running

```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Then, enter `brew install sfml` to install SFML.

This code is compiled using the g++ compile command that comes with the Xcode command line tools, which can be installed by entering

```
xcode-select --install
```

## Compiling

As mentioned earlier, this code has to be compiled into an executable file that your computer can run. This can be done by entering the following command into your terminal while in the [main](https://github.com/jmcnally17/space-invaders) directory:

```
g++ -o bin/SpaceInvaders $(find src -name "*.cpp") -I /opt/homebrew/Cellar/sfml/2.5.1_2/include -L /opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio  -std=c++20
```

As of writing, the current SFML version from Homebrew is 2.5.1. You can check which version you have by using `brew info sfml`. This will also show you the correct path for the `-I` and `-L` options used in the compile command.

Enter `bin/SpaceInvaders` into your terminal and a window should open with the game running.

## Testing

Tests have been written using the [GoogleTest](http://google.github.io/googletest/) framework while adhering to the TDD process. To run the tests, enter

```
bin/tests
```

while in the [main](https://github.com/jmcnally17/space-invaders) directory. If you want to compile the tests yourself, you can start by installing GoogleTest with Homebrew by entering

```
brew install googletest
```

Then, using the g++ command mentioned in the previous section, compile the tests with

```
g++ -o bin/tests $(find tests -name "*.cpp") $(find src -name "*.cpp" ! -name "spaceInvaders.cpp")  -I /opt/homebrew/Cellar/googletest/1.13.0/include -I /opt/homebrew/Cellar/sfml/2.5.1_2/include -L /opt/homebrew/Cellar/googletest/1.13.0/lib -lgtest -lgtest_main -lgmock -lgmock_main -pthread -L /opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=c++20
```

Then the executable file should be in the [bin](https://github.com/jmcnally17/space-invaders/tree/main/bin) folder.
