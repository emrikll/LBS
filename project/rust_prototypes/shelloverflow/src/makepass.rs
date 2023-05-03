use rpassword::read_password;
use std::io::Write;
use anyhow::Result;

fn is_salt(salt: String) {

}

pub fn makepass() -> Result<String> {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        println!("Usage: {} salt\n", args[0]);
        return;
    }

    print!("password: ");
    std::io::stdout().flush().unwrap();
    let password = read_password().unwrap();
    if password.len() == 1 {
        eprintln!("Please enter a real password next time.");
        return Err(());
    }

    print!("reenter password: ");
    std::io::stdout().flush().unwrap();
    let re_password = read_password().unwrap();

    if !password.eq(re_password) {
        eprintln!("The passwords did not match.");
        return Err(());
    }

    

}