# 3dSage-doom-wii
A Nintendo Wii port of 3DSage's doom engine
## Building
Building requires you to have devkitPro for the Wii installed.

To build the port navigate to the root of this project and run `make`. This will create in´ `boot.dol` and `boot.elf`.
## Running it on a Wii
Running requires you to have a modded wii with the Homebrew Channel installed.

Create a folder called `/apps/3dSage-doom/` on your Wii's SD-Card. Copy `boot.dol` and your own `level.h` to this directory. In the HB Channel you should now be able to load `3dSage-doom`.

## Controls
Hold the Wiimote sideways and use the DPAD to move, 1 and 2 to move only on the horizontal axis, and hold B + DPAD to look around and change the height.

## License
All files within this repo are released under the GNU GPL V3 License as per the LICENSE file stored in the root of this repo.
