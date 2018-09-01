import cv2
img = cv2.imread("2.jpeg")
img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow("gray image", img)
cv2.waitKey(0)
