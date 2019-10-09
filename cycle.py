u={1,2,3,4,5,6,7,8,9}
n=int(input("Enter the no of edges:"))
arr = [set([]) for i in range(20)]
k=0
cycle=0
edges=set([tuple((int(input("Enter vertices of edge:")))for j in range(2)) for i in range(n)])
print(edges)
for i in list(edges):
	flag = 0	
	for j in i:		
		if j in u:#check if it is in universal
			temp=u.remove(j)
			arr[k].add(temp)
		else:
			for l in arr:#check if it is in newly made sets
				if j in l:
					flag+=1
					#arr[k].add=l.remove(j)
					arr[k]=union(l,arr[k])
					
	k+=1
	if flag==2:
		cycle+=1

print("Cycle:" + str(cycle))
