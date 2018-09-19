import cv2
img = cv2.imread("ava.png")
ori = cv2.imread("ava.png")
r, c, channel = img.shape
for i in range(1, r - 1):
    for j in range(1, c - 1):
        for k in range(0, channel):
            temp = [0 * img[i - 1, j - 1, k] , 1 * img[i - 1, j, k] , 0 * img[i - 1, j + 1, k]
                                  , 1 * img[i, j - 1, k] , 4 * img[i, j, k] , 1 * img[i, j + 1, k]
                                  , 0 * img[i + 1, j - 1, k] , 1 * img[i + 1, j, k] , 0 * img[i + 1, j + 1, k]]
            img[i, j, k] = temp[4]
cv2.imshow('origin', ori)
cv2.imshow('image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
