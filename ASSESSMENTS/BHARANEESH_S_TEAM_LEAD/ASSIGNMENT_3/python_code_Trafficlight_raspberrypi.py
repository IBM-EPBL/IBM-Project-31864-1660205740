from gpiozero import LED
from time import sleep

red = LED(22)
yellow = LED(27)
green = LED(17)
while True:
    red.on()
    sleep(10)
    red.off()
    sleep(1)
    yellow.on()
    sleep(2)
    yellow.off()
    sleep(1)
    green.on()
    sleep(10)
    green.off()
    sleep(1)