from threading import Timer,Thread,Event

class MyThread(Thread):
    def __init__(self, event):
        Thread.__init__(self)
        self.stopped = event
        self.time = 0

    def run(self):
        while not self.stopped.wait(1):
            print("my thread")
            self.time += 0.1
            print(self.time)
            # call a function
            
            
stopFlag = Event()
thread = MyThread(stopFlag)
thread.start()
# this will stop the timer
if thread.time > 1:
    # stopFlag.set()
    thread.cancel()
    