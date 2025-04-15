class MyStack:
    def __init__(self, capacity):
        """Khởi tạo stack với sức chứa tối đa"""
        self.capacity = capacity
        self.stack = []

    def is_empty(self):
        """Kiểm tra stack có rỗng không"""
        return len(self.stack) == 0

    def is_full(self):
        """Kiểm tra stack đã đầy chưa"""
        return len(self.stack) == self.capacity

    def push(self, value):
        """Thêm phần tử vào stack nếu chưa đầy"""
        if not self.is_full():
            self.stack.append(value)
        else:
            raise Exception("Stack is full")

    def pop(self):
        """Loại bỏ và trả về phần tử top nếu không rỗng"""
        if not self.is_empty():
            return self.stack.pop()
        else:
            raise Exception("Stack is empty")

    def top(self):
        """Trả về phần tử top mà không loại bỏ"""
        if not self.is_empty():
            return self.stack[-1]
        else:
            raise Exception("Stack is empty")


# VÍ DỤ
if __name__ == "__main__":
    stack = MyStack(capacity=4)

    # Push lần lượt các phần tử
    stack.push(31)
    stack.push(12)
    stack.push(10)
    stack.push(20)

    print("Is full?", stack.is_full())         
    print("Top before pop:", stack.top())     

    print("Pop 1:", stack.pop())              
    print("Top after pop 1:", stack.top())     

    print("Pop 2:", stack.pop())               
    print("Top after pop 2:", stack.top())     
    
    print("Pop 3:", stack.pop())  
    print("Top after pop 3:", stack.top())     

    print("Pop 4:", stack.pop())  

    print("\n>>> Kiểm tra stack rỗng")
    print(f"Stack is empty? {stack.is_empty()}")