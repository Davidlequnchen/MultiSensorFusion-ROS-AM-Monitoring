from threading import Timer,Thread,Event,Lock
import time
import logging


logging.basicConfig(level=logging.DEBUG,
                    format='(%(threadName)-9s) %(message)s',)


class MyThread(Thread):
    def __init__(self, interval, hFunction):
        Thread.__init__(self)
        self.hFunction = hFunction
        # self.stopped = event
        self.interval = interval
        
        # initialize a timer object to execute the function handler
        # this timer will call function handler after [interval] seconds
        self.thread = Timer(self.interval,self.function_handler)
        
    def function_handler(self):
        self.hFunction() # execute the function (the actual function for execution)
        # create a new timer to call the funciton_handler again
        self.thread = Timer(self.interval,self.function_handler)
        self.thread.start()
    
    def start(self):
        self.thread.start() # this will start the first timer
        
    def cancel(self):
        print ('before cancel thread.is_alive() = ', self.thread.is_alive())
        self.thread.cancel() # cancel the timer thread
        print ('after cancel thread.is_alive() = ', self.thread.is_alive())



class Main_class():
    def __init__(self):
        self.count = 0
        self.timer_function = MyThread(1,self.function) # wait 1s to execute function 
        # IMPORTANT: use "self.function" instead of self.function()
        self.timer_function.start()
        
        
    def function(self):
        countLock = Lock() # 若多个线程需要对共享变量进行更改，需要用Lock()方法
        countLock.acquire()
        
        logging.debug('thread function running')
        self.count +=1
        print (self.count)
        
        countLock.release()
    

            
def main():
    logging.debug('starting timers...')
    
    main_class = Main_class()
    
    
    time.sleep(5) # 5秒后停止定时器
    main_class.timer_function.cancel()
            
if __name__ == '__main__':            
    main()
