# Space Invaders &nbsp; <img src="./public/images/oldSprites/oldOctopus.png" height="30"> <img src="./public/images/oldSprites/oldCrab.png" height="30"> <img src="./public/images/oldSprites/oldSquid.png" height="30"> <img src="./public/images/oldSprites/oldUfo.png" height="30">

This solo project is an imitation of the classic 1978 Taito game, Space Invaders. It has been written in [C++](https://en.wikipedia.org/wiki/C%2B%2B) using the [SFML](https://www.sfml-dev.org/) graphics library.

## Features Pending

- Invaders speed up when they move down one level
- Invade condition when the Invaders reach the bottom of the board
- Random spawning of UFO Invader at the top of the window
- Invaders randomly shooting lasers down
- Collision detection between Invader lasers and Laser Cannon
- Collisions between Invader lasers and Laser Cannon laser
- Lives for the player
- Player score information displayed
- Bunkers protecting the Laser Cannon at the bottom
- Title screen
- Game over screen with button to play again
- **_(Under consideration)_** Submit the player score into a database with their name at game over and display the leaderboard either at game over or on a live website

## Gameplay

The player controls a Laser Cannon shooter at the bottom of the window which can be moved horizontally using the left and right arrow keys. Pressing the spacebar will fire the laser directly upwards from the Cannon's current position at the time the spacebar is pressed.

### Rules

- The player may only have 1 laser on the screen at any given time, meaning once the player fires the laser, they must wait for the laser to reach the top of the window for them to be able to fire again.

<p align="center">
  <img src="./public/images/gameplay.png" width="70%">
</p>

<p align="center">
  <b>Fig.1 -</b> A screenshot of the game window with the Laser Cannon at the bottom of the board, firing the Laser with the grid of Invaders above
</p>

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
