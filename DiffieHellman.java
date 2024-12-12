import java.util.*;

class DiffieHellman{

    public static double keyExchange(double base, double exponent, int c){
        return Math.pow(base,exponent)%c;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter 1st large prime number:");
        int n = sc.nextInt();
        System.out.println("Enter 2nd large prime number:");
        int g = sc.nextInt();
        
        
        System.out.println("Enter random number :");
        double x = sc.nextInt();
        System.out.println("Enter random number:");
        double y = sc.nextInt();

        double A = keyExchange(g,x,n); 
        double B = keyExchange(g,y,n); 
        
        double key1 = keyExchange(B,x,n); 
        double key2 = keyExchange(A,y,n);
        
        System.out.println("Key 1:"+key1);
        System.out.println("Key 2 :"+key2);
        sc.close();
        
    }
}