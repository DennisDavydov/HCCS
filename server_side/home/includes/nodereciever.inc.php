<?php
	include_once 'dbh.inc.php';

	$id =(int) $_POST['id'];
	$temp = (int) $_POST['temp'];
	
	$sql = "UPDATE sensor_data SET  current_temp = '$temp' WHERE id= $id;";
	if (mysqli_query($conn, $sql)) {
		echo "OK";
	} else{
		echo "Nope";
	}
	