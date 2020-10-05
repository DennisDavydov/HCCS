<?php
	include_once 'dbh.inc.php';
	
	$tempI = $_POST['tempI'];

	$sql = "UPDATE sensor_data SET  request_temp = '$tempI' WHERE id=1;";

	mysqli_query($conn, $sql);

	header("Location: ../");


