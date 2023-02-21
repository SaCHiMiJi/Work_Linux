from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import sys
import numpy as np

global x,y

x = 0.34
y = 0.34

width = height = 500
axrng = 1.5

def init():
    glClearColor(0.0,0.0,0.0,1.0)
    glColor3ub(255,100,0)
    
    gluOrtho2D(-axrng,axrng,-axrng,axrng)

def tranform():
    global x,y
    glClear(GL_COLOR_BUFFER_BIT)
    
    reflect_x = [1, 0,0,0,0,-1,0,0,0,0,1,0,0,0,0,1]
    reflect_y = [-1, 0,0,0,0,1,0,0,0,0,1,0,0,0,0,1]
    reflect_xy = [-1, 0,0,0,0,-1,0,0,0,0,1,0,0,0,0,1]
    reflectf1 = np.array(reflect_xy ,dtype = float)
    reflectf2 = np.array(reflect_xy ,dtype = float)
    
    glPushMatrix()
    
    glRotatef(-45.,0.,0.,1.)
    
    glutWireTeapot(0.5)
    
    glPopMatrix()
    
    glColor3ub(0, 100, 100)
    glPushMatrix()
    
    glTranslatef(-.5,-.5,0.)
    glRotatef(-45.,0.,0.,1.)
    glRotatef(180.,0.,1.,0.)
    glMultMatrixf(reflectf2)
    
    glutWireTeapot(0.5)
    glPopMatrix()
    
    glutSwapBuffers()
    
def main():
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE)
    glutInitWindowPosition(100,100)
    glutInitWindowSize(width,height)
    glutCreateWindow('Tranformation: Reflection')
    glutDisplayFunc(tranform)
    
    init()
    glutMainLoop()
    
main()    