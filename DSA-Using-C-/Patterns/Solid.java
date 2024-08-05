import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main"
class Main {
    public static void main(String[] args) {
       int n = 5;
        //row	
        for (int i = 0; i<n; i++){
            //col
            for(int j=0; j<n;j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
