## Overview
Marker-based tracking and stereoscopic rendering project written in C++ with OpenGL, OpenCV and ArUco. The first part uses ArUco markers detected through a webcam to control a virtual camera and a virtual object in real time. The second part renders the scene in stereo using two different methods, toe-in and off-axis, with red/blue anaglyph filters.

## Part 1: Marker Tracking

**Marker detection**

* ArUco markers are detected and drawn on the camera feed
* The first detected marker drives the virtual camera, and the second one drives an additional object

**Camera translation**

* The camera position is taken from the marker position and applied through the view matrix
* The position is averaged over the last detections, so tracking stays smooth when the marker is lost or detected intermittently

**Camera rotation**

* The axis-angle rotation given by ArUco is converted to a rotation matrix
* Averaged over the last rotations for smoothness
* The up and look vectors are rebuilt every frame so the rotation does not accumulate
* The result is mirrored on the x axis so the virtual camera turns in the expected direction

<p align = "center">
  <img width="800" height="450" alt="tracking" src="https://github.com/user-attachments/assets/d5f03e73-415c-4473-bd2c-3e6f8af33283" />
</p>

**Additional objects in the scene**

* Capacity of the VAO/VBO arrays extended to support more objects
* The model matrix of the new cube is built every frame from the second marker's pose, reflecting the X and Z axes so the rotation matches what the camera sees

## Part 2: Stereoscopy

**Toe-in**

* Both cameras are offset by `eyeSeparation` and look at a fixed point, the origin
* The view matrix is recomputed for each eye before rendering

<p align = "center">
  <img width="800" height="450" alt="toe-in" src="https://github.com/user-attachments/assets/3802c72e-bb1d-4744-868e-5f56c0ea6f55" />
</p>

**Off-axis**

* Both cameras keep parallel forward vectors, so they do not converge
* An asymmetric frustum is computed for each eye

<p align = "center">
  <img width="800" height="450" alt="off-axis" src="https://github.com/user-attachments/assets/cbb93727-1cde-4954-941b-60aaa11b98ed" />
</p>

## Features

* Real-time marker tracking with smoothing
* Camera controlled by a marker, plus a second marker controlling a cube
* Stereoscopic rendering with red/blue anaglyph output
* Switchable toe-in and off-axis methods
