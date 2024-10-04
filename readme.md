# sens

## about

sens is just a simple sensitivity converter written in c++

## features

- fast (yeah c++ wooo)
- easy to use (once you understand the format)
- easily convert between (supported) games
- easily convert to and from cm/360 values and in-game senses
- aliases for (supported) games (i.e. `val`, `valorant` and `valo` are all valid!)

## usage

sens is a command line tool. the easiest way to use it is to add its exe's directory to your system's path

from there you can just run it using your favourite terminal using the `sens` command. this will print the most up-to-date usage for the program (i'm lazy and will probably (definitely) forget to update the readme)

``` sh
$ sens

usage:
        sens <dpi> <sensitivity> <input game> <output game>

valid input/output games:
        cm               cm/360
        val              valorant
        cs               counterstrike
        ...
```

e.g.

convert 47cm/360 at 800 dpi to it's respective valorant in-game sens:
``` sh
$ sens 800 47 cm val

0.347615
```

convert .348 in-game val to cs (note that the dpi here is ignored here, but still required -- my bad)
``` sh
$ sens 0 .348 val cs

1.106640
```

convert .553 in-game cs at 1600 dpi to cm/360
```sh
$ sens 1600 .553 cs cm

46.975172
```

hope that helps :D

## compilation

navigate to the sens directory (wherever you cloned it) and then just type 'make' in your terminal. if you don't have make installed (it's available on windows and linux you should get it), you can just compile it using the arguments found inside the makefile

## planned features

- want to look at fov edge to edge sens conversion
    - right now we just look at 360 sens conversion (i.e. cm/360)
    - can also implement different aspect ratio scaling
- change games to just work off of json files
    - would be a lot easier to add additional games
- add rounding for senses depending on game
    - most games don't have the ability to have an arbitrary amount of decimal places - like valorant only allows for 3 and deadlock only allows for 2
- ui (eventually)
