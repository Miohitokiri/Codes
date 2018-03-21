<?php 
    require_once('flag.php'); 
    $acct = $_POST['account']??null; 
    $pass = $_POST['password']??null; 
    if( isset($acct,$pass) ) 
    { 
        if( $acct === $pass ) 
            $ans = "are U 87?"; 
        elseif( sha1($acct) === sha1($pass) ) 
            $ans = $flag;          
    } 
?> 