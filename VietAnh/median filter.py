import cv2

img = cv2.imread("2.jpeg")

median = cv2.medianBlur(img, 5)

cv2.imshow("original", img)
cv2.imshow("new", median)

cv2.waitKey(0)
cv2.destroyAllWindows()