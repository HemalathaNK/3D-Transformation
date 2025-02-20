# 3D Transformation

## Overview
Transformation implementation involves translation, rotation, and scaling in a 3D space using GLUT and OpenGL. This project demonstrates the fundamental operations of 3D transformations by defining various shapes and applying transformation techniques.

## Features
- Implementation of translation, rotation, and scaling in 3D space.
- Interaction using keyboard and mouse.
- Menu options accessible via mouse clicks.

## Requirements

Ensure you have the following installed:

1. OpenGL

2. GLUT (OpenGL Utility Toolkit)

3. C++ Compiler (GCC)

## Interaction Controls
### Keyboard Shortcuts:
- **'s/S'** - Start
- **'n/N'** – Network
- **'a/A'** – About Project

### Mouse Interaction:
- **Right Click** - Displays a menu.
- **Left Click** - Selects an option from the menu.

## OpenGL & GLUT Functions Used
### Initialization and Window Management:
- `glutInit()` - Initializes the interaction between the windowing system and OpenGL.
- `glutInitDisplayMode()` - Sets up display modes like double buffering and depth buffering.
- `glutCreateWindow()` - Opens an OpenGL window with a title.
- `glutInitWindowSize()` - Defines the window size.
- `glutInitWindowPosition()` - Specifies the window position on the screen.

### Input Handling:
- `glutKeyboardFunc()` - Handles standard keyboard input.
- `glutSpecialFunc()` - Handles special keys on the keyboard.
- `glutMouseFunc()` - Manages mouse input events.

### Display and Rendering:
- `glutDisplayFunc()` - Handles window redrawing.
- `glutReshapeFunc()` - Handles window resizing.
- `glutIdleFunc()` - Manages background processing.
- `glutPostRedisplay()` - Triggers an automatic redraw.

### Transformation & Rendering:
- `glViewport()` - Defines the viewport.
- `glVertex3fv()` - Specifies vertices in three-dimensional space.
- `glColor3fv()` - Assigns colors to faces.
- `glFlush()` - Flushes the OpenGL pipeline.
- `glMatrixMode()` - Sets up the transformation matrix mode.
- `glLoadIdentity()` - Resets to the identity matrix.
- `glTranslatef()` - Applies translation in 3D space.
- `glRotatef()` - Rotates an object in 3D space.

## Installation & Execution
1. Install **OpenGL** and **GLUT** on your system.
2. Compile the program using a C++ compiler with OpenGL support:
   ```
   g++ cg.cpp -o transformation -lGL -lGLU -lglut
   ```
3. Run the executable:
   ```
   ./transformation
   ```
.
