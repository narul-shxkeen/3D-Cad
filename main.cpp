#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "src/Polyhedron.h"
#include "src/Translate.h"
#include "src/Rotate.h"
#include "src/Scale.h"

using namespace std;

int main() {
    string inputPath, outputPath;
    cout << "Enter the path to the input file (e.g., inputs/polyhedron.txt): ";
    cin >> inputPath;

    // Load the polyhedron from the input file
    Polyhedron polyhedron;
    if (!polyhedron.loadFromFile(inputPath)) {
        cerr << "Error: Could not load the polyhedron from file." << endl;
        return 1;
    }

    // Main loop for performing operations
    string operation;
    while (true) {
        cout << "Enter operation (translate/rotate/scale/save/exit): ";
        cin >> operation;

        if (operation == "translate") {
            float tx, ty, tz;
            cout << "Enter translation values (tx ty tz): ";
            cin >> tx >> ty >> tz;
            translate(polyhedron, tx, ty, tz);
        } else if (operation == "rotate") {
            float angle, rx, ry, rz;
            cout << "Enter rotation angle and axis (angle rx ry rz): ";
            cin >> angle >> rx >> ry >> rz;
            rotate(polyhedron, angle, rx, ry, rz);
        } else if (operation == "scale") {
            float sx, sy, sz;
            cout << "Enter scale factors (sx sy sz): ";
            cin >> sx >> sy >> sz;
            scale(polyhedron, sx, sy, sz);
        } else if (operation == "save") {
            cout << "Enter the output file path (e.g., outputs/output.txt): ";
            cin >> outputPath;
            if (!polyhedron.saveToFile(outputPath)) {
                cerr << "Error: Could not save the polyhedron to file." << endl;
                return 1;
            }
            cout << "Polyhedron saved to " << outputPath << endl;
        } else if (operation == "exit") {
            break;
        } else {
            cout << "Unknown operation. Please enter one of: translate, rotate, scale, save, exit." << endl;
        }
    }

    return 0;
}
