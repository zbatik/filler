# Filler
## A 42 algorithms I project
### Overview
Filler is a two player command line game where the objective is to fill up the most space on the board with each player having a turn to place a randomly generated piece. This project concerns itself with designing a filler champion to play on a supplied vm against a host of other champions.

Each turn the a player is given a random piece that must be places onto the board such the one of the blocks in the piece overlaps with one and only one block of that players existing blocks on the board. A player cannot place a piece over an opponent's captured spots on the board. A bad placement cause you player to forfeit their remaining turns allowing the opponent to maximise the remaining space on the board.

Bellow is an example of a board and possible pieces:

![A filler board](http://oi65.tinypic.com/219awig.jpg)
![A selection of filler pieces](http://oi67.tinypic.com/dqn1ad.jpg)

### Usage
First compile the player using `make -C filler` in the root directory. Then run the following command to start a game against Carli on map 01.

```
cd resources && ./filler_vm -p1 ../filler/zbatik.filler -p2 ./players/carli.filler -f map/map01
```

