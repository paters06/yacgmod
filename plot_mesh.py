import matplotlib.pyplot as plt
import matplotlib.collections
import numpy as np


"""
Taken from https://stackoverflow.com/a/52206017
Defining the white values https://matplotlib.org/stable/gallery/color/colormap_reference.html
"""


def plot_mesh(nodes, elems):

    elems = np.asarray(elems)

    x = nodes[:, 0]
    y = nodes[:, 1]
    num_elems = elems.shape[0]
    zero_fill = np.zeros(num_elems)

    fig, ax = plt.subplots()
    ax.set_aspect('equal')

    xy = np.c_[x, y]
    verts = xy[elems]
    pc =matplotlib.collections.PolyCollection(verts)
    pc.set_cmap('Greys')
    pc.set_edgecolor('blue')
    pc.set_array(zero_fill)
    ax.add_collection(pc)
    ax.autoscale()

    ax.plot(x, y, marker="o", ls="", color="blue")
    plt.show()


def test_01():
    nodes = np.array([[0, 0], [0, 1],
                    [1, 1], [1, 0]])
    elems = np.array([[0, 1, 2, 3, 0]])
    plot_mesh(nodes, elems)


def test_02():
    nodes = np.array([[0, 0], [0, 1],
                    [1, 0], [1, 1],
                    [2, 0], [2, 1]])
    elems = np.array([[0, 2, 3, 1], [2, 4, 5, 3]])
    plot_mesh(nodes, elems)


def test_03():
    nodes = np.array([[0, 0], [0, 1],
                    [1, 0], [1, 1],
                    [1.5, 0.5]])
    elems = np.array([[0, 1, 3], [0, 3, 2], [2, 3, 4]])
    plot_mesh(nodes, elems)


def test_04():
    nodes = np.array([[0,0], [0,0.5], [0,1], [0.5,0], [0.5,0.5], [0.5,1], [1,0], 
                     [1,0.5], [1,1]])
    elems = np.array([[0,3,4,1],[1,4,5,2],[3,6,7,4],[4,7,8,5]])
    plot_mesh(nodes, elems)


def main():
    
    test_id = 4

    if test_id == 1:
        test_01()
    elif test_id == 2:
        test_02()
    elif test_id == 3:
        test_03()
    elif test_id == 4:
        test_04()
    else:
        print('Check test ID')


if __name__ == '__main__':
    main()
