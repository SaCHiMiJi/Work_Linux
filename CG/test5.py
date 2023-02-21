from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import sys
import numpy as np

global anim, x, y, da, dy, deg, s

x = -0.67
y = 0.34
deg = 0

s = 0
scale = []
for f in np.arange(0.5, 3.0, 0.01):
    scale.append(f)
for f in np.arange(3.0, 0.6, -0.01):
    scale.append(f)
    
dx = dy = 1

width = height = 500
axrng = 1.0

anim = 0

def init():
    glClearColor(0.0,0.0,0.0,1.0)
    glColor3ub(255,100,0)
    
    gluOrtho2D(-axrng,axrng,-axrng,axrng)
    
def idle():
    if anim == 1 :
        glutPostRedisplay()
        
def bounce():
    global x,y,dx,dy,deg, s
    glClear(GL_COLOR_BUFFER_BIT)
    x += 0.001 * dx
    y += 0.001 * dy
    deg += 1
    
    s = (s +1 )% len(scale)
    
    glPushMatrix()
    
    glTranslate(x, y, 0)
    glRotated(deg,1,0,0)
    glScalef(scale[s],scale[s],scale[s])
    
    glutWireSphere(0.1,20,20)
    
    glPopMatrix()
    
    if x>=axrng-0.1 or x <= -axrng + 0.1:
        dx = -1 * dx
        
    if y>=axrng-0.1 or y <= -axrng + 0.1:
        dy = -1 * dy
    glutSwapBuffers()
     
def keyboard(key, x, y):
    global anim
    
    if key == b'a':
        anim = 1
    if key == b's':
        anim = 0 
        
def main():
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE)
    glutInitWindowPosition(100,100)
    glutInitWindowSize(width,height)
    glutCreateWindow('Bounce')
    glutDisplayFunc(bounce)
    glutIdleFunc(idle)
    glutKeyboardFunc(keyboard)
    
    init()
    glutMainLoop()
    
main()