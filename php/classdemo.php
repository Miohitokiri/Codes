<?php
echo "<br / >";
$d1 = new Demo;
echo $d1->do_something()."<br / >";
$d2 = new Demo;
$d2->a = 44;
$d2->b = 55;
echo $d2->do_something()."<br / >";
echo "<br / >";
 
class Demo {
    public $a = 22;
    public $b = 33;
     
    function do_something() {
        return $this->a + $this->b;
    }
}
?>
