# Brightness Controller

A dead simple GTK app that controls brightness via a "slider" widget for my Dell laptop that has Intel graphics.

## Build Instructions

This project requires a few dependencies be install in order to compile it:

```
 Meson - Build System
 gtkmm - GTK GUI toolkit library.
```

1. Git clone project
2. `$ cd` into the `src` directory
3. `$ meson setup builddir`
4. `$ cd` into `builddir`
5. `$ meson compile`
6. Launch the app: `$ ./brightness_controller`

_You will need to run the binary as `root` because it needs to write to the `/sys/backlight/` file._