class MinStack:

    def __init__(self):
        self.stack = []
        self.minstack = []
        

    def push(self, val: int) -> None:
        self.stack.append(val)
        
        if (len(self.minstack) == 0 or 
            self.minstack[-1] >= val):
            self.minstack.append(val)
            

    def pop(self) -> None:
        if len(self.stack) != 0:
            curElem = self.stack[-1]
            self.stack.pop()
            
            while (len(self.minstack) > 0 and
                self.minstack[-1] >= curElem):
                popped_elem = self.minstack[-1]
                self.minstack.pop()
                if popped_elem == curElem:
                    break
                    
    
    def top(self) -> int:
        if(len(self.stack) != 0):
            return self.stack[-1]
        
        return None
        
        

    def getMin(self) -> int:
        if len(self.minstack) != 0:
            return self.minstack[-1]
        
        return -1
        


# Your MinStack object will be instantiated and called as such:
obj = MinStack()
obj.push(3)
print(obj.top());
print("Min", obj.getMin());
obj.push(4)
print(obj.top());
print("Min", obj.getMin());
obj.push(2)
print(obj.top());
print("Min", obj.getMin());

obj.pop()
print(obj.top());
print("Min", obj.getMin());
obj.pop()
print(obj.top());
print("Min", obj.getMin());
obj.pop()
print(obj.top());
print("Min", obj.getMin());
print(obj.top());
print("Min", obj.getMin());
obj.pop()
obj.pop()
print(obj.top());
print("Min", obj.getMin());
print("Min", obj.getMin());