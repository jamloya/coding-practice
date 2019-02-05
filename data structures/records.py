import pickle,random,os
class Record:
    '''
    objective: to represent a record entity
    '''
    count=1
    lst=[]
    def __init__(self):
        '''
        objective: initialization function
        input parameter:
        self:implicit parameter
        output: return none
        '''
        temp=random.randint(1000000,2000000)
        while temp in Record.lst:
            temp=random.randint(1000000,2000000)
        self.key=temp
        Record.lst.append(temp)
        Record.count+=1
        self.other=str(self.key)*random.randint(50,250)
    def __str__(self):
        '''
        objective:return a string comprising key and other value
        input:
        self:implicit parameter
        '''
        return str(self.key)+(" ")+str(self.other)
    def getkey(self):
        '''objective:it will return the value of the key of the
                    corresponding object
            input parameters:
            self:implicit parameter
            ouput; return the key
            '''
        return str(self.key)
    def getothers(self):
        '''objective;it should return the value of other
        input parameter:
        self;implicit parameter
         output;returns string other
         '''
        return str(self.other)
def keyvalue(r):
    return r.key
def merge(lst,lst1):
    '''objective:to sort the list of records and merge them
        input parameters :two list that needs to be merged in sorted order
        output: none
        '''
    temp=[]
    while lst!=[] and lst1!=[]:
        if lst[0].key<lst1[0].key:
            temp.append(lst[0])
            del lst[0]
        else:
            temp.append(lst1[0])
            del lst1[0]
    if lst!=[]:
        while lst!=[]:
            temp.append(lst[0])
            del lst[0]
    if lst1!=[]:
        while lst1!=[]:
            temp.append(lst1[0])
            del lst1[0]
    return temp

def sort(numrec,block=4):
    '''objective to sort and store it in file 3 and file 4
    input parameter:blocksize:block size we need to pick from file2 and file 3
    output parameter: none
    '''
    print(block)
    if (block*2)>numrec:
        return
    else:
        f1=open('file2.txt','rb')
        f2=open('file3.txt','rb')
        f3=open('file4.txt','wb')
        f4=open('file5.txt','wb')
        temp=[]
        lst=[]
        lst1=[]
        flag=0
        try:
            while f1 or f2:
                if flag==0:
                    for i in range(0,block):
                        ob=pickle.load(f1)
                        lst.append(ob)
                        ob1=pickle.load(f2)
                        lst1.append(ob1)
                    temp=merge(lst,lst1)
                    for i in range(0,block*2):
                        pickle.dump(temp[i],f3)
                    del temp[:]
                    del lst[:]
                    del lst1[:]
                    flag=1
                else:
                    for i in range(0,block):
                        ob=pickle.load(f1)
                        lst.append(ob)
                        ob1=pickle.load(f2)
                        lst1.append(ob1)
                    temp=merge(lst,lst1)
                    for i in range(0,block*2):
                        pickle.dump(temp[i],f4)
                    del temp[:]
                    del lst[:]
                    del lst1[:]
                    flag=0
        except EOFError:
            if os.stat("file5.txt").st_size == 0:
                try:
                    for i in range(0,block):
                        ob=pickle.load(f1)
                        pickle.dump(ob,f4)
                except EOFError:
                    pass

            pass
        f2.close()
        f1.close()
        f3.close()
        f4.close()
        os.remove('file2.txt')
        os.remove('file3.txt')
        os.rename('file4.txt','file2.txt')
        os.rename('file5.txt','file3.txt')
        sort(numrec,(block*2))
def main():
    '''
    objective :main function to be called and store the value of key and other values
    from one file to other
    input parameter: none
    output: none
    '''
    f1=open('file1.txt',"wb")
    for i in range(1,100):
        r=Record()
        pickle.dump(r,f1)
    f1.close()
    f=open('file1.txt','rb')
    f1=open('file2.txt','wb')
    f2=open('file3.txt','wb')
    flag=0
    lst=[]
    try:
        while f:
            if flag==0:
                for i in range(0,4):
                    ob=pickle.load(f)
                    lst.append(ob)
                lst.sort(key=keyvalue)
                for i in range (0,4):
                    pickle.dump(lst[i],f1)
                flag=1
                del lst[:]
            else:
                for i in range(0,4):
                    ob=pickle.load(f)
                    lst.append(ob)
                lst.sort(key=keyvalue)
                for i in range (0,4):
                    pickle.dump(lst[i],f2)
                flag=0
                del lst[:]
    except EOFError:
        pass
    f.close()
    f1.close()
    f2.close()
    sort(100)
    f1=open('file2.txt','rb')
    f2=open('file3.txt','rb')

    while f1:
         ob=pickle.load(f2)
         print (ob.key)
    
main()
