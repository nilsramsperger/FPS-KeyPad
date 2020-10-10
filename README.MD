This is the firmware for a Teensy 3.2 to drive a custom left hand keypad for playing FPS games.

Every key on the board has two bindings, that can be switched by holding the Mod button.
The keys are mapped to the HID interface "slots" according to the finger they are pressed with.
So every finger can press one button a time.
Only the buttons for the pinky finger make an exception when not modified.
Shift and Ctrl can be pressed simultaneously.

# Keypad button layout
```
 [1][2][3][4]
  [5][6][7][8]
[9]     [10]   [12][13]
 [11]
```

# Keys layout
```
 [Q][W][E][R]
  [A][S][D][F]
[Shift]     [C]   [Space][Mod]
 [Ctrl]
 ```

# Keys modified layout
```
 [1][2][3][G]
  [4][5][6][Esc]
[B]     []   [][Mod]
 [A]
 ```