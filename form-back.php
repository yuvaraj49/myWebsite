<?php
	$name=$_POST['uname'];
	$num=$_POST['unum'];

	$con=mysqli_connect("localhost","root","","myphp");
	if($con==true)
	{
		echo "DB connected <br>";
	}
	else
	{
		echo "Cannot establish connection <br>";
	}
	echo "<h1>$name</h1>";
	echo "<h2>$num</h2>";
	$q=mysqli_query($con,"INSERT INTO GitData VALUES('".$name."',".$num.");");
	if($q==true)
	{
		echo "Your response is taken <br>";
	}
	else
	{
		echo "Sorry <br>";
	}
	if(mysqli_close($con))
	{
		echo "DB connection terminated <br>";
	}
	else
	{
		echo "DB connection not closed properly <br>";
	}
	
?>