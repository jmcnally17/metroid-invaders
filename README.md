# Space Invaders &nbsp; <img src="./public/images/octopus.png" height="30"> <img src="./public/images/crab.png" height="30"> <img src="./public/images/squid.png" height="30"> <img src="./public/images/ufo.png" height="30">

This solo project is an imitation of the classic 1978 Taito game, Space Invaders. It has been written in [C++](https://en.wikipedia.org/wiki/C%2B%2B) using the [SFML](https://www.sfml-dev.org/) graphics library.

This game can be played by simply entering

```
bin/SpaceInvaders
```

into your terminal while in the [main](https://github.com/jmcnally17/space-invaders) directory. However, if you would like to have a go at compiling the code yourself, a few frameworks must be installed first. See the instructions below for macOS to get started.

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

Then, all that's left is to clone this repository and you will be ready to run the compiler:

```
git clone https://github.com/jmcnally17/space-invaders.git
```

## How To Use

As mentioned earlier, this code has to be compiled into an executable file that your computer can run. This can be done by entering the following command into your terminal while in the [main](https://github.com/jmcnally17/space-invaders) directory:

```
g++ -o bin/SpaceInvaders $(find src -name "*.cpp") -I /opt/homebrew/Cellar/sfml/2.5.1_2/include -L /opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio  -std=c++20
```

As of writing, the current SFML version from Homebrew is 2.5.1. You can check which version you have by using `brew info sfml`. This will also show you the correct path for the `-I` and `-L` options used in the compile command.

Enter `bin/SpaceInvaders` into your terminal and a window should open with the game running.
