
Debian
====================
This directory contains files used to package butd/but-qt
for Debian-based Linux systems. If you compile butd/but-qt yourself, there are some useful files here.

## but: URI support ##


but-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install but-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your but-qt binary to `/usr/bin`
and the `../../share/pixmaps/but128.png` to `/usr/share/pixmaps`

but-qt.protocol (KDE)

