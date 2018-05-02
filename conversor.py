from PIL import Image
import numpy as np

im = Image.open("maze.bmp")
col,row = im.size
data=[]
pixels=im.load()
Matrix=[[0]*row]*col
i=o=p=j=0

img = open('grafo.txt','w')

for i in range(row):
    for j in range(col):
        if(j==col-1):
            img.write('\n')
        if(pixels[i,j][0]==255):
            img.write('0')
        else:
            img.write('1')
            
img.close()
