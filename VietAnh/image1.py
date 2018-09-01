import cv2
img = cv2.imread("2.jpeg", 0)
thesh = 100
img = cv2.threshold(img, thesh, 255, cv2.THRESH_BINARY)[1]
cv2.imshow("black white", img)
cv2.waitKey(0)
