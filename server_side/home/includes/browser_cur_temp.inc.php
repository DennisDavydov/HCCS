


<?php
//   Get currenttemp of sensor by id from database and return it to browser

    include_once 'dbh.inc.php'; 
	$id =(int) $_GET['id'];
	$temp = $_GET['temp'];

	
	$sql = "SELECT current_temp FROM  sensor_data
	 WHERE id= $id;";
	 $result = mysqli_query($conn, $sql);
	if ($result) {
		$temperatures = mysqli_fetch_row($result);

		echo "" . $temperatures[$id-1] . "\n";
	} else{
		echo "$temp";
	}