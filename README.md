# SuperTTD
[![LGPL License](https://img.shields.io/badge/license-LGPL-blue.svg)](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.txt)  
<img align="right" width="300" height="291" src="SuperTTD.png" alt="SuperTTD">
*An expandable version of OpenTTD!*

## Getting Started
1. Install the appropiate libraries.
#### Linux
```shell
sudo apt install libsfml-dev libyaml-cpp-dev # Debian/Ubuntu
sudo pacman -S sfml yaml-cpp                 # Arch Linux
sudo dnf install SFML yaml-cpp               # Fedora (might not work)
```
#### macOS
```shell
brew install sfml yaml-cpp                   # Might work
```
#### Windows
```cmd
REM See https://www.sfml-dev.org/tutorials/2.4/start-vc.php
REM or https://www.sfml-dev.org/tutorials/2.4/start-cb.php

REM Then, build https://github.com/jbeder/yaml-cpp.
```
2. Run `make`. It should compile an executable.
3. Run the executable.

## Licenses

The code of SuperTTD is under the LGPL 2.1 License. The graphics
are under the Creative Commons Attribution-NoCommercial-ShareAlike
4.0 International License. **See the license file for more info.*
