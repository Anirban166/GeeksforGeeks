import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    static StringBuilder sb = new StringBuilder();
    static  List<List<Integer>> edge = new ArrayList<List<Integer>>();
    static Scanner sc = new Scanner(System.in);
    static int time = 0;
	public static void main (String[] args) {
		//code
		int a = sc.nextInt();
		while(a-- > 0) solve();
	}
	public static void solve(){
	    sb = new StringBuilder();
	    edge.clear();
	    time = 0;
	    int n = sc.nextInt();
	    int m = sc.nextInt();
	    for(int i = 0; i < n; i++){
	        edge.add(new ArrayList<Integer>());
	    }
	    for(int i = 0; i < m; i++){
	        int u = sc.nextInt(), v = sc.nextInt();
	        if(u == v) continue;
	        edge.get(u).add(v);
	    }
	    int[] disc = new int[n];
	    int[] low = new int[n];
	    Arrays.fill(disc, -1); Arrays.fill(low, -1);
	    boolean[] stackMem = new boolean[n];
	    Arrays.fill(stackMem, false);
	    Stack<Integer> st = new Stack<Integer>();
	    for(int i = 0; i < n; i++){
	        if(disc[i] == -1){
	            strongCompo(i, disc, low, st, stackMem);
	        }
	    }
	    System.out.println(sb);
	}
	static void strongCompo(int u, int disc[], int low[], Stack<Integer> st, boolean[] stackMem){
	   // time = 0 ;
	    disc[u] = low[u]= ++time;
	    st.push(u);
	    stackMem[u] = true;
	    for(int i = 0; i < edge.get(u).size(); i++){
	        int v = edge.get(u).get(i);
	        if(disc[v] == -1){
	            strongCompo(v, disc, low, st, stackMem);
	            low[u] = Math.min(low[u], low[v]);
	        }else if(stackMem[v] == true){
	            low[u] = Math.min(disc[v], low[u]);
	        }
	    }
	    int w = 0;
	    List<Integer> ll = new ArrayList<Integer>();
	    if(low[u] == disc[u]){
	        while(st.peek() != u){
	           w = st.pop();
	           ll.add(w);
	           stackMem[w] = false;
	        }
	        w = st.pop();
	        ll.add(w);
	        stackMem[w] = false;
	        for(int i = 0; i < ll.size(); i++){
	            if(sb.length() > 0 && i != 0) sb.append(" ");
	            sb.append(ll.get(i));
	        }
	        sb.append(",");
	    }
	}
}
