<p align="left">
 <!-- Black on light theme, white on dark theme -->
 <img src="/.github/icons/black.svg#gh-light-mode-only" height=40px/>
 <img src="/.github/icons/white.svg#gh-dark-mode-only" height=40px/>
</p>

**Quickly initialise projects for specified languages via templates hosted here, on GitHub.**

## Summary

**Devinit** was created to automate the annoying process of creating C/C++ projects with CMake integration. Creating a project with devinit simplifies the process from:
 1. Creating a folder
 2. Making the main file
 3. Adding CMakeLists.txt
 4. Populating these files with some boilerplate code (hello world)
 5. Adding an MIT license file

to:
 1. Running the `devinit` command with a desired project name and language.

## Building and installing devinit

Devinit is built using CMake.

There aren't any special build flags to set; to build it, just run `cmake . -B build/` and then `cmake --build build/`.

To use the `devinit` command, you can just execute it from a terminal - no sudo rights are necessary. To make it more effective, you should move the executable to a folder that is in your PATH so you can reference it easier.

The following packages will be needed to use devinit (I think they come pre-packaged in most distros anyway):
 - [unzip](https://man.archlinux.org/man/unzip.1)
 - [wget](https://archlinux.org/packages/extra/x86_64/wget/)

## Usage

To see help dialogue for the command, simply run `devinit` (or use the `-h` | `--help` flag).

| After creating a project, remember to change `<your_name>` to your name in LICENSE.MD, and change the project name in CMakeLists.txt! |
| - |
