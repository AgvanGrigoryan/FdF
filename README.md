# Fdf

Fdf is a program that creates simplified 3D graphic representation of a relief landscape using [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html) library. Subject can be found [here](https://cdn.intra.42.fr/pdf/pdf/47326/en.subject.pdf).

FDF is short for ’fil de fer’ in French which means ’wireframe model’.

## Project goals

* Create a basic computer graphics project
* Learn about mapping
* Drawing lines in 3D using maths
* Implement axis rotation, zoom and transmittion

![Map Rotation](preview/fdf-rotate.gif)


https://github.com/AgvanGrigoryan/FdF/assets/101641443/8d39155b-e198-41e6-9631-6e2e5947c798


## To compile and run
Run the following commands in Terminal:
```shell
# to build
> make

# to run
> ./fdf test_maps/julia.fdf
```

The program accepts a map in `.fdf` file as argument. Those files can be found at `test_maps/` folder. Those include lines of numbers separated by spaces (sometimes with HEX colour codes) representing height of the points on map.

To close window press `esc`.

## Scene control

Use `[+]` & `[-]` to zoom in and out

Use `[a]` & `[d]` to rotate on x-axis

Use `[s]` & `[w]` to rotate on y-axis

Use `[scroll up]` & `[scroll down]` to rotate on z-axis

Press `[↑]` to move upwards

Press `[↓]` to move downwards

Press `[←]` to move left

Press `[→]` to move right

## Additionally, you can control the scene using the buttons on the screen 

<img width="150" alt="Screen Shot 2024-03-24 at 4 52 39 PM" src="https://github.com/AgvanGrigoryan/FdF/assets/101641443/30a86f3b-b7c7-4c41-81db-647471eaceb2">

## Render examples
<img width="1998" alt="Screen Shot 2024-03-23 at 11 07 14 AM" src="https://github.com/AgvanGrigoryan/FdF/assets/101641443/5ec68623-1972-4377-a9ed-b401c7b9e66a">
<img width="1999" alt="Screen Shot 2024-03-23 at 11 17 07 AM" src="https://github.com/AgvanGrigoryan/FdF/assets/101641443/38fad0c4-a1ef-4e52-8556-e3619a03b00f">
<img width="2000" alt="Screen Shot 2024-03-24 at 5 09 25 PM" src="https://github.com/AgvanGrigoryan/FdF/assets/101641443/fdab6fa4-9cc0-4001-ba2b-f0ee12bb4b82">
<img width="2000" alt="Screen Shot 2024-03-24 at 5 05 00 PM" src="https://github.com/AgvanGrigoryan/FdF/assets/101641443/8e0f39ee-9f5c-4299-a319-2cdf922b111c">
<img width="2000" alt="Screen Shot 2024-03-24 at 5 03 45 PM" src="https://github.com/AgvanGrigoryan/FdF/assets/101641443/c3d3c1d1-75ef-48dd-a6f8-255287295101">


