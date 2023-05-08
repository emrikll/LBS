use rpassword::read_password;
use std::io::Write;
use anyhow::Result;
use std::io;

#[allow(warnings)]
fn main() {

    let important1 = "**IMPORTANT1**".to_string();

    let salt = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";

    let important2 = "**IMPORTANT2**".to_string();

    println!("Starting..");

    while true {
        
        print!("user: ");
        let mut stdin = io::stdin();
        let input = &mut String::new();
    
        input.clear();
        stdin.read_line(input);

        let user = input.trim().to_string();
        if user.is_empty() {
            return;
        }        

        print!("password: ");
        std::io::stdout().flush().unwrap();
        let password = read_password().unwrap();
        
        println!("Your password was {}", password);
    }
        

    println!("Hello, world!");
}
