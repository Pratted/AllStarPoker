# Tests

## Hand Strength Tester

This is a driver developed to test the strength of poker hands and compare them against one another. It includes a GUI to make visualizing the hands easier. Tests can be conducted through the command line or through the GUI. 

### Usage
    
```shell    
$ hand-str-test --no-gui tests.txt      Output test case to console
$ hand-str-test tests.txt               Display test cases in GUI.
$ hand-str-test                         Use random test cases.
```

#### Visualize hands through the GUI.

![alt text](https://github.com/Pratted/allstarpoker/tests/three_kind.png "A player wins with 3 of a kind")

![alt text](https://github.com/Pratted/allstarpoker/tests/straight.png "Two players have the best hand; straight")

#### Test through the command line.

```shell
$ hand-str-test --no-gui cases.txt

---------------------------- New Hand ---------------------------
Player(s) 5 won
Flush 13 12 7 6 3 
```

