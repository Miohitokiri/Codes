import Cocoa

func gcd ( a:Int, b: Int ) -> Int{
    var a = a, b = b
    
    while a % b != 0 && b % a != 0{
        if a > b {
            a %= b
        }
        else{
            b %= a
        }
    }
    
    if a > b{
        return b
    }
    else{
        return a
    }
}


let first = 1146, secound = 4569

print ( "\(gcd(a: first, b: secound))")