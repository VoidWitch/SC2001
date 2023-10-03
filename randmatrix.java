package proj2;

import java.util.ArrayList;

import org.w3c.dom.Node;

public class randmatrix {
    /* - Generates a random 2D n element square matrix - connected graph with random weights
       - Weights obtained randomly within range determined by min max values: adjusted with inputs */

    public static int[][] randArr(int n, int min, int max) { // n elements, max and min weight range
        int[][] arr = new int[n][n];
        do {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) {
                        arr[i][j] = 0; // diagonal entries 0
                        continue;
                    }
                    int weight = (int)(Math.random() * (double)(max-min+1) + (double) min);   
                    weight = weight < 0 ? 0 : weight;   //if weight<0, assume unconnected
                    arr[i][j] = weight;
                }
            }
        } while (!Connected(arr));   //if random arr generated is not connected
        return arr;
    }

    public static boolean Connected(int[][] arr) {
        /* Row connectedness check on 2D matrix */
        boolean[] visited = new boolean[arr.length];
        for (int i=0; i<visited.length; i++) {
            visited[i] = false;     //initialize as unvisited for each vertex
        }
        isConnectedFromFirstVertex(arr, 0, visited);
        for (boolean i : visited) {     //if not visited implies unconnected
            if (!i) {
                return false;
            }
        }
        return true;
    }

    public static void isConnectedFromFirstVertex(int[][] arr, int cur, boolean[] visited) {
        visited[cur] = true;    //mark first node visited
        for (int i=0; i<arr[cur].length; i++) {     //iterating thru first matrix row
            // Checked if is connected
            if (arr[cur][i] > 0 && !visited[i]) {   //if weighted & unvisited, explore vertex, mark as visited
                isConnectedFromFirstVertex(arr, i, visited);
            }
        }
    }

    public static void printMatrix(int[][] arr) {       //prints weighted directed edges
        for (int[] a : arr) {
            for (int b : a) {
                System.out.printf("%2d ", b);
            }
            System.out.printf("\n");
        }
    }

    public static void print2DGraph(ArrayList<ArrayList<Node>> graph) {;
        for (int i=0; i<graph.size(); i++) {
            System.out.printf("%2d", i);
            for (Node j : graph.get(i)) {
                System.out.printf(" -> %2d", j.getFirstChild());
            }
            System.out.print("\n");
        }
        System.out.print("\n");
    }

    public static void to2DGraph(int[][] arr, ArrayList<ArrayList<Node>> graph) {
        for (int i = 0; i < arr.length; i++) {
            graph.add(new ArrayList<>());
            for (int j = 0; j < arr.length; j++) {
                if (arr[i][j] != 0) {
                    graph.get(i).add(new Node(j, arr[i][j]));
                }
            }
        }
    }

    public static int countEdges(int[][] arr) {
        int counter = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++) {
                if (arr[i][j] > 0)
                    counter++;
            }
        }
        return counter;
    }

    public static void main(String[] args) {
        int[][] arr = randArr(5, -10, 10);

        for (int[] a : arr) {
            for (int b : a) {
                System.out.printf("%2d ", b);
            }
            System.out.printf("\n");
        }
        System.out.println(Connected(arr));
    }
}