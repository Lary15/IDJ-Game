# File structure

```
/game       >> project folder 
  /assets   >> resources folder
    /audio
    /font
    /img
    /map
  /bin     >> folder with executable
  /inc     >> include folder
    *.h         contains all .h files
  /obj     >> objects folder
    *.o         contains all .o files
  /src     >> source folder
    *.cpp       contains all .cpp files
```

# Building
The Makefile file should be able to create object files of all scripts on the src folder and link them all together when building the main executable. This includes the SDL2 library linking also.

> **WARNING!** When including different SDL lib components, there may be the necessity of adding elements to these variables:  
`INCLUDE_DIRS = /usr/include/SDL2`  
`LIBRARIES = SDL2 SDL2_image SDL2_mixer SDL2_ttf`

To build the code, run:
```
make
```
To clean object files and executable, run:
```
make clean
```

# Running

To execute the code run this line from the project folder:
```
./bin/main
```