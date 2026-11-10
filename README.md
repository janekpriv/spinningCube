## Build
 
```bash
gcc cube.c -o cube -lm
```
 
## Run
 
```bash
./cube        # cube (default)
./cube -s     # cube
./cube -p     # pyramid
```

## How it works
 
1. Generate points on the surface of the shape.
2. Rotate each point around the X, Y and Z axes.
3. Project it onto the 2D screen with perspective.
4. Use a z-buffer to keep only the closest point per character cell.
5. Print the buffer and repeat.
