from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import sys


def display():
    
    # set line color
    glColor3f(1.0, 1.0, 1.0)
    glBegin(GL_LINES)
    #  Draw a white grid floor.
    i = -2.5
    while(i <=2.5):
        glVertex3f(i, 0, 2.5)
        glVertex3f(i, 0, -2.5)
        glVertex3f(2.5, 0, i)
        glVertex3f(-2.5, 0, i)
        i+= 2.5
    glEnd()
    # Draw the tetrahedron.
    glBegin(GL_TRIANGLE_STRIP)
    
    glColor3f(1,0.77,0.55)
    glVertex3f(0, 2, 0)
    
    glColor3f(0.2, 0.77, 0.96)
    glVertex3f(-1, 0, 1)
    
    glColor3f(0.81,0.62,0.97)
    glVertex3f(1, 0, 1)
    
    glColor3f(0, 0, 1)
    glVertex3f(0, 0, -1.4)
    
    glColor3f(0.51,0.72,0.96)
    glVertex3f(0, 2, 0)
    
    glColor3f(0.65,0.42,1)
    glVertex3f(-1, 0, 1)
    glEnd()

    glFlush()


def init():
    # Set the current clear color.
    glClearColor(0.1, 0.39, 0.88, 1.0)
    glColor3f(1.0, 1.0, 1.0)
    
    # Tell the rendering engine not to draw backfaces.
    glEnable(GL_CULL_FACE)
    glCullFace(GL_BACK)

    # Set the camera lens
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glFrustum(-2, 2, -1.5, 1.5, 1, 40)
    
    # Set up transforms
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    glTranslatef(0, 0, -3)
    glRotatef(50, 1, 0, 0)
    glRotatef(70, 0, 1, 0)


def main():
    
    # Normal window setting
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
    glutInitWindowPosition(80, 80)
    glutInitWindowSize(800, 600)
    glutCreateWindow("Tetrahedron")
    
    # Draw Tetrahedron
    glutDisplayFunc(display)
    
    # Set perspective
    init()
    glutMainLoop()

main()



