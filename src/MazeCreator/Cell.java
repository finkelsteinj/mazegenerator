package MazeCreator;

public class Cell {
    private boolean visited;
    private int nodes;
    private String block[][];

    public Cell(boolean v, int n) {
        visited = v;
        nodes = n;
        block = new String[3][3]; // holds inner part of cell, walls will be part of the entire maze array
    }

    public boolean isVisited() { return visited; }
    public void setVisited(boolean v) { visited = v; }
    public int getNodes() { return nodes; }
    public void setNumberOfNodes(int n) { nodes = n; }

    public String openNorth() { return ""; }
    public String openEast() { return ""; }
    public String openSouth() { return ""; }
    public String openWest() { return ""; }

    public String toString() {
        return "";
    }
}