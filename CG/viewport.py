from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import numpy as np
from PIL import Image

# Globals for animation, ball position and direction of motion.
global x, y

# Initial position of the ball.
x = 0.34
y = 0.34

# Window dimenstions.
width = 1000
height = 800
axrng = 1.0


def init():
    glClearColor(0.0, 0.0, 0.0, 1.0)
    # Dimensions of the screen (try increase axrng).
    gluOrtho2D(-axrng, axrng, -axrng, axrng)


def transform():
    global x, y
    glClear(GL_COLOR_BUFFER_BIT)
    #image
    yw_max = 500  # height
    xw_max = 500  # width
    yw_min = 0  # height
    xw_min = 0  # width
    #viewport
    yv_max = 450  # height
    xv_max = 450  # width
    yv_min = 0  # height
    xv_min = 0  # width

    sx = (xv_max - xv_min)/(xw_max - xw_min)
    sy = (yv_max - yv_min)/(yw_max - yw_min)

    tx = ((xw_max * xv_min) - (xw_min * xv_max))/(xw_max - xw_min)
    ty = ((yw_max * yv_min) - (yw_min * yv_max))/(yw_max - yw_min)
    Mv = [(xv_max - xv_min)/2, (xv_max + xv_min)/2,
          (yv_max - yv_min)/2, (yv_max + yv_min)/2]
    Mws = [2/(xw_max - xw_min), -(xw_max + xw_min)/(xw_max - xw_min),
           2/(yw_max - yw_min), -(yw_max + yw_min)/(yw_max - yw_min)]

    win_view = np.array([sx, 0, 0, 0,
                        0, sy, 0, 0,
                        0, 0, 1, 0,
                        tx, ty, 0, 1]).reshape((4, 4))

    win_norm = np.array([Mws[0], 0, 0, 0,
                         0, Mws[2], 0, 0,
                         0, 0, 1, 0,
                         Mws[1], Mws[3], 0, 1]).reshape((4, 4))

    norm_view = np.array([Mv[0], 0, 0, 0,
                          0, Mv[2], 0, 0,
                          0, 0, 0.5, 0,
                          Mv[1], Mv[3], 0.5, 1]).reshape((4, 4))

    # Transform the object.
    full_transform = np.matmul(win_view, np.matmul(win_norm, norm_view))

    # Apply the transformation to the object.
    glPushMatrix()
    glMultMatrixf(full_transform)

    # Load the texture image file and bind it to a texture ID.
    texture_file = "./CG/image/hopless_cat.png"
    texture_id = glGenTextures(1)
    glBindTexture(GL_TEXTURE_2D, texture_id)
    img = Image.open(texture_file)
    img_data = np.array(list(img.getdata()), np.uint8)

    # Flip the image data.
    img_data = np.flipud(img_data)

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 img.size[0], img.size[1], 0, GL_RGB, GL_UNSIGNED_BYTE, img_data)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)

     # Apply the transformation to the object.
    glPushMatrix()
    glMultMatrixf(win_view)
    glTranslatef( -0.8,0,0.)
    # Enable texturing.
    glEnable(GL_TEXTURE_2D)
    glBegin(GL_QUADS)
    glTexCoord2f(1.0, 0.0)
    glVertex2f(-0.5, -0.5)
    glTexCoord2f(1.0, 1.0)
    glVertex2f(-0.5, 0.5)
    glTexCoord2f(0.0, 1.0)
    glVertex2f(0.5, 0.5)
    glTexCoord2f(0.0, 0.0)
    glVertex2f(0.5, -0.5)
    glEnd()

    glDisable(GL_TEXTURE_2D)

    # Finish the frame.
    glPopMatrix()

    # Apply the transformation to the object.
    glPushMatrix()
    glMultMatrixf(win_norm)
    glScalef(100,100,100)
    glTranslatef( 2.7,2,0.)
    # Enable texturing.
    glEnable(GL_TEXTURE_2D)
    glBegin(GL_QUADS)
    glTexCoord2f(1.0, 0.0)
    glVertex2f(-0.5, -0.5)
    glTexCoord2f(1.0, 1.0)
    glVertex2f(-0.5, 0.5)
    glTexCoord2f(0.0, 1.0)
    glVertex2f(0.5, 0.5)
    glTexCoord2f(0.0, 0.0)
    glVertex2f(0.5, -0.5)
    glEnd()

    glDisable(GL_TEXTURE_2D)

    # Finish the frame.
    glPopMatrix()


    # Apply the transformation to the object.
    glPushMatrix()
    glMultMatrixf(full_transform)
    glTranslatef( 1,-0.25,0.)
    # Enable texturing.
    glEnable(GL_TEXTURE_2D)
    glBegin(GL_QUADS)
    glTexCoord2f(1.0, 0.0)
    glVertex2f(-0.5, -0.5)
    glTexCoord2f(1.0, 1.0)
    glVertex2f(-0.5, 0.5)
    glTexCoord2f(0.0, 1.0)
    glVertex2f(0.5, 0.5)
    glTexCoord2f(0.0, 0.0)
    glVertex2f(0.5, -0.5)
    glEnd()

    glDisable(GL_TEXTURE_2D)

    # Finish the frame.
    glPopMatrix()

    glutSwapBuffers()


def main():
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE)
    glutInitWindowPosition(400, 100)
    glutInitWindowSize(width, height)
    glutCreateWindow('Viewport')
    glutDisplayFunc(transform)
    init()
    glutMainLoop()


main()
