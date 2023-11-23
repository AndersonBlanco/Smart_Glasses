import tensorflow as tf 
from tensorflow import keras 
import cv2
import pandas as pd
import matplotlib.pyplot as plt

def trainModel():
    model = keras.Sequential()
    model.add(keras.Input((1, 1)))
    model.add(keras.layers.LSTM(64, activation='tanh', return_sequences=True))
    model.add(keras.layers.LSTM(64, activation='tanh', return_sequences=False))
    model.add(keras.layers.Dense(1))

    