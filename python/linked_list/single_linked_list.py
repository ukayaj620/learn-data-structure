class Node:
  
  def __init__(self, data):
    self.data = data
    self.next = None

class SinglyLinkedList:

  def __init__(self):
    self.head = self.tail = None
  

  def insert_node(self, data):
    node = Node(data)

    if self.head is None:
      self.head = self.tail = node
    else:
      self.tail.next = node
    
    self.tail = node


  def length(self):
    count = 0
    node = self.head
    while node:
      count += 1
      node = node.next

    return count


  def print(self):
    node = self.head
    while node:
      print(node.data, end=" ")
      node = node.next


if __name__=='__main__': 
  singlyLinkedList = SinglyLinkedList()
  while True:
    data = input()
    if data == "":
      break
    singlyLinkedList.insert_node(int(data))

singlyLinkedList.print()