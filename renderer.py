import os
import matplotlib.pyplot as plt

def parse_polyhedron(file_name):
    vertices = []
    edges = []
    faces = []

    with open(file_name, 'r') as f:
        for line in f:
            # Ignore comments and strip whitespace
            line = line.split('#')[0].strip()
            if not line:
                continue  # Skip empty lines

            # Parse the relevant parts
            if line.startswith('v '):  # Vertex
                _, x, y, z = line.split()
                vertices.append([float(x), float(y), float(z)])
            elif line.startswith('e '):  # Edge
                _, v1, v2 = line.split()
                edges.append((int(v1), int(v2)))
            elif line.startswith('f '):  # Face
                face_edges = list(map(int, line.split()[1:]))
                faces.append(face_edges)
    
    return vertices, edges, faces

def plot_polyhedron(vertices, edges):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    # Plot the vertices
    xs, ys, zs = zip(*vertices)
    ax.scatter(xs, ys, zs, color='b')

    # Plot the edges
    for edge in edges:
        v1, v2 = edge
        x = [vertices[v1][0], vertices[v2][0]]
        y = [vertices[v1][1], vertices[v2][1]]
        z = [vertices[v1][2], vertices[v2][2]]
        ax.plot(x, y, z, color='r')

    # Set the scaling and labels
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    ax.auto_scale_xyz([min(xs), max(xs)], [min(ys), max(ys)], [min(zs), max(zs)])

    plt.show()

# Main function to read and plot the polyhedron
if __name__ == "__main__":
    # Prompt for the input file name
    input_file_name = input("Enter the name of the input file (without extension): ")

    # Construct the full file path (assuming inputs are stored in 'inputs' directory)
    file_path = os.path.join('inputs', input_file_name + '.txt')

    # Check if the file exists
    if not os.path.exists(file_path):
        print(f"Error: The file {file_path} does not exist.")
    else:
        vertices, edges, faces = parse_polyhedron(file_path)
        plot_polyhedron(vertices, edges)
