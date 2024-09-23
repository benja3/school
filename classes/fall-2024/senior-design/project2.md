# Project 2

Image Processing related

using 2d matrix in matlab

image Processing can involve more than pixels

starting with smallest unit: pixel

use matlab 2d matrix with coordinates

## Techniques

### Background Subtraction

use to separate foreground and background

foreground is what we are interested in  

one option: know exactly what pixels correspond to the board

take a reference image with an empty board and see what changes between the current and reference

could also do previous image to see what changes between turns

### intensity thresholding

foreground separation

histrogram represents the intensity of the greyscale values in the image

relies on the foreground being brighter than the background

### morphological operations

used to remove noise from image after background subtraction

dialation can make the foreground more clear

erosion can shrink things

combinations of dialation and erosion can help

### regions

regionprops function relies on a good binary image input

### color processing

difficult because can change under lighting conditions

use 3d matrix with the 3rd element being color

### design

keep camera height and angle fixed

include constant lighting source

keep the image input as similar between runs as possible

see slides for useful matlab functions
