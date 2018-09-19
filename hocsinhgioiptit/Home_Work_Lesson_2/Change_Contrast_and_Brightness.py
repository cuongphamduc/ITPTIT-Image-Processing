import cv2
img = cv2.imread("Ava.png")
img = cv2.resize(img, (400, 400))
ori = cv2.imread("Ava.png")
ori = cv2.resize(img, (400, 400))
contrast = 0.5
brightness = 50
rows, cols, channels = img.shape
for i in range (rows):
    for j in range (cols):
    	for k in range (channels):
        img[i][j][k] = img[i][j][0]*contrast + brightness
cv2.imshow('After', img)
cv2.imshow('Before', ori)
cv2.waitKey(0)
cv2.destroyAllWindows()