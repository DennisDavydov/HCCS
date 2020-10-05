<?php
	include_once 'includes/dbh.inc.php'
?>
<head>
	<title>
		
	</title>
<link rel="stylesheet" type="text/css" href="includes/style.css">
</head>
<body>
<?php
	$sql = "SELECT request_temp FROM sensor_data";
	$result = mysqli_query($conn, $sql);
	$resultCheck = mysqli_num_rows($result);
	if ($resultCheck > 0) {
		$temperatures = mysqli_fetch_row($result);
		}

?>

</body>


<form action="includes/submit_temps.inc.php" method="post">
	Heater I: <input type="number" name="tempI" min = "0" max="100" step="0.5" value = <?php echo $temperatures[0]; ?>>
	<br>
	<button type="submit" name="submit">Set</button>
</form>


	