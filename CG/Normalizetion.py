from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import sys
import numpy as np
from PIL import Image

global x, y

x = 0
y = 0

width = 250
height = 500

axrng = 1

def loadImage(filename):
    img = Image.open(filename)
    img = img.convert("RGB")
    return img

def makeImage(image, resize=None):
    if resize is not None:
        image = image.resize(resize)
    width, height = image.size
    image_data = list(image.getdata())
    data = []
    for i in range(height):
        row = []
        for j in range(width):
            r, g, b = image_data[i*width + j]
            row.append((r, g, b))
        data.append(row)
    return data, width, height

def init():
    image = loadImage("./CG/image/hopless_cat.png")
    
    # Convert the image to a format that can be used by glDrawPixels
    image_data, img_width, img_height = makeImage(image)

    # Create a numpy array from the image data
    image_array = np.array(image_data, dtype=np.uint8)
    
    # Store the image array as a global variable
    global myImage
    myImage = image_array
    
    glClearColor(0.0, 0.0, 0.0, 1.0)
    glColor3ub(255, 100, 0)
    gluOrtho2D(-axrng, axrng, -axrng, axrng)
    


def tranform():
    
    global x, y
    
    glClear(GL_COLOR_BUFFER_BIT)
    xw_max = 500
    yw_max = 500
    xw_min = 10
    yw_min = 10
    Mws = [2/(xw_max-xw_min), -(xw_max + xw_min)/(xw_min-xw_max),2/(yw_max-yw_min),-(yw_max + yw_min)/(yw_max-yw_min)]
    
    xv_max = width
    yv_max = height
    xv_min = 0
    yv_min = 0
    Mv = [(xv_max-xv_min)/2, (xv_max + xv_min)/2,(yv_max-yv_min)/2,(yv_max + yv_min)/2]

    Nor_s = np.array([
        Mws[0], 0, Mws[1], 0, 
        0, Mws[2], Mws[3], 0, 
        0, 0, 1, 0,
        0, 0, 0, 1])
    M_v = np.array([
        Mv[0], 0, Mv[1], 0, 
        0, Mv[2], Mv[3], 0, 
        0, 0, 1, 0,
        0, 0, 0, 1])
    # Transform the object.
    full_transform = np.matmul(win_view, np.matmul(win_norm, norm_view))

    
    
    glPushMatrix()
    
    glMultMatrixf(m1)
    glMultMatrixf(m2)
    glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, myImage)
    
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
