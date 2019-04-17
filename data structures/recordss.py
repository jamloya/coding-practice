import random,pickle
class node:
    def __init__(self):
        self.key=[None]*4
        self.links=[None]*5
    def getkey(self):
        return self.key
    def getlinks(self):
        return self.links
        
class Record:
    '''
    objective: to create a record object with key and non key attribute'''

    def __init__(self,key,others):

        self.key=key
        self.nonkey=others

    def getkey(self):

        '''objective: return key of the object'''
        return self.key
    
def lookup(number,filename):
    '''objective to check the record number in file"'''

    f=open(filename,'rb')
    start=f.tell()
    pickle.load(f)
    end=f.tell()
    offset=end-start
    f.seek(offset*(number-1))
    print(pickle.load(f).key)
    f.close()
    
'''def bplustree(maxlevel,no,filename):
    
    objective:to create a b plus tree out of records
    input parameter:
    no=no of values that should be in a node
    filename: file which contains record 

    n=node(no)
    f=open(filename,"rb")
    try:
        for i in range(1,201,10):
            if n.key[0]==None:
                for j in range(0,no):
                    n.key[0]=pickle.load(f).key
'''
class index:
    def __init__(self):        
        n0=node()
        n=node()
        #1st record
        f=open('index.txt','wb')
        n0.key[0]=1
        n.key[0]=(10000+200,1)
        pickle.dump(n0,f)
        pickle.dump(n,f)
        f.close()
        #2nd record
        f=open('index.txt','rb')
        n0=pickle.load(f)
        n=pickle.load(f)
        f.close()
        f=open('index.txt','wb')
        n.key[1]=(10000+300,2)
        pickle.dump(n0,f)
        pickle.dump(n,f)
        f.close()
        #3rd record
        f=open('index.txt','rb')
        n0=pickle.load(f)
        n=pickle.load(f)
        f.close()
        f=open('index.txt','wb')
        n.key[2]=n.key[1]
        n.key[1]=(10000+250,3)
        pickle.dump(n0,f)
        pickle.dump(n,f)
        f.close()
        #4th record
        f=open('index.txt','rb')
        n0=pickle.load(f)
        n=pickle.load(f)
        f.close()
        f=open('index.txt','wb')
        n.key[3]=(10000+304,4)
        pickle.dump(n0,f)
        pickle.dump(n,f)
        f.close()

        #5th record
        n1,n2=node(),node()
        f=open('index.txt','rb')
        n0=pickle.load(f)
        n=pickle.load(f)
        f.close()
        n1.key[0],n.key[2],n2.key[0]=n.key[2],None,n.key[3]
        n.key[3]=None
        f=open('index.txt','wb')
        n2.key[1]=(10000+400,5)
        pickle.dump(n0,f)
        pickle.dump(n,f)
        pickle.dump(n1,f)
        pickle.dump(n2,f)
        f.close()

        #6th record
        f=open('index.txt','rb')
        n0=pickle.load(f)
        n=pickle.load(f)
        n1=pickle.load(f)
        n2=pickle.load(f)
        f.close()
        f=open('index.txt','wb')
        n.key[2],n.key[1]=n.key[1],(10000+225,6)
        pickle.dump(n0,f)
        pickle.dump(n,f)
        pickle.dump(n1,f)
        pickle.dump(n2,f)
        f.close()

        #7th record
        f=open('index.txt','rb')
        n0=pickle.load(f)
        n=pickle.load(f)
        n1=pickle.load(f)
        n2=pickle.load(f)
        f.close()
        f=open('index.txt','wb')
        n2.key[2]=(10000+500,7)
        pickle.dump(n0,f)
        pickle.dump(n,f)
        pickle.dump(n1,f)
        pickle.dump(n2,f)
        f.close()

        #8th record
        f=open('index.txt','rb')
        n0=pickle.load(f)
        n=pickle.load(f)
        n1=pickle.load(f)
        n2=pickle.load(f)
        f.close()
        f=open('index.txt','wb')
        n2.key[2],n2.key[3]=(10000+450,8),n2.key[2]
        pickle.dump(n0,f)
        pickle.dump(n,f)
        pickle.dump(n1,f)
        pickle.dump(n2,f)
        f.close()

        #9th record
        f=open('index.txt','rb')
        n0=pickle.load(f)
        n=pickle.load(f)
        n1=pickle.load(f)
        n2=pickle.load(f)
        f.close()

        f=open('index.txt','wb')
        n.key[3]=(10000+290,9)

        #links
        n0.key[0],n0.links[0]=2,n1
        n1.links[0],n1.links[1]=n,n2

        pickle.dump(n0,f)
        pickle.dump(n,f)
        pickle.dump(n1,f)
        pickle.dump(n2,f)
        f.close()

        '''f=open('index.txt','rb')
        n=pickle.load(f)
        print(n.links[0].getlinks())
        print(n.getkey(),pickle.load(f).getkey(),pickle.load(f).getkey(),pickle.load(f).getkey())
        f.close()'''
        
    def search(self,value):
        '''
            objective:search for the record in the tree
            input:number to be searched in the tree
            output:if exist give the record number
            ''' 

        f=open('index.txt','rb')
        root=pickle.load(f)
        n=pickle.load(f)
        n1=pickle.load(f)
        n2=pickle.load(f)
        current=root.links[0]
        foundflag=False
        if (current.key[0][0]-10000)==value:
            print('\nrecord found')
            print('record value & record number =',current.key[0][0]-10000, " & ",current.key[0][1])
        elif (current.key[0][0]-10000)>value:
            current=current.links[0]
            print(current.getkey())
            for i in current.key:
                if i[0]-10000==value:
                    print('\nrecord found')
                    print('record value & record number =',i[0]-10000, " & " ,i[1])
                    foundflag=True
                    break
            if foundflag==False:
                print('\nrecord not found')
        elif (current.key[0][0]-10000)<value:
            current=current.links[1] 
            for i in current.key:
                if i[0]-10000==value:
                    print('\nrecord found')
                    print('record value & record number =',i[0]-10000, " & " ,i[1])
                    foundflag=True
                    break
            if foundflag==False:
                print('\nrecord not found')            
                
                  
                  
                  

        f.close()



def main():

    chklst=[]
    f=open("f.txt","wb")
    for i in range(1,200+1):
        key=random.randint(100000,200000)
        while key in chklst:
            key=random.randint(100000,200000)
            
        chklst.append(key)
        others=str(key)*9
        n=Record(key,others)
        pickle.dump(n,f)
    f.close()
    ''' f=open("f.txt","rb")
    for i in range(1,201):
        print(pickle.load(f).key)'''
    i=index()
    if input('would you want to search a record')== 'y' :
        i.search(int(input('enter the record you want to search for')))
    
    #if ((input("enter y if you want to check record")=='y')):
     #   lookup(int(input("enter record number you want to check")),input("enter filename"))
    

main()
