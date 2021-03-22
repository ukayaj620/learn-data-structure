class Node:
  
  def __init__(self, data):
    self.data = data
    self.next = None

  def __repr__(self):
    return f'Node({self.data})'


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


  def insert_after(self, find, data):
    node = Node(data)
    _, find_node = self.search(find)
    if find_node is not None:
      node.next = find_node.next
      find_node.next = node

      if find_node is self.tail:
        self.tail = node


  def delete(self, find):
    prev_find_node, find_node = self.search(find)
    if find_node is not None:
      if find_node is self.head:
        self.head = self.head.next
      elif find_node is self.tail:
        prev_find_node.next = None
        self.tail = prev_find_node
      else:
        prev_find_node.next = find_node.next
        

  def search(self, find):
    node = self.head
    node_prev = None
    while node is not None:
      if node.data == find:
        return node_prev, node

      node_prev = node
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


  def print(self):
    node = self.head
    if node is None:
      print("Linked list is empty!")
    else:
      print("\nHead: {}".format(self.head.data))
      print("Tail: {}".format(self.tail.data))
      print("Length: {}".format(self.length()))
      print("Data:", end=" ")
      while node:
        print(repr(node), end=" -> " if node.next is not None else "\n")
        node = node.next


if __name__=='__main__': 
  singlyLinkedList = SinglyLinkedList()
  
  singlyLinkedList.insert_node(100)
  singlyLinkedList.insert_node(-10)
  singlyLinkedList.insert_node(90)
  singlyLinkedList.insert_after(100, 10)
  singlyLinkedList.insert_after(90, 40)
  singlyLinkedList.insert_after(40, -80)
  singlyLinkedList.print()

  singlyLinkedList.delete(100)
  singlyLinkedList.print()

  singlyLinkedList.delete(-80)
  singlyLinkedList.print()

  singlyLinkedList.delete(10)
  singlyLinkedList.print()