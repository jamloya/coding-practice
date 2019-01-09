def heapinsert(lst,el):
    '''
    objective : to insert a element in the list in sorted order
    input parameter:
        lst-list in which we have to insert
        el-element
    output:
        same list modified
        '''
    '''if ind<0:
        return 
    elif lst[ind]<el:
        temp=lst[ind]
        lst[ind]=el
        lst.append(temp)
        if ind%2!=0:
            ind1=(ind-1)/2
        else:
            ind1=(ind-2)/2
        print(ind1)
        print(lst)
        heapinsert(lst[:ind],lst[ind],int(ind1))
    else:
        return'''
    lst.append(el)
    lst=heap(lst)
    return lst
def heap(lst):
    '''
    objective: to convert the list into a heap
    input parameter:
    lst=list to be converted to heap
    '''
    
    lst1=[]
    ind=0
    lst1.append(lst[ind])
    ind+=1
    while True:
        if len(lst1)==len(lst):
            break
        temp=lst[ind]
        lst1.append(temp)
        ind2=ind
        while True:
            if ind%2!=0:
                ind1=int((ind-1)/2)
            else:
                ind1=int((ind-2)/2)
            if lst1[ind]>lst1[ind1] and ind1>=0:
                lst1[ind],lst1[ind1]=lst1[ind1],lst1[ind]
                ind=ind1
            else:
                break
        ind=ind2+1
    lst=lst1
    del lst1
    return lst
def heapdel(lst):
    '''
    objective :to return the heap list in a sorted order
    input parameter:
    lst=list given
    output:
    a sorted list'''
    lst1=lst
    while True:
        if lst==[] or len(lst)==1:
            print(lst[0])
            break
        else:
            print(lst[0])
            lst[0]=lst[len(lst)-1]
            del lst[len(lst)-1]
            lst=heap(lst)
    lst=lst1         
            
        
