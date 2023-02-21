from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import sys

def draw():
    # while True:
    glClear(GL_COLOR_BUFFER_BIT)
    glutWireTeapot(0.5)
    glFlush()
    
glutInit(sys.argv)
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
# glutInitWindowSize(250, 250)
# glutInitWindowPosition(100, 100)
glutCreateWindow('Wire Teapot by PyOpenGL')
glutDisplayFunc(draw)
glutMainLoop()