# PegasusServer

## Introduction
PegasusServer is a project that uses sockets with an arduino based board to receive commands from a client on a local network and controls the drone.

## Requirements

## Using

- ### Moving the drone:
  #### 1. Definitios:
  The directions are named according to the compass. Looking from behind (like the pilot).

  Where:
   - N -> Front
   - S -> Back
   - E -> Left
   - W -> Right

  The amount of variation in a direction is a float number with a range from 0.0 to 100.0. 
  
  Where: "0.0" indicates that the drone should not move to the specific direction and "100.0" indicates that it should move with full power.

  #### 2. Using:
```json
{
  "N" : 100.0,
  "S" : 0.0,
  "E" : 50.0,
  "W" : 0.0
}
```
