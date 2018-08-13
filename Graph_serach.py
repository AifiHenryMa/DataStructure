graph = {
	"A": ["B", "C"],
	"B": ["A", "C", "D"],
	"C": ["A", "B", "C", "D"],
	"D": ["B", "C", "E", "F"],
	"E": ["C", "D"],
	"F": ["D"]
}

def BFS(graph, s):
	queue = []
	queue.append(s)
	seen = set()
	seen.add(s)
	parent = {s: None}
	while (len(queue) > 0):
		vertex = queue.pop(0)
		nodes = graph[vertex]
		for w in nodes:
			if w not in seen:
				queue.append(w)
				seen.add(w)
				parent[w] = vertex
		print(vertex)
	return parent

def DFS(graph, s):
	stack = []
	stack.append(s)
	seen = set()
	seen.add(s)
	while (len(stack) > 0):
		vertex = stack.pop()
		nodes = graph[vertex]
		for w in nodes:
			if w not in seen:
				stack.append(w)
				seen.add(w)
		print(vertex)

parent = BFS(graph, 'E')
for key in parent:
	print(key, parent[key])

v = 'B'
while v != None:
	print(v)
	v = parent[v]

