# 🪐 Solar System Simulation using Raytracing

This project simulates a 3D model of the solar system using ray tracing techniques, allowing for realistic rendering of planets, moons, and other celestial bodies. The simulation includes representations of orbits and lighting effects.

[🎥 Orbit of the Moon](https://youtu.be/aCWGztJvIAc?si=wWXhDJo0T5ZaGUyc)

[🎥 Solar System Simulation](https://youtu.be/lytyF9gdKbI?si=RHzfQMiQUu2pxVZC)

![IMG_0023](https://github.com/user-attachments/assets/5c9d0660-3761-44b2-aa8f-c31f2e2e8232)

Alternatively, you can create your own map using any supported objects!

![christmas](https://github.com/user-attachments/assets/0932659f-2247-450a-aac0-93feaaba8a04)

## 🚀 Features

- **Easy Scene Creation**: Simply specify object names and details on the map to render the desired scene.
- **Support for Various Objects**: In addition to celestial bodies, renders desired objects when specified on the map.
- **Time Interval and Flow Adjustment**: Allows observation of celestial movements by adjusting the flow of time.
- **Viewpoint Switching**: Instantly switch to viewpoints that allow you to observe each celestial body or a top-down view.
- **Free Movement**: Move freely in any direction within the space environment.
- **Phong lighting**: Realistic lighting effects including shadows cast by objects.
- **Raytracing Techniques**: Uses ray tracing for high-quality rendering of reflections, refractions, and shadows.
- **Anti-Aliasing Support**: Provides smoother and more natural rendering of images.

## 📜 Prerequisites

⚠️ MacOS Only

To compile and run this program, you'll need:

- [minilibX](https://github.com/42Paris/minilibx-linux)
- A C/C++ compiler (e.g., GCC)
- Make (optional, for easier compilation)


## 💻 Installation

Follow these steps to set up and run the IRC server on your local machine:

1. **Clone the repository**:
    ```bash
    git clone https://github.com/Hyun-Soon/RayTraceSolar.git
    cd RayTraceSolar
    ```

2. **Build the project**:
    ```bash
    make
    ```

3. **Run the program**:
    ```bash
    ./miniRT <arg1>

    arg1 : map file path(e.g., ./maps/solar_system.rt)
    ```

## ⚒️ Custom Maps

You can create your own map with the supported objects below. Map's extension must be `.rt` and each arguments should be seperated by space.

### Object List

|Keyword|Meaning|Arguments|
|-------|-------|---------|
|`A`|Ambient|brightness ratio, color|
|`C`|Camera|position, direction, FOV|
|`L`|Light| position, brightness ratio, color|
|`cb`|CheckerBoard|position, normal vector, pattern direction, color|
|`pl`|Plane|position, normal vector, color|
|`dk`|Disk|position, normal vector, diameter, color|
|`sp`|Sphere|position, diameter, color, [texturemap], [bumpmap]|
|`cn`|Cone|position, normal vector, radius, height, color|
|`cy`|Cylinder|position, normal vector, diameter, height, color|
|`lb`|LightBulb|position, diameter, color, [texturemap], [bumpmap]|
|`star`|Star|name, axis, radius, color, [texturemap], [bumpmap]|
|`planet`|Planet|name, primary star(planet) name, axis, radius, orbit radius, period, color, [texturemap], [bumpmap]|

⚠️ If you don't want to use the optional argument on star and planet objects, you must specify 'none'

You can use these names for star and planets.

Star : `SUN`

Planet : `MERC`,`VENUS`, `EARTH`, `MARS`, `JUPITER`, `SATURN`, `MOON` 

⚠️ Specify star and planet's name in the map if you want to use `0`~`9` keys below.

## 🎮 Controls

|Key|Meaning|
|---|-------|
|`W, A, S, D`|Control camera movement within the environment|
|`E, Q`|Move up, down vertically|
|`Arrow Keys`|Move the viewpoint up, down, left, and right|
|`[, ]`|Time flows into the past/future in time interval|
|`F`|Adjust the time interval(day - week - month - year cycle)|
|`0`|Top view|
|`1`|Set the camera to point from _**Earth**_ towards the _**Sun**_|
|`2`|Set the camera to point from _**Sun**_ towards the _**Mercury**_|
|`3`|Set the camera to point from _**Sun**_ towards the _**Venus**_|
|`4`|Set the camera to point from _**Sun**_ towards the _**Earth**_|
|`5`|Set the camera to point from _**Sun**_ towards the _**Mars**_|
|`6`|Set the camera to point from _**Sun**_ towards the _**Jupiter**_|
|`7`|Set the camera to point from _Sun_ towards the _**Saturn**_|
|`9`|Set the camera to point from _**Earth**_ towards the _**Moon**_|
|`SPACE`|Turn on/off anti-aliasing|
|`ESC`|Destroy window|


## 🙌 Collaborator
|![임현순](https://avatars.githubusercontent.com/u/66724166)|![서동현](https://avatars.githubusercontent.com/u/108206977)|![김유승](https://avatars.githubusercontent.com/u/127705483)|![김성민](https://avatars.githubusercontent.com/u/128010957)|
|:-:|:-:|:-:|:-:|
|[임현순](https://github.com/Hyun-Soon)|[서동현](https://github.com/west-eastH)|[김유승](https://github.com/yusekim)|[김성민](https://github.com/sungmiki42)|
