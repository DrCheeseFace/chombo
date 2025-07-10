# Chombo 
`Chombo 「錯和/チョンボ」is a penalty for severe game rule violations, generally severe enough to restart the current hand. 
Mistakes that are minor and/or correctable, such as drawing the wrong tile, can be given a dead hand penalty instead.`

Gui riichi mahjong calculator. In progress

#### Requirements for deving
- sdl3
- sdl3ttf
- cbindgen (for generating header files for mahc)
```
make debug && ./main.out
```

#### TODO
- [x] shift -+ window resizing
- [x] figure out why memory leak :(
- [x] help menu 
- [ ] fix for resize bug. (not updating immediatly) 
- [x] input and deleting tile preview on top
- [x] settings round conditions menu
- [ ] using mahc for calculate
- [ ] displaying output
- [ ] figure out how to use cmake to add sdl3 and sdl3ttf as vendored 
- [ ] figure out creating platform specific executable

![](https://c.tenor.com/wjvQf6cClREAAAAd/tenor.gif)
