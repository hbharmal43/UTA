import java.util.ArrayList;

public class hw4 {
    public static void main(String[] args){
    //int Treat[] = {5,2,7,6,1,8,1,5,8,2,5,6,9}; 
    int Treat[] = {0,4,3,2,1};
    ArrayList<Double>Candy = new ArrayList<>();
    for (int Trick : Treat){
    Candy.add (Trick*1.1); 
    Candy.add (Trick/1.1); 
    Candy.remove (Candy.size () -1);}
    for (double Bag : Candy)
    {
    System.out.printf("%.1f\n", Bag);
    }
//     boolean Grape = false;
//     int Bunch;

//     if(Grape)
//         Bunch = 1;
//     else
//         Bunch = 0;
//     }
//     int Bunch = ("Grape")?1:0;
//int Treat[] = {0,4,3,2,1};
// for(int i =1 ; i< Treat.length ;i+=4 )
// System.out.print(Treat[i]);
// }
    }
}