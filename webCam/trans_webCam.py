import tensorflow as tf 
from tensorflow import keras
import matplotlib.pyplot as plt
import pandas as pd
import cv2 

def init_liveFeed():
    cap = cv2.VideoCapture(0)
    while True:
         if (cap.isOpened()) == False:
              print('Camera unaccesable / not open')
              break
    

         ret,frame = cap.read()
         cv2.imshow('Feed', frame) 

         if cv2.waitKey(1) == ord('q'):
              break
         
init_liveFeed()
         