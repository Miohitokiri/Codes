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
 
/* 《程式語言教學誌》的範例程式
    http://pydoing.blogspot.com/
    檔名：classdemo.php
    功能：示範 PHP 程式 
    作者：張凱慶
    時間：西元 2012 年 11 月 */
?>
