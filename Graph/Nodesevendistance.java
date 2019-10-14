import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;

class NodesAtEvenDistance 
{
    
    public static void main(String[] args) {
         Scanner s = new Scanner(System.in);
            //        FastReader s = new FastReader();
            int totalCases = s.nextInt();
            for (int i = 0; i < totalCases; i++) {
                int totalNodes=s.nextInt();
                Graph2 g=new Graph2(totalNodes);
                for(int j=0;j<totalNodes-1;j++){
                    int x=s.nextInt()-1;
                    int y=s.nextInt()-1;
                    g.addEdge(x, y);
                    g.addEdge(y, x);
                }
                
                    g.DFS(0);
                
                System.out.println(g.evenCount*(g.evenCount-1)/2+g.oddCount*(g.oddCount-1)/2);
            }
    }
}

class Graph2 {
     int evenCount=1;
     int oddCount=0;
    static int tempStartingNode;
    int totalVertics;
    Object adj[];
    Graph2(int NoOfVertices){
        totalVertics=NoOfVertices;
        adj=new Object[NoOfVertices];
        for(int i=0;i<NoOfVertices;i++){
            adj[i]=new LinkedList<Integer>();
            
        }
    }
    void addEdge(int u,int v){
            ((LinkedList<Integer>)adj[u]).add(v);
    }   
    void DFS(int StartingNode){
        tempStartingNode=StartingNode;
        boolean visited[]=new boolean[totalVertics];
    DFSutil(StartingNode,visited,1);        
        
        
    }
    
    void DFSutil(int Vertices,boolean visited[],int count){
     //  if(!visited[Vertices]){
         //  System.out.println(Vertices);
           visited[Vertices]=true;
           LinkedList<Integer> ll=(LinkedList<Integer>)adj[Vertices];
           ListIterator<Integer> ltr=ll.listIterator();
           while(ltr.hasNext()){
               int nextVertics=ltr.next();
               if(!visited[nextVertics]){
                   if(count%2==0){
                   evenCount++;
                   }
                   else{
                       oddCount++;
                   }
                   DFSutil(nextVertics, visited,count+1);
               }
           }
    }

}

