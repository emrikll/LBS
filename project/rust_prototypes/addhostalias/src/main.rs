use std::env;
use std::io::Write;
use std::fs::OpenOptions;

const HOST_FILE: &str = "/etc/hosts";

#[allow(warnings)]
fn add_alias(ip: &str, host: &str,  alias: &str) -> std::io::Result<()> {
    let formatbuffer: String;

    formatbuffer = format!("{} {} {}", ip, host, alias);

    let mut file = OpenOptions::new()
        .write(true)
        .append(true)
        .open(HOST_FILE)?;

    writeln!(file, "{}", formatbuffer)?;
    Ok(())
}

#[allow(warnings)]
fn main() -> std::io::Result<()> {
    let args: Vec<String> = env::args().collect();
    if args.len() != 4 {
        println!("Usage: {} ipaddress hostname alias", args[0]);
        return Ok(());
    }

    for n in range (1..101) {
        add_alias(&args[1], &args[2], &args[3])?;
    }
    Ok(())
}
