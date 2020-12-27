## Brief

A general iterator over Cartesian Coordinate, also supporting access on coordinates for calculation.

May come in handy when you need to indexing inside a 1-D container but stores data that represents a matrix.

## Compile

```
$ make
```

## Expected Output

```
$ ./a.out
Max Offset: 36
coordinate: 0, 0, 0, 0, 	offset: 0
coordinate: 0, 0, 0, 1, 	offset: 1
coordinate: 0, 0, 0, 2, 	offset: 2
coordinate: 0, 0, 1, 0, 	offset: 3
coordinate: 0, 0, 1, 1, 	offset: 4
coordinate: 0, 0, 1, 2, 	offset: 5
coordinate: 0, 0, 2, 0, 	offset: 6
coordinate: 0, 0, 2, 1, 	offset: 7
coordinate: 0, 0, 2, 2, 	offset: 8
coordinate: 0, 1, 0, 0, 	offset: 9
coordinate: 0, 1, 0, 1, 	offset: 10
coordinate: 0, 1, 0, 2, 	offset: 11
coordinate: 0, 1, 1, 0, 	offset: 12
coordinate: 0, 1, 1, 1, 	offset: 13
coordinate: 0, 1, 1, 2, 	offset: 14
coordinate: 0, 1, 2, 0, 	offset: 15
coordinate: 0, 1, 2, 1, 	offset: 16
coordinate: 0, 1, 2, 2, 	offset: 17
coordinate: 1, 0, 0, 0, 	offset: 18
coordinate: 1, 0, 0, 1, 	offset: 19
coordinate: 1, 0, 0, 2, 	offset: 20
coordinate: 1, 0, 1, 0, 	offset: 21
coordinate: 1, 0, 1, 1, 	offset: 22
coordinate: 1, 0, 1, 2, 	offset: 23
coordinate: 1, 0, 2, 0, 	offset: 24
coordinate: 1, 0, 2, 1, 	offset: 25
coordinate: 1, 0, 2, 2, 	offset: 26
coordinate: 1, 1, 0, 0, 	offset: 27
coordinate: 1, 1, 0, 1, 	offset: 28
coordinate: 1, 1, 0, 2, 	offset: 29
coordinate: 1, 1, 1, 0, 	offset: 30
==========================================
coordinate: 1, 1, 1, 1, 	offset: 31
coordinate: 1, 1, 1, 2, 	offset: 32
coordinate: 1, 1, 2, 0, 	offset: 33
coordinate: 1, 1, 2, 1, 	offset: 34
coordinate: 1, 1, 2, 2, 	offset: 35
==========================================
{1, 1, 2, 3} -> offset: 19
Successfully executed
```