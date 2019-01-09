class node:
    def __init__(self,value):
        '''
        objective: to create a node
        input parameter:
        self:object of type node
        value:value to be put into the node
        output :
        returns none
        '''
        self.data=value
        self.next=None
class Linkedlist:
    def __init__(self):
        '''
        objective: create a linked list
        input parameter:
        self:object of type linked list
        output:
        returns none
        '''
        self.head=None
    def insertbeginning(self,value):
        '''
        objective:to insert at  the beginning of the linked list
        input parameter:
        value:value to be put into the front
        output:
        returns none
        '''
        if self.head==None:
            self.head=node(value)
        else:
            temp=node(value)
            temp.next=self.head
            self.head=temp
    def __str__(self):
            '''
            objective:
            to print the linked list
            output :
            to print the list
            '''
            temp=self.head
            str1=''
            if temp==None:
                return "No Element reamining"
            while temp!=None:
                try:
                    str1=str1+' '+str(temp.data)
                    temp=temp.next
                except TypeError:
                    pass
            return str1
    def delete(self,value):
        '''
        objective: to delete a node in the linked list
        input parameter:
        value:value to be delete in the node
        output:none'''
        #deletion using iteration
        
        temp=self.head
        temp1=None
        while temp!=None:
            if temp.data==value:
                if temp==self.head:
                    self.head=temp.next
                    del(temp)
                else:
                    temp1.next=temp.next
                    del(temp)
                return
            else:
                temp1=temp
                temp=temp.next
        return "element not found"
    def deleterecur(self,value,prev,current):
        '''
        objective: to delete a node in the linked list
        input parameter:
        value:value to be delete in the node
        prev=pointer to the previous node
        current=pointng to the current node
        output:none'''
        if current==None:
            print("value not found")
            return
        if current.data==value:
            if  current==self.head:
                self.head=current.next
                print ("value deleted")
                return
            else:
                prev.next=current.next
                print ("value deleted")
                del(current)
        else:
            prev=current
            current=current.next
            self.deleterecur(value,prev,current)
        
    
def main():
    '''objective: main fnction to be called when the program runs
    input parameter :choice
    output:
    none
    '''
    l=Linkedlist()
    
    while 1:
        print("1. Insert at the beggining")
        print("2. Delete an element")
        print("3. Display")
        print("4. Quit")
        ch=int(input())
        if ch==1:
            value=int(input())
            l.insertbeginning(value)
        elif ch==2:
            value=int(input())
            l.deleterecur(value,None,l.head)
        elif ch==3:
            print(l)
        elif ch==4:
            break
        else:
            print("invalid choice")
            pass
        
if __name__=="__main__":
    main()
         
        
