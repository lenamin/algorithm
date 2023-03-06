import Foundation

var graph: [Int: [Int]] = [:]
var result = ""


var visitedNodes: [Int] = []
var needVisitNodes: [Int] = []

// input
var input = readLine()!.split(separator: " ").map { Int(String($0))! }
let (n, m, v) = (input[0], input[1], input[2])

var isVisited: [Bool] = Array(repeating: false, count: n + 1)

// create graph
for i in 1...n {
    graph.updateValue([], forKey: i)
}

for _ in 0..<m {
    let nodes = readLine()!.split(separator: " ").map { Int($0)! } // 일단 첫 줄 1,2 가 담기겠지 배열로
    graph[nodes[0]]?.append(nodes[1])
    graph[nodes[1]]?.append(nodes[0])
    
}
print(dfs(v))
print(bfs(v))


func dfs(_ index: Int) -> String {
    
    isVisited[index] = true // 첫번째 간선 true로 방문처리
    result += "\(index) "
    
    for linkedNode in graph[index]! {
        if !isVisited[linkedNode] {
            dfs(linkedNode)
        }
    }
    return result
}

func bfs(_ index: Int) -> String {
    
    needVisitNodes.append(index) // 이번에 방문해야 하는 노드를 여기다가 저장
    
    while !needVisitNodes.isEmpty {
        let node = needVisitNodes.removeFirst() //
        if visitedNodes.contains(node) {
            continue
        }
        visitedNodes.append(node)
        needVisitNodes.append(contentsOf: graph[node] ?? [])
    }
    return visitedNodes.map { String($0) }.joined(separator: " ")
    
}
