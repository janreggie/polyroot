# polyroot

Implementation of `polyroot` by Dela Cruz, Park, and Vallente

## Syntax

```
$ ./polyroot file.txt
```

The file `file.txt` contains our polynomial. The syntax for our `file.txt` is
as follows:

```
N a0 a1 a2 ... aN COMMENTS
```

- `N` is our degree: an integer.
- `a0` to `aN` are our coefficients, where `a0` is our constant and
`aN` is our leading coefficient. All of which are floating-points i.e. may
contain decimal points.
- `COMMENTS` is any text after the leading coefficient.

## Root-finding algorithm

The root-finding algorithm shall be the Durand-Kerner algorithm, whose
initial roots are determined using [Guggenheimer's *Initial Approximations
in Durand-Kerner's Root-Finding Method*](https://doi.org/10.1007/BF01935059).
