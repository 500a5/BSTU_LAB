import cv2 as cv
import numpy as np

width = 5
height = 5
qipan_cell = 100
width_pix = (width + 1) * qipan_cell + qipan_cell  # add extra  qipan_cell  for reserve blank
height_pix = (height + 1) * qipan_cell + qipan_cell

# white = (255,255,255)
# black =  (0,0,0)


image = np.zeros((height_pix, width_pix, 3), dtype=np.uint8)
image.fill(255)

# Создать окно отображения
win_name = "qipan"
cv.namedWindow("qipan", cv.WINDOW_AUTOSIZE)
cv.imshow(win_name, image)
color = (255, 255, 255)

y0 = 0
fill_color = 0
for j in range(0, height + 1):
    y = j * qipan_cell
    for i in range(0, width + 1):
        # rint(i)
        x0 = i * qipan_cell
        y0 = y
        rect_start = (x0, y0)

        x1 = x0 + qipan_cell
        y1 = y0 + qipan_cell










































































































































































































































































































rect_end = (x1, y1)
print(x0, y0, x1, y1, fill_color)
cv.rectangle(image, rect_start, rect_end, color, 1, 0)
# print(fill_color)
# image[y0:y1, x0:x1] = fill_color
# if width % 2:

    if i != width:
                fill_color = (0 if (fill_color == 255) else 255)
        else:
            if i != width + 1:
                fill_color = (0 if (fill_color == 255) else 255)

# image[0:20,0:20] = 0
# image[40:60,0:20] = 0

cv.imwrite("qipan_%d_W_%d_H.jpg" % (width, height), image)
cv.imshow(win_name, image)

cv.waitKey()
