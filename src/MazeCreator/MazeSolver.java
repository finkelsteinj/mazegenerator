package MazeCreator;

import MazeCreator.Maze;

import java.util.Scanner;

public class MazeSolver {

    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the odd number width of the maze: ");
        int size = input.nextInt();

        Maze maze = new Maze(size);
        System.out.print(size);
    }
}