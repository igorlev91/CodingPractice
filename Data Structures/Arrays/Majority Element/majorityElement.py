nums = [3, 3, 4, 2, 4, 4, 2, 4, 4]
mydict = {}
for i in nums:
    if i in mydict.keys():
        mydict[i]=mydict[i]+1
        if mydict[i]>=(len(nums)+1)/2:
            print "Majority Element is: ", i
            break
    else:
        mydict[i]=1
