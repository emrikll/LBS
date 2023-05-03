fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        println!("Usage: {} text", args[0]);
        return Ok(());
    }

    let formatbuffer: String;

    formatbuffer = format!("{}", args[1]);
    println!("You wrote: {}", formatbuffer);
    return Ok(());

}
