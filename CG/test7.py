from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import sys
import numpy as np

global x, y

x = 0.34
y = 0.34

width = height = 500
axrng = 1.5


def init():
    glClearColor(0.0, 0.0, 0.0, 1.0)
    glColor3ub(255, 100, 0)

    gluOrtho2D(-axrng, axrng, -axrng, axrng)


def tranform():
    global x, y
    glClear(GL_COLOR_BUFFER_BIT)

    sh_x = .4
    sh_y = .5
    sher_x = [1, 0, 0, 0, sh_x, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]
    sher_y = [1, sh_y, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]
    sher_xy = [1, -sh_y, 0, 0, -sh_x, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]
    sherf1 = np.array(sher_x, dtype=float)
    sherf2 = np.array(sher_y, dtype=float)
    sherf3 = np.array(sher_xy, dtype=float)

    
    glPushMatrix()
    
    glMultMatrixf(sherf1)
    glutWireTeapot(0.5)

    glPopMatrix()

    glColor3ub(0, 100, 100)
    glPushMatrix()

    glTranslatef(0., .8, 0.)
    glMultMatrixf(sherf2)

    glutWireTeapot(0.5)
    glPopMatrix()

    glColor3ub(100, 0, 100)
    glPushMatrix()

    glTranslatef(0., -.8, 0.)
    glMultMatrixf(sherf3)

    glutWireTeapot(0.5)
    glPopMatrix()
    glutSwapBuffers()


def main():
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE)
    glutInitWindowPosition(100, 100)
    glutInitWindowSize(width, height)
    glutCreateWindow('Tranformation: Reflection')
    glutDisplayFunc(tranform)

    init()
    glutMainLoop()


main()
