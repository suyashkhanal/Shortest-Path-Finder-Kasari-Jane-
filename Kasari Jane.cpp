#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

class Graph {
public:
    unordered_map<string, vector<pair<string, float>>> adjList;

    void addEdge(string u, string v, float weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    void dijkstra(string src, string dest) {
        unordered_map<string, float> dist;
        unordered_map<string, string> parent;
        priority_queue<pair<float, string>, vector<pair<float, string>>, greater<>> pq;
        
        for (auto &node : adjList) dist[node.first] = numeric_limits<float>::max();
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [currDist, u] = pq.top(); pq.pop();
            if (currDist > dist[u]) continue;
            
            for (auto &[v, weight] : adjList[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        
        printPath(src, dest, dist, parent);
    }

    void printPath(string src, string dest, unordered_map<string, float> &dist, unordered_map<string, string> &parent) {
        if (dist[dest] == numeric_limits<float>::max()) {
            cout << "No path found from " << src << " to " << dest << endl;
            return;
        }

        stack<string> path;
        for (string node = dest; node != src; node = parent[node]) path.push(node);
        path.push(src);

        cout << "\nShortest path from " << src << " to " << dest << ":\n";
        while (!path.empty()) {
            cout << path.top(); 
			path.pop();
            if (!path.empty()) cout << "\n => ";
        }
        cout << "\n\n\t\t\t\t  Total Distance: " << dist[dest] << " km approx"<<endl;
        cout << "\t\t\t\t<===============================>\n\n"<<endl;
        cout<<"\t-----------------------------------------------------------------------"<<endl;
        cout<<"\t| Estimated Time by Walking                  |   "<<dist[dest]/3<<" hrs approx   |"<<endl;
        cout<<"\t-----------------------------------------------------------------------"<<endl;
    	cout<<"\t| Estimated Time by Driving (30km/sec)       |   "<<dist[dest]/30*60<<" min approx      |"<<endl;
    	cout<<"\t-----------------------------------------------------------------------"<<endl;
    }
};

int main() {
    Graph g;
    g.addEdge("Thamel", "Basantapur", 2);
    g.addEdge("RNAC", "Tripureshwor", 2.4);
    g.addEdge("Tripureshwor", "Patan", 5.4);
    g.addEdge("Patan", "Koteshwor", 4);
    g.addEdge("Koteshwor", "Thimi", 3.5);
    g.addEdge("Thimi", "Bhaktapur Durbar Square", 4);


    g.addEdge("Swoyambhu", "Thamel", 3);
    g.addEdge("Chabahil", "Bouddhanath", 3.2);




    g.addEdge("Kalanki", "Balkhu", 1.9);
    g.addEdge("Balkhu", "Ekantakuna", 3.8);
    g.addEdge("Ekantakuna", "Satdobato", 3.2);
    g.addEdge("Satdobato", "Gwarko", 2.2);
    g.addEdge("Gwarko", "Balkumari", 1.1);
    g.addEdge("Balkumari", "Koteshwor", 1.4);
    g.addEdge("Koteshwor", "Tinkune", 0.6);
    g.addEdge("Tinkune", "Sinamangal", 1.6);
    g.addEdge("Sinamangal", "Gaushala", 1.6);
    g.addEdge("Gaushala", "Chabahil", 1.1);
    g.addEdge("Chabahil", "Sukedhara", 1.3);
    g.addEdge("Sukedhara", "Maharajgunj", 1.7);
    g.addEdge("Maharajgunj", "Basundhara", 1.4);
    g.addEdge("Basundhara", "Samakhushi", 0.8);
    g.addEdge("Samakhushi", "Gongabu", 0.45);
    g.addEdge("Gongabu", "Naya Buspark", 0.55);
    g.addEdge("Naya Buspark", "Machhapokhari", 0.4);
    g.addEdge("Machhapokhari", "Balaju", 0.9);
    g.addEdge("Balaju", "Swoyambhu", 2.4);
    g.addEdge("Swoyambhu", "Sitapaila", 1.1);
    g.addEdge("Sitapaila", "Kalanki", 1.7);
        
    g.addEdge("Balaju", "Naya Bazar", 1.1);
    g.addEdge("Naya Bazar", "Sorakhutte", 0.07);
    g.addEdge("Sorakhutte", "Lainchaur", 0.6);
    g.addEdge("Lainchaur", "Lazimpat", 0.3);
    g.addEdge("Lazimpat", "Maharajgunj", 2.4);


	g.addEdge("Kalanki", "Kalimati", 2.1);
    g.addEdge("Kalimati", "Tripureshwor", 1.7);
    g.addEdge("Tripureshwor", "Maitighar", 1.9);
    g.addEdge("Maitighar", "Babar Mahal", 0.7);
    g.addEdge("Babar Mahal", "Naya Baneshwor", 0.8);
    g.addEdge("Naya Baneshwor", "Tinkune", 1.2);
    g.addEdge("Naya Buspark", "Naya Bazar", 1.2);


    
    g.addEdge("Naya Baneshwor", "Purano Baneshwor", 1.5);
    g.addEdge("Purano Baneshwor", "Gaushala", 2.7);
    g.addEdge("Purano Baneshwor", "Sinamangal", 1.5);
    


    g.addEdge("Naya Baneshwor", "Bijuli Bazar", 3.1);
    g.addEdge("Bijuli Bazar", "Anam nagar", 0.85);
    g.addEdge("Anam nagar", "New Plaza", 1.1);
    g.addEdge("New Plaza", "Singha Durbar", 0.9);


    g.addEdge("New Plaza", "Putalisadak", 0.5);
    g.addEdge("Putalisadak", "Kamaladi", 0.3);
    g.addEdge("Kamaladi", "Durbar Marg", 0.6);
    g.addEdge("Durbar Marg", "Lainchaur", 0.6);



    g.addEdge("Kamaladi", "Hattisar", 0.4);
    g.addEdge("Hattisar", "Narayanchaur", 0.6);
    g.addEdge("Narayanchaur", "Tangal", 1.1);
    g.addEdge("Tangal", "Baluwatar", 0.9);
    g.addEdge("Baluwatar", "Maharajgunj", 1.9);



    g.addEdge("Maharajgunj", "Budhanilkantha", 5);
    g.addEdge("Gongabu", "Ganeshthan", 0.4);
    g.addEdge("Ganeshthan", "Manamaiju", 1);
    g.addEdge("Manamaiju", "Naya Buspark", 1.5);
    g.addEdge("Manamaiju", "Nepaltar", 2.6);
    g.addEdge("Nepaltar", "Machhapokhari", 1.8);

    g.addEdge("Samakhusi", "Ranibari", 2.2);
    g.addEdge("Ranibari", "Lazimpat", 1.4);


    g.addEdge("Gongabu", "Rehdon College", 1);
    g.addEdge("Rehdon College", "Sarkaridhara", 0.3);
    g.addEdge("Sarkaridhara", "Kapurdhara",0.2);
    g.addEdge("Kapurdhara", "Thamel", 0.5);


    g.addEdge("Jamal", "Ghantaghar", 0.5);
    g.addEdge("Ghantaghar", "Ratnapark", 0.2);
    g.addEdge("Ratnapark", "Purano Buspark", 0.3);
    g.addEdge("Purano Buspark", "Bhadrakali", 0.4);
    g.addEdge("Bhadrakali", "Sahid Gate", 0.1);
    g.addEdge("Sahid Gate", "Sundhara", 0.1);
    g.addEdge("Sundhara", "RNAC", 0.3);
    g.addEdge("Jamal", "Lainchaur", 1.1);
    g.addEdge("Jamal", "Durbar Marg", 0.5);


    
    

    g.addEdge("Ghantaghar", "Kamaladi", 0.5);
    g.addEdge("Ratna Park", "Baghbazar", 0.35);
    g.addEdge("Baghbazar", "Putalisadak", 0.25);
    g.addEdge("Putalisadak", "Dillibazar", 0.4);
    g.addEdge("Dillibazar", "Purano Baneshwor", 1.3);




    g.addEdge("Ekantakuna", "Jawalakhel", 0.8);
    g.addEdge("Jawalakhel", "Pulchowk", 1);
    g.addEdge("Pulchowk", "Thapathali", 1.1);
    g.addEdge("Thapathali", "Maitighar", 0.5);
    g.addEdge("Thapathali", "Tripureshwor", 0.5);
    g.addEdge("Tripureshwor", "Teku", 1);
    g.addEdge("Dallu", "Sorakhutte", 1);
    g.addEdge("Sorakhutte", "Chhetrapati", 0.8);
    g.addEdge("Chhetrapati", "Dallu", 0.8);
    g.addEdge("Chhetrapati", "Basantapur", 0.7);
    g.addEdge("RNAC", "Ratnapark", 0.4); 
    g.addEdge("Balkhu", "Kupondole", 2.2);
    g.addEdge("Pulchowk", "Kupondole", 0.8);
    g.addEdge("Thapathali", "Kupondole", 0.3);
    g.addEdge("Jwagal", "Kupondole", 1);
    g.addEdge("Bhadrakali", "Singha Durbar", 0.5);
    g.addEdge("Singha Durbar", "Maitighar", 0.4);
    g.addEdge("Lainchaur", "Narayanhiti", 0.5);
    g.addEdge("Narayanhiti", "Nagpokhari", 0.6);
    g.addEdge("Nagpokhari", "Uttar Dhoka", 0.5);
    g.addEdge("Uttar Dhoka", "Lazimpat", 0.8);

    g.addEdge("Sorakhutte", "Newa ghasa", 0.1);

    string src, dest;
    cout<<"\t\t\t\t\t-----------------------"<<endl;
    cout<<"\t\t\t\t\t|     Kasari Jane     |"<<endl;
    cout<<"\t\t\t\t\t-----------------------"<<endl;
    cout << "Enter source location: "<<endl; 
	cout<<"\t=> ";cin >> src;
    cout << "Enter destination location: "<<endl; 
	cout<<"\t=> ";cin >> dest;
    g.dijkstra(src, dest);
    return 0;
    
    
}
