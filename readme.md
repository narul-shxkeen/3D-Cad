# Input Formats

This software takes txt files as input, the files should contain description of the polyhedron in winged-edge data structure format.

# Getting Started

- run make command in the terminal to build the project
- execute the polyhedron_program.exe file
- enter the path to the input file relative to the main.cpp file
- Enter the desired operation. For example, tranlate.
    1. If tranlation is selected then enter the amount of translation wanted along each axis. For example,  "500 50 0" is a valid input to translate 500 units along x axis, 50 along y axis, and not move along z axis.
    2. If scale is selected then enter amount of scaling required along each axis in similar format as translation.
    3. If rotation is selected then enter the amount of rotation wanted in degrees and follow it up by the axis along which this rotation is to be perfomed. The encoding for the x, y, and z axes are 1 0 0, 0 1 0, and 0 0 1 respectively.

    The command "45 0 1 0" would mean that the solid is rotated 45 degrees along the y axis.
    4. Enter save after performing desired operations.
    5. Enter the path where you want to save the output file, relative to the main.cpp file.
    5. Enter exit to quit the session.

#  Rendering

To render the 3D object, run the renderer.py file and enter the path of the file which you want to get rendered.