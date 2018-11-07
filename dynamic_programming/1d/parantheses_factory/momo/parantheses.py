class Stack:
     def __init__(self):
         self.items = []

     def isEmpty(self):
         return self.items == []

     def push(self, item):
         self.items.append(item)

     def pop(self):
         return self.items.pop()

     def peek(self):
         return self.items[len(self.items)-1]

     def size(self):
         return len(self.items)


n = int(input())
input = input()
stack = Stack()
result = [0]*(n+1)
i = n-1

while i != -1:
	if input[i]==')' or input[i]== ']' or input[i]=='>' or input[i]== '}':
		stack.push(input[i])
	elif not (stack.isEmpty()):
		if (input[i] == '(' and stack.peek() == ')' ) \
				or (input[i] == '[' and stack.peek() == ']')\
				or (input[i] == '<' and stack.peek() == '>')\
				or (input[i] == '{' and stack.peek() == '}'):
			stack.pop()
			result[i] = 2
			if i < n-2:
				result[i] += result[i + 1]
				result[i] += result[i + result[i]]
		else:
			while not stack.isEmpty():
				stack.pop()

	i -= 1
for i in range(n):
	print(result[i], end=" ")


