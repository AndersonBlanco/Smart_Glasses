import cv2 
def init_img_cap():
    cap = cv2.VideoCapture(0)

    while True: 
        if cap.isOpened() != True:
            print('Cam unaccesable / not opened')
            break 

        ret,frame = cap.read()
        cv2.imshow(f'{ret}', frame)

        if cv2.waitKey(1) == ord('q'):
            break 



