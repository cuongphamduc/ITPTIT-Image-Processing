import cv2
import numpy as np

alpha = float(input(" Enter contrast value : "))
beta = int(input("Enter brightness value : "))
img = cv2.imread("1.jpeg")

mulimg = cv2.multiply(img, np.array([alpha]))
newimg = cv2.add(mulimg, beta)

cv2.imshow("Original ", img)
cv2.imshow("new", newimg)

cv2.waitKey(0)
cv2.destroyAllWindows()