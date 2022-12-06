import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class hw4 {

    public static void main(String[] args) throws FileNotFoundException {
        // Scanner in = new Scanner(System.in);
        // double Total = 0;
        // System.out.print("Enter a file name ");
        // //String Lamp = in.next();
        // File Desk = new File("test.txt");
        // Scanner Pencil = new Scanner(Desk);
        // while (Pencil.hasNextInt())
        // {
        // Total += Math.pow(Pencil.nextInt(), Pencil.nextInt());
        // }
        // System.out.printf("%.0f\n", Total);
        // Pencil.close();
        // Scanner in = new Scanner(System.in);
        // int total = 0;
        // PrintWriter out = new PrintWriter("Rainbow.txt");

        // System.out.println("Type 5 colors");
        // for (int i = 0 ; i<5 ;i++)
        // {
        // out.println(in.next());
        // }
        // out.close();
        // File handle = new File("Rainbow.txt");
        // Scanner inFile = new Scanner(handle);
        // ArrayList<String> rainbow = new ArrayList<String>();
        // while(inFile.hasNext())
        // {
        // rainbow.add(inFile.next());
        // for (int i = 0; i < rainbow.size(); i += 2)
        // total = (int) rainbow.get(i).charAt(i);
        // }System.out.println(total);

        // ArrayList<String> Muffin = new ArrayList<String>();
        // String Bagel = "";
        // String Croissant = "";
        // for (int i = 0;i <= 9; i++)
        // {
        // Bagel = String.valueOf((char) (i+48));
        // Muffin.add(i, Bagel);
        // }
        // Croissant = Muffin + "";

        // String Donut[] = Croissant.split("[37]");
        // System.out.println(Donut[0]);

        // Scanner Fly = new Scanner (System.in);
        // int Butter = 56;
        // System.out.println("Enter a value ");
        // try{
        // Butter = Fly.nextInt ();
        // }
        // catch (Exception Moth)
        // {
        // Butter = -56;
        // }
        //System.out.println (Butter);
        Scanner in = new Scanner(System.in);
        int total = 0;
        PrintWriter out = new PrintWriter("Rainbow.txt");
        System.out.println("Type 5 colors");
        for (int i = 0; i < 5; i++)
        {
        out.println(in.next());
        }
        out.close();
        File handle = new File("Rainbow.txt");
        Scanner inFile = new Scanner(handle);

        ArrayList<String> rainbow = new ArrayList<String>();
        while(inFile.hasNext())
        {
        rainbow.add(inFile.next());
        }for(int i = 0;i<rainbow.size();i+=2)
        {
        total += (int) rainbow.get(i).charAt(i);
        }
        System.out.println(total);

        // String Apple[] = { "Pie", "Tart", "Cake" };
        // String Car[] = Apple;
        // Car[2] = "Honda";
        // System.out.println(Apple[2] + Car[2]);

    }
}
