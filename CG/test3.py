from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import sys

def init():
    glClearColor(1.0,1.0,1.0,1.0)
    gluOrtho2D(-5.0,5.0,-5.0,5.0)

def plotfunc():
    glClear(GL_COLOR_BUFFER_BIT)
    glColor3f(0.5,0.5,0.5)
    glLineWidth(3.0)

    glBegin(GL_LINES)
    glVertex2f(-5.0,0.0)
    glVertex2f(5.0,0.0)
    glVertex2f(0.0,5.0)
    glVertex2f(0.0,-5.0)
    glEnd()

    glColor3f(0.0,0.0,0.5)
    glPointSize(5.0)
    x = -5.0
    while(x <= 5.0):
        y = x**2

        glBegin(GL_POINTS)
        glVertex2f(x, y)
        glEnd()
        x += 0.1


    glFlush()

#def keyboard(key, x, y):
#   #Allows us to quit by pressing 'Esc' or 'q'.
#   if key == chr(27) or key == 'q':
#       sys.exit()

def main():
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
    glutInitWindowPosition(50, 30)
    glutInitWindowSize(400,400)
    glutCreateWindow('Function Plotter')
    glutDisplayFunc(plotfunc)
    # glutKeyboardFunc(keyboard)

    init()
    glutMainLoop()

main()