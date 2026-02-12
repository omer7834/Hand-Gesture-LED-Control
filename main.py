import cv2
from cvzone.HandTrackingModule import HandDetector
import serial

cap = cv2.VideoCapture(0)
detector = HandDetector(detectionCon=0.8, maxHands=1)
ser = serial.Serial('COM3', 9600)

while True:
    success, img = cap.read()
    hands, img = detector.findHands(img)

    if hands:
        fingers = detector.fingersUp(hands[0])
        count = fingers.count(1)
        ser.write(str(count).encode())

    cv2.imshow("Image", img)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
