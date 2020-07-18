def solution(capacity1,capacity2,target):
    mx=max(capacity1,capacity2)
    mn=min(capacity1,capacity2)
    bucket1=bucket2=0
    while (target>mx):
        target-=mx

    while True:
        if bucket1==target or bucket2==target:
            break
        if(bucket2>=mx):
            bucket2=0

        bucket1+=mn
        currcapacity=mx-bucket2
        if currcapacity>=bucket1:
            bucket2+=mn
            bucket1=0
        else:
            bucket1-=currcapacity
            bucket2=bucket1

        print(bucket1,bucket2)
        bucket1=0
