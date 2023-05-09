use std::io;

#[allow(warnings)]
fn main() {

    let important1 = "**IMPORTANT1**".to_string();

    let salt = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";

    let important2 = "**IMPORTANT2**".to_string();

    println!("Starting..");

    println!("user: ");
    let mut stdin = io::stdin();
    let input = &mut String::new();

    input.clear();
    stdin.read_line(input);

    let user = input.trim().to_string();
    if user.is_empty() {
        return;
    } 

    println!("password: ");
    input.clear();
    stdin.read_line(input); 

    let password = input.trim().to_string();  
    
    println!("Your password was {}", password);
}
