from threading import Timer,Thread,Event
import logging

'''
Timer class represents an action that should be run only after a certain amount of time has passed.
start the timer thread: start() method. The timer can be stopped (before its action has begun) -- cancel() method.
definition of Timer: 
class threading.Timer(interval, function, args=None, kwargs=None)
'''


class perpetualTimer():
    
    def __init__(self,t,hFunction):
      self.t=t
      self.hFunction = hFunction
      self.thread = Timer(self.t,self.handle_function)

    def handle_function(self):
      self.hFunction() # call the function
      self.thread = Timer(self.t,self.handle_function)
      self.thread.start()

    def start(self):
      self.thread.start()

    def cancel(self):
      self.thread.cancel()

def printer():
    print ('ipsem lorem')



# t = perpetualTimer(0.1,printer)
# t.start()

# t = Timer(0.1, printer) # only one time
# t.start()
