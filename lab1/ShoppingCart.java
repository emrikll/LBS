import backEnd.*;
import java.util.Scanner;

public class ShoppingCart {
    private static void print(Wallet wallet, Pocket pocket) throws Exception {
        System.out.println("Your current balance is: " + wallet.getBalance() + " credits.");
        System.out.println(Store.asString());
        System.out.println("Your current pocket is:\n" + pocket.getPocket());
    }

    private static String scan(Scanner scanner) throws Exception {
        System.out.print("What do you want to buy? (type quit to stop) ");
        return scanner.nextLine();
    }

    public static void main(String[] args) throws Exception {
        Wallet wallet = new Wallet();
        Pocket pocket = new Pocket();
        Scanner scanner = new Scanner(System.in);

        print(wallet, pocket);
        String product = scan(scanner);

        while(!product.equals("quit")) {
            /* TODO:
               - check if the amount of credits is enough, if not stop the execution.
               - otherwise, withdraw the price of the product from the wallet.
               - add the name of the product to the pocket file.
               - print the new balance.
            */
            Integer price = Store.getProductPrice(product);

            //Thread.sleep(5000);
            
            if(!wallet.safeWithdraw(price)){ 
                break;
            }
            
            pocket.addProduct(product);

            // Just to print everything again...
            print(wallet, pocket);
            product = scan(scanner);

            /*
            Integer price = Store.getProductPrice(product);
            int balance = wallet.getBalance();
            if(balance - price){
                break;
            }
            
            Thread.sleep(5000);
            wallet.setBalance(balance - price);
            
            pocket.addProduct(product);

            // Just to print everything again...
            print(wallet, pocket);
            product = scan(scanner);
            */
        }
    }
}

//två instanser, en köper en godis och den andra en bil
//båda hamnar på rad 52
//först den som köper bil exekverar rad 53, så blir wallet.txt 0
//sen kör den andra som köper godis och då sätts wallet.txt till 30000 - candie
//voila köpt bil och godis för pris av godis
//BOOM
