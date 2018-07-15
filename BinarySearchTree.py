class Node:
    def __init__(self, data):
        self.data = data
        self.LeftChild = None
        self.RightChild = None

    def insert(self, x):
        if(self.data==x):
            return False

        else:
            if(self.data>x):
                if(self.LeftChild):
                    self.LeftChild.insert(x)
                else:
                    self.LeftChild = Node(x)

            else:
                if(self.RightChild):
                    self.RightChild.insert(x)
                else:
                    self.RightChild = Node(x)
            return True

    def find(self, x):
        if(self.data == x):
            return True
        else:
            if(self.data > x):
                if(self.LeftChild):
                    return self.LeftChild.find(x)
                else:
                    return False

            else:
                if(self.RightChild):
                    return self.RightChild.find(x)
                else:
                    return False

    def preorder(self):
        print(self.data)        

        if(self.LeftChild):
            self.LeftChild.preorder()
            
        if(self.RightChild):
            self.RightChild.preorder()

    def postorder(self):
        if(self.LeftChild):
            self.LeftChild.postorder()
            
        if(self.RightChild):
            self.RightChild.postorder()

        print(self.data)

    def inorder(self):
        if(self.LeftChild):
            self.LeftChild.inorder()

        print(self.data)
            
        if(self.RightChild):
            self.RightChild.inorder()

    def getSize(self):
        if(self.LeftChild and self.RightChild):
            return 1+self.LeftChild.getSize()+self.RightChild.getSize()
        elif(self.LeftChild):
            return 1+self.LeftChild.getSize()
        elif(self.RightChild):
            return 1+self.RightChild.getSize()
        else:
            return 1

    def getHeight(self):
        if(self.LeftChild and self.RightChild):
            return 1+max(self.LeftChild.getHeight(),self.RightChild.getHeight())
        elif(self.LeftChild):
            return 1+self.LeftChild.getHeight()
        elif(self.RightChild):
            return 1+self.RightChild.getHeight()
        else:
            return 1


class Tree:
    def __init__(self):
        self.root = None

    def insert(self, x):
        if(self.root):
            self.root.insert(x)
        else:
            self.root = Node(x)

    def find(self, x):
        if(self.root):
            return self.root.find(x)
        else:
            return False

    def preorder(self):
        print("PreOrder:")
        self.root.preorder()

    def postorder(self):
        print("PostOrder:")
        self.root.postorder()

    def inorder(self):
        print("InOrder:")
        self.root.inorder()

    def getSize(self):
        if(self.root):
            return self.root.getSize()
        else:
            return 0

    def getHeight(self):
        if(self.root):
            return self.root.getHeight()
        else:
            return 0




obj = Tree()
obj.insert(10)
obj.insert(15)
obj.insert(30)
obj.insert(5)
obj.insert(2)
obj.insert(1)
#print(obj.find(10))
#print(obj.find(30))
#print(obj.find(23))
#print(obj.find(50))
obj.preorder()
print("***************")
obj.postorder()
print("***************")
obj.inorder()
print("***************")
print("Size of BST is: ",obj.getSize())
print("***************")
print("Height of BST is: ",obj.getHeight())
print("***************")

            
