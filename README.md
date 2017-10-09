# SuperTTD <img align="right" width="250" height="250" src="SuperTTD.png" alt="SuperTTD">
[![GPL License](https://img.shields.io/badge/license-GPL-blue.svg)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.txt)  
*An expandable version of OpenTTD!*

## Getting Started
1. Install the appropiate libraries.
#### Linux
```shell
sudo apt install libsfml-dev libyaml-cpp-dev boost # Debian/Ubuntu
sudo pacman -S sfml yaml-cpp boost                 # Arch Linux
sudo dnf install SFML yaml-cpp boost               # Fedora (might not work)
```
#### macOS
```shell
brew install sfml yaml-cpp boost                   # Might work
```
#### Windows
```cmd
REM See https://www.sfml-dev.org/tutorials/2.4/start-vc.php
REM or https://www.sfml-dev.org/tutorials/2.4/start-cb.php

REM Then, build https://github.com/jbeder/yaml-cpp.
```
2. Run `make`. It should compile an executable. The `testdeps`
should only run the first time.
3. Run the executable.

## Licenses

The code of SuperTTD is under the GPL 2.0 License. The graphics
are under the Creative Commons Attribution-NoCommercial-ShareAlike
4.0 International License. **See the license file for more info.**
