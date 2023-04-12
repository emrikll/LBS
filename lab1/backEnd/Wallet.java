package backEnd;
import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.file.*;
import java.nio.channels.*;

public class Wallet {
    /**
     * The RandomAccessFile of the wallet file
     */  
    private RandomAccessFile file;

    /**
     * Creates a Wallet object
     *
     * A Wallet object interfaces with the wallet RandomAccessFile
     */
    public Wallet () throws Exception {
	this.file = new RandomAccessFile(new File("backEnd/wallet.txt"), "rw");
    File f = new File("./backEnd/wallet.lock");
        if(!f.exists()) {
            f.createNewFile();
        }
    }

    /**
     * Gets the wallet balance. 
     *
     * @return                   The content of the wallet file as an integer
     */
    public int getBalance() throws IOException {
	this.file.seek(0);
	return Integer.parseInt(this.file.readLine());
    }

    /**
     * Sets a new balance in the wallet
     *
     * @param  newBalance          new balance to write in the wallet
     */
    public void setBalance(int newBalance) throws Exception {
	this.file.setLength(0);
	String str = Integer.valueOf(newBalance).toString()+'\n'; 
	this.file.writeBytes(str); 
    }

    /**
     * Sets a new balance in the wallet
     *
     * @param  valuetoWithdraw          The value to withdraw from the wallet
     */
    public boolean safeWithdraw(int valueToWithdraw) throws Exception {

        RandomAccessFile file = new RandomAccessFile("./backEnd/wallet.lock", "rw"); 
        FileChannel channel = file.getChannel();
        FileLock lock = channel.lock();

        int balance = getBalance();
        if(balance >= valueToWithdraw){
            setBalance(balance - valueToWithdraw);
            lock.close();
            return true;
        }
        lock.close();
        return false;
    }

    /**
     * Closes the RandomAccessFile in this.file
     */
    public void close() throws Exception {
	this.file.close();
    }
}
