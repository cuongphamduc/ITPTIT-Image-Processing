import cv2
img = cv2.imread("2.jpeg", 0)
thresh = 100
img_bw = cv2.threshold(img, thresh, 255, cv2.THRESH_BINARY)[1]
cv2.imshow("aaa", img_bw)
cv2.waitKey(0)
