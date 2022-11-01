# REGULAR ENGINE

REGULAR ENGINE is a videogame engine created by Pau Olmos for research, learning and improvement purposes. Hosted and directed by CITM durning the third year of the career 'Design and Development o Videogames' in Terrassa.

## LINKS:

Engine: https://github.com/PauOlmos/REGULAR_ENGINE
Coder: https://github.com/PauOlmos

## Short description:

REGULAR ENGINE currently enables de user to create, destroy and modify different primitives, load any fbx with drag & drop and adjust some parametres in the Configuration window such as max FPS, faceculling, etc.

## Features

* Creation of cubes, Pyramides, Cilindres and planes and the option of render them or not.
* Selection of any of the primitives quoted above.
* Destruction, movement and scaling of the selected primitive.
* Unity-like camera that can:
  * Move and aim freely the camera.
  * Move the camera around the primitive in order of its scale. 
  * Focus on the selected primitive.
  *  Zoom in and zoom out with the mouse wheel.
* Inspector which shows the current rimitives in the scene.
* Console with information of the events.
* Supports loading files form any part of the computer and with drag and drop.
* Enable/disable options for lightning, faceculling, wireframe and depthtest.
* Show FPS and miliseconds in two separate histograms and a capper.
* Window window to adjust resolutions with a button to have the resolution of 16:9 automatically.
* Fullscreen and Vsync mode can be enabled or disabled.
* There is a button to restart the configuration to the predeterminated.
* Hardware can be seen in the Hardware window
* Can show the demo of ImGui to change the aesthetic of the engine and go the the repository of the engine with one click.

## Controls

### Camera
* Mouse wheel pressed: Moves the camera angle in the same position.
* (W/A/S/D) + Right click: Movement of the camera without changing its angle.
* Mouse wheel Up/Down: Zoom in/Zoom out respectively.
* F: Focus on the selected primitive.
* LAlt + Left click: View around the sleted primitive at a distance acording to its scale value.
* U/J: Moves the camera at Y axis indistinctly of the angle of the camera.
* LShift doubles the speed of the camera.
### Primitives
* 1: Sums x position to the selected primitve.
* 2: Sums y position to the selected primitve.
* 3: Sums z position to the selected primitve.
* 1 + LShift: Substracts x position to the selected primitve.
* 2 + LShift: Substracts y position to the selected primitve.
* 3 + LShift: Substracts z position to the selected primitve.
* X + Up Arrow: Scales the x axis of the selected primitive.
* Y + Up Arrow: Scales the y axis of the selected primitive.
* Z + Up Arrow: Scales the z axis of the selected primitive.
* X + Down Arrow: Reducts the x axis of the selected primitive.
* Y + Down Arrow: Reducts the y axis of the selected primitive.
* Z + Down Arrow: Reducts the z axis of the selected primitive.
* Just Up Arrow: Scales the whole primitive.
* Just Down Arrow: Reducts the whole primitive.
* Supr: Deletes the current primitve.
### EXTRA
* ESC: Close the engine.
