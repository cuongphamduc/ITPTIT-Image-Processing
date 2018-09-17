import cv2

img = cv2.imread("2.jpeg")
blur = cv2.blur(img, (5, 5))

cv2.imshow("original", img)
cv2.imshow("new", blur)

cv2.waitKey(0)
cv2.destroyAllWindows()