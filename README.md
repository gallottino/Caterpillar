# Caterpillar - A Snake clone

Caterpillar is a game written in C++ to test the SFML library.
All resources are drawing by myself in pixel Art. The Caterpillar asset is the smallest possible.
Every rotation of asset is calculated in a single access to a matrix in which are stored the n times of 90 degrees rotation:
the magic Matrix has on i index the direction of previous snakeBlock and on j index the direction of nest snakeBlock

##### Magic Matrix: </br>
{</br>
<blockqoute>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{1,1,0,2},</br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{3,2,2,0},</br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{0,0,3,3},</br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{0,0,1,0}</br>
</blockqoute>
};</br>

### Preview
Follow a simple screen with the final Result:

![Caterpillar](https://user-images.githubusercontent.com/33552039/56850902-0b7eeb00-6909-11e9-8a10-f2891498bf68.png)

### Assets
![snake-asset](https://user-images.githubusercontent.com/33552039/57641881-632e7f00-75b6-11e9-9f3e-c2b23a03cacb.png)


## Usefull Links

SFML LIBRARIES: https://www.sfml-dev.org/
