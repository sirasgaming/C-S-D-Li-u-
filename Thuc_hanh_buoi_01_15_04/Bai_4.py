class MyQueue:
    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = [None] * capacity
        self.front_index = 0
        self.rear_index = 0
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.capacity

    def enqueue(self, value):
        if self.is_full():
            print("Queue is full")
            return
        self.queue[self.rear_index] = value
        self.rear_index = (self.rear_index + 1) % self.capacity
        self.size += 1

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty")
            return None
        value = self.queue[self.front_index]
        self.queue[self.front_index] = None  # optional: clear value
        self.front_index = (self.front_index + 1) % self.capacity
        self.size -= 1
        return value

    def front(self):
        if self.is_empty():
            print("Queue is empty")
            return None
        return self.queue[self.front_index]

    def print_queue(self):
        result = []
        index = self.front_index
        for _ in range(self.size):
            result.append(self.queue[index])
            index = (index + 1) % self.capacity
        print("Queue state:", result)



#  Ví dụ


queue1 = MyQueue(capacity=5)

queue1.enqueue(31)
queue1.enqueue(12)
queue1.enqueue(10)
queue1.print_queue()  

print(queue1.is_full())       

print(queue1.front())         
print(queue1.dequeue())      

queue1.print_queue()          

print(queue1.front())         
print(queue1.dequeue())       

queue1.print_queue()          

print(queue1.is_empty())      
