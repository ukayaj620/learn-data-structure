class Node:
  
  def __init__(self, data):
    self.data = data
    self.next = None
    self.prev = None

  def __repr__(self):
    return f'Node({self.data})'


class DoubleLinkedList:

  def __init__(self):
    self.head = self.tail = None
  

  def insert_node(self, data):
    node = Node(data)

    if self.head is None:
      self.head = self.tail = node
    else:
      self.tail.next = node
      node.prev = self.tail
    
    self.tail = node


  def insert_after(self, find, data):
    node = Node(data)
    find_node = self.search(find)
    if find_node is not None:
      if find_node is self.tail:
        node.prev = self.tail
        self.tail.next = node
        self.tail = node
      else:
        node.next = find_node.next
        find_node.next.prev = node
        node.prev = find_node
        find_node.next = node


  def delete(self, find):
    find_node = self.search(find)
    if find_node is not None:
      if find_node is self.head:
        self.head = self.head.next
        self.head.prev = None
      elif find_node is self.tail:
        self.tail = find_node.prev
        self.tail.next = None
      else:
        find_node.prev.next = find_node.next
        find_node.next.prev = find_node.prev
        

  def search(self, find):
    node = self.head
    while node is not None:
      if node.data == find:
        return node

      node = node.next
    
    print("No data found!")
    return None


  def length(self):
    count = 0
    node = self.head
    while node:
      count += 1
      node = node.next

    return count


  def print_info(self):
    print("\nHead: {}".format(self.head.data))
    print("Tail: {}".format(self.tail.data))
    print("Length: {}".format(self.length()))


  def print_forward(self):
    node = self.head
    if node is None:
      print("Linked list is empty!")
    else:
      self.print_info()
      print("Data (Forward Formation):", end=" ")
      while node:
        print(repr(node), end=" -> " if node.next is not None else "\n")
        node = node.next

  def print_backward(self):
    node = self.tail
    if node is None:
      print("Linked list is empty!")
    else:
      self.print_info()
      print("Data (Backward Formation):", end=" ")
      while node:
        print(repr(node), end=" -> " if node.prev is not None else "\n")
        node = node.prev


if __name__=='__main__': 
  doubleLinkedList = DoubleLinkedList()
  
  doubleLinkedList.insert_node(100)
  doubleLinkedList.insert_node(-10)
  doubleLinkedList.insert_node(90)
  doubleLinkedList.insert_after(100, 10)
  doubleLinkedList.insert_after(90, 40)
  doubleLinkedList.insert_after(40, -80)
  doubleLinkedList.print_forward()
  doubleLinkedList.print_backward()

  doubleLinkedList.delete(100)
  doubleLinkedList.print_forward()
  doubleLinkedList.print_backward()

  doubleLinkedList.delete(-80)
  doubleLinkedList.print_forward()
  doubleLinkedList.print_backward()

  doubleLinkedList.delete(10)
  doubleLinkedList.print_forward()
  doubleLinkedList.print_backward()